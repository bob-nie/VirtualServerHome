// VirtualServerDoc.h : interface of the CVirtualServerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIRTUALSERVERDOC_H__A1CA4E2C_0AF3_453B_9642_D8458DC9F232__INCLUDED_)
#define AFX_VIRTUALSERVERDOC_H__A1CA4E2C_0AF3_453B_9642_D8458DC9F232__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVirtualServerDoc : public CDocument
{
protected: // create from serialization only
	CVirtualServerDoc();
	DECLARE_DYNCREATE(CVirtualServerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualServerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVirtualServerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVirtualServerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALSERVERDOC_H__A1CA4E2C_0AF3_453B_9642_D8458DC9F232__INCLUDED_)
