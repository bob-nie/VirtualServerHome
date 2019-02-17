// VirtualServer.h : main header file for the VIRTUALSERVER application
//

#if !defined(AFX_VIRTUALSERVER_H__BA30C86E_BC09_47BF_A3C2_5A5AFE52C07C__INCLUDED_)
#define AFX_VIRTUALSERVER_H__BA30C86E_BC09_47BF_A3C2_5A5AFE52C07C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVirtualServerApp:
// See VirtualServer.cpp for the implementation of this class
//

class CVirtualServerApp : public CWinApp
{
public:
	CVirtualServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVirtualServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CVirtualServerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIRTUALSERVER_H__BA30C86E_BC09_47BF_A3C2_5A5AFE52C07C__INCLUDED_)
