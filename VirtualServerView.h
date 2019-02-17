// VirtualServerView.h : interface of the CVirtualServerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIRTUALSERVERVIEW_H__42068BAB_7AB8_4EDD_A56C_C6361D1F051E__INCLUDED_)
#define AFX_VIRTUALSERVERVIEW_H__42068BAB_7AB8_4EDD_A56C_C6361D1F051E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVirtualServerView : public CFormView
{
protected: // create from serialization only
	CVirtualServerView();
	DECLARE_DYNCREATE(CVirtualServerView)

public:
	//{{AFX_DATA(CVirtualServerView)
	enum{ IDD = IDD_VIRTUALSERVER_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CVirtualServerDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualServerView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVirtualServerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVirtualServerView)
	afx_msg void OnBtnSend();
	afx_msg LRESULT OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnSrvStart();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void InsertLog(char* szLogBuffer,int nLogType);
};



#ifndef _DEBUG  // debug version in VirtualServerView.cpp
inline CVirtualServerDoc* CVirtualServerView::GetDocument()
   { return (CVirtualServerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALSERVERVIEW_H__42068BAB_7AB8_4EDD_A56C_C6361D1F051E__INCLUDED_)
