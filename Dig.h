#if !defined(AFX_DIG_H__67C53082_AA48_4ED5_9AFC_2B65C6A6D4A3__INCLUDED_)
#define AFX_DIG_H__67C53082_AA48_4ED5_9AFC_2B65C6A6D4A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDig dialog

class CDig : public CDialog
{
// Construction
public:
	CDig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDig)
	enum { IDD = IDD_DIALOG1 };
	int		m_cq;
	short	m_tq;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDig)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIG_H__67C53082_AA48_4ED5_9AFC_2B65C6A6D4A3__INCLUDED_)
