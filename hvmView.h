// hvmView.h : interface of the CHvmView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "msflexgrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_HVMVIEW_H__2BF77744_62AD_4ECA_9C17_44A8599AD6E8__INCLUDED_)
#define AFX_HVMVIEW_H__2BF77744_62AD_4ECA_9C17_44A8599AD6E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHvmView : public CFormView
{
protected: // create from serialization only
	CHvmView();
	DECLARE_DYNCREATE(CHvmView)

public:
	//{{AFX_DATA(CHvmView)
	enum { IDD = IDD_HVM_FORM };
	CMSFlexGrid	m_msg1;
	CString	m_etq;
	CString	m_hk;
	CString	m_mitq;
	CString	m_mkg;
	CString	m_mtg;
	CString	m_mtq;
	CString	m_nkq;
	CString	m_ykq;
	CString	m_ytq;
	CMSFlexGrid	m_msg2;
	CString	m_etmkq;
	CString	m_fatq;
	CString	m_kg;
	CString	m_mtog;
	CString	m_mtogm;
	//}}AFX_DATA

// Attributes
public:
	CHvmDoc* GetDocument();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHvmView)
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
	virtual ~CHvmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool is_minus;
	bool is_run;
	bool is_next;
	bool is_back;
	bool test(int,int,short int,CHvmDoc*);
	short int index;
	void DrowThis();
	void nul();
// Generated message map functions
protected:
	//{{AFX_MSG(CHvmView)
	afx_msg void OnKeyPressMsflexgrid1(short FAR* KeyAscii);
	afx_msg void OnUpdateToolsRun(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsNext(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsBack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsComplate(CCmdUI* pCmdUI);
	afx_msg void OnToolsComplate();
	afx_msg void OnToolsRun();
	afx_msg void OnToolsBack();
	afx_msg void OnToolsNext();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in hvmView.cpp
inline CHvmDoc* CHvmView::GetDocument()
   { return (CHvmDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVMVIEW_H__2BF77744_62AD_4ECA_9C17_44A8599AD6E8__INCLUDED_)
