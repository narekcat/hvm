// Dig.cpp : implementation file
//

#include "stdafx.h"
#include "hvm.h"
#include "Dig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDig dialog


CDig::CDig(CWnd* pParent /*=NULL*/)
	: CDialog(CDig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDig)
	m_cq = 0;
	m_tq = 0;
	//}}AFX_DATA_INIT
}


void CDig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDig)
	DDX_Text(pDX, IDC_EDIT1, m_cq);
	DDV_MinMaxInt(pDX, m_cq, 1, 79800);
	DDX_Text(pDX, IDC_EDIT2, m_tq);
	DDV_MinMaxInt(pDX, m_tq, 2, 400);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDig, CDialog)
	//{{AFX_MSG_MAP(CDig)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDig message handlers
