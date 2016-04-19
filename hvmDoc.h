// hvmDoc.h : interface of the CHvmDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HVMDOC_H__AA9B57AA_0961_4E1F_BE5F_167C50EF24AA__INCLUDED_)
#define AFX_HVMDOC_H__AA9B57AA_0961_4E1F_BE5F_167C50EF24AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "graph.h"//<---

class CHvmDoc : public CDocument
{
protected: // create from serialization only
	CHvmDoc();
	DECLARE_DYNCREATE(CHvmDoc)

// Attributes
public:
	graph gr;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHvmDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHvmDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHvmDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HVMDOC_H__AA9B57AA_0961_4E1F_BE5F_167C50EF24AA__INCLUDED_)
