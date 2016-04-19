// hvmDoc.cpp : implementation of the CHvmDoc class
//

#include "stdafx.h"
#include "hvm.h"

#include "hvmDoc.h"
#include "transfer.h"//<---
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHvmDoc

IMPLEMENT_DYNCREATE(CHvmDoc, CDocument)

BEGIN_MESSAGE_MAP(CHvmDoc, CDocument)
	//{{AFX_MSG_MAP(CHvmDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHvmDoc construction/destruction

extern transfer tr;

CHvmDoc::CHvmDoc()
{
	gr.setGraphParams(tr.cq,tr.tq);
}

CHvmDoc::~CHvmDoc()
{
}

BOOL CHvmDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	SetModifiedFlag();
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHvmDoc serialization

void CHvmDoc::Serialize(CArchive& ar)
{
	gr.Serialize(ar);
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
// CHvmDoc diagnostics

#ifdef _DEBUG
void CHvmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHvmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHvmDoc commands
