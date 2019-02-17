// VirtualServerDoc.cpp : implementation of the CVirtualServerDoc class
//

#include "stdafx.h"
#include "VirtualServer.h"

#include "VirtualServerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerDoc

IMPLEMENT_DYNCREATE(CVirtualServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CVirtualServerDoc, CDocument)
	//{{AFX_MSG_MAP(CVirtualServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerDoc construction/destruction

CVirtualServerDoc::CVirtualServerDoc()
{
	// TODO: add one-time construction code here

}

CVirtualServerDoc::~CVirtualServerDoc()
{
}

BOOL CVirtualServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVirtualServerDoc serialization

void CVirtualServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerDoc diagnostics

#ifdef _DEBUG
void CVirtualServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVirtualServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerDoc commands
