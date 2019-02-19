// VirtualServerView.cpp : implementation of the CVirtualServerView class
//

#include "stdafx.h"
#include "VirtualServer.h"

#include "VirtualServerDoc.h"
#include "VirtualServerView.h"

#include <afxcview.h>
#include <winsock2.h>
#include "Define.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

SOCKET sListen;
SOCKET sAccept;
SOCKADDR_IN saddr;
SOCKADDR_IN caddr;
int nAddressSize = sizeof(SOCKADDR);
char szMessage[MSGSIZE];
char szLog[1024];
char szMsg[MSGSIZE];

void GetTime(char* szString)
{
	time_t tt = time(NULL);
	tm *t;
	t = ::localtime(&tt);

	sprintf(szString,"%d/%02d/%02d %02d:%02d:%02d", 
		t->tm_year + 1900,
		t->tm_mon + 1,
		t->tm_mday,
		t->tm_hour,
		t->tm_min,
		t->tm_sec);
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerView

IMPLEMENT_DYNCREATE(CVirtualServerView, CFormView)

BEGIN_MESSAGE_MAP(CVirtualServerView, CFormView)
	//{{AFX_MSG_MAP(CVirtualServerView)
	ON_BN_CLICKED(IDC_BTN_SEND, OnBtnSend)
	ON_MESSAGE(WM_SOCKET,OnSocket)
	ON_COMMAND(IDC_SRV_START, OnSrvStart)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerView construction/destruction

CVirtualServerView::CVirtualServerView()
	: CFormView(CVirtualServerView::IDD)
{
	//{{AFX_DATA_INIT(CVirtualServerView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CVirtualServerView::~CVirtualServerView()
{
}

void CVirtualServerView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVirtualServerView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CVirtualServerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CVirtualServerView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CListView* clv = (CListView*)this->GetDlgItem(IDC_LIST);
	CListCtrl* clc = &(clv->GetListCtrl());


	RECT rect;
	clv->GetClientRect(&rect);

	DWORD dwWidth = rect.right - rect.left;

	clc->InsertColumn(0,"rownum",LVCFMT_LEFT,0);
	clc->InsertColumn(1,"datetime",LVCFMT_LEFT,150);
	clc->InsertColumn(2,"recv",LVCFMT_LEFT,(dwWidth-150)/4*3);
	clc->InsertColumn(3,"send",LVCFMT_LEFT,(dwWidth-150)/4);

	
	

}

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerView printing

BOOL CVirtualServerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVirtualServerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVirtualServerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVirtualServerView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerView diagnostics

#ifdef _DEBUG
void CVirtualServerView::AssertValid() const
{
	CFormView::AssertValid();
}

void CVirtualServerView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CVirtualServerDoc* CVirtualServerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVirtualServerDoc)));
	return (CVirtualServerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerView message handlers

void CVirtualServerView::OnBtnSend() 
{
	// TODO: Add your control notification handler code here
	CWnd* cWnd = this->GetDlgItem(IDC_INPUT);
	CString cs;
	cWnd->GetWindowText(cs);
	if(cs.IsEmpty())
	{
		MessageBox("input is empty.");
		return;
	}


	strcpy(szMsg,cs.GetBuffer(cs.GetLength()));

	//char szMsg[1024] = "hello,this is comes from client.";

	send(sAccept,szMsg,sizeof(szMsg),0);
	InsertLog(szMsg,LOGSEND);

	cWnd->SetWindowText(NULL);

}

void CVirtualServerView::OnSrvStart() 
{
	// TODO: Add your command handler code here
	WSADATA wsd;
	if(WSAStartup(MAKEWORD(2,2),&wsd) != 0)
	{
		return;
	}
	sListen = socket(AF_INET,SOCK_STREAM,0);

	int nPort = 7000;

	//SOCKADDR_IN addr;
	ZeroMemory(&saddr,sizeof(SOCKADDR_IN));
	//saddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(nPort);

	if(bind(sListen,(const struct sockaddr FAR*)&saddr,sizeof(SOCKADDR_IN)))
	{
		
		int eCode = WSAGetLastError();
		char sztmp[100];
		sprintf(sztmp,"bind error,error code is %d",eCode);
		MessageBox(sztmp);
		return;
	}

	if(listen(sListen,5))
	{
		MessageBox("listen error.");
		return;
	}

	WSAAsyncSelect(sListen,this->m_hWnd,WM_SOCKET,FD_ACCEPT);

	char sztmp[20] = "service has startup";

	InsertLog(sztmp,LOGRECV);
}

LRESULT CVirtualServerView::OnSocket(WPARAM wParam,LPARAM lParam)
{
	
	switch(WSAGETSELECTEVENT(lParam))
	{
	case FD_CONNECT:
		strcpy(szLog, "client try to connect");
		InsertLog(szLog,LOGRECV);
		break;
	case FD_ACCEPT:
		strcpy(szLog,"have accept client connect");
		InsertLog(szLog,LOGRECV);
		sAccept = accept(sListen,(SOCKADDR*)&caddr,&nAddressSize);
		WSAAsyncSelect(sAccept,this->m_hWnd,WM_SOCKET,FD_CONNECT | FD_READ | FD_CLOSE);
		break;
	case FD_READ:
		ZeroMemory(&szMessage,MSGSIZE);
		recv(wParam,szMessage,MSGSIZE,0);
		InsertLog(szMessage,LOGRECV);
		
		break;
	case FD_WRITE:
		break;
	case FD_CLOSE:
		strcpy(szLog, "client has disconnected");
		InsertLog(szLog,LOGRECV);
		closesocket(wParam);
		break;

	}
	//SOCKADDR_IN c_addr;

	return 0;
	
}

void CVirtualServerView::InsertLog(char* szLogBuffer,int nLogType)
{
	::GetTime(szDateTime);
	CListView* clv = (CListView*)this->GetDlgItem(IDC_LIST);
	CListCtrl* clc = &(clv->GetListCtrl());

	int nRowNum = clc->GetItemCount();
	char szColumnOne[10];
	sprintf(szColumnOne,"%d",nRowNum);
	clc->InsertItem(nRowNum,szColumnOne);
	clc->SetItemText(nRowNum,1,szDateTime);
	switch(nLogType)
	{
	case LOGRECV:
		clc->SetItemText(nRowNum,2,szLogBuffer);
		break;
	case LOGSEND:
		clc->SetItemText(nRowNum,3,szLogBuffer);
		break;
	}

}


void CVirtualServerView::OnDestroy() 
{
	closesocket(sListen);
	WSACleanup();
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	
}
