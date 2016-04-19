// hvm.h : main header file for the HVM application
//

#if !defined(AFX_HVM_H__81CD380D_89D4_412B_848F_7EBC856537EC__INCLUDED_)
#define AFX_HVM_H__81CD380D_89D4_412B_848F_7EBC856537EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHvmApp:
// See hvm.cpp for the implementation of this class
//

class CHvmApp : public CWinApp
{
public:
	CHvmApp();
private:
	bool is_first;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHvmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHvmApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVM_H__81CD380D_89D4_412B_848F_7EBC856537EC__INCLUDED_)
