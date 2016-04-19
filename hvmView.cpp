// hvmView.cpp : implementation of the CHvmView class
//

#include "stdafx.h"
#include "hvm.h"

#include "hvmDoc.h"
#include "hvmView.h"
//#include "transfer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHvmView

IMPLEMENT_DYNCREATE(CHvmView, CFormView)

BEGIN_MESSAGE_MAP(CHvmView, CFormView)
	//{{AFX_MSG_MAP(CHvmView)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_RUN, OnUpdateToolsRun)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_NEXT, OnUpdateToolsNext)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_BACK, OnUpdateToolsBack)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_COMPLATE, OnUpdateToolsComplate)
	ON_COMMAND(ID_TOOLS_COMPLATE, OnToolsComplate)
	ON_COMMAND(ID_TOOLS_RUN, OnToolsRun)
	ON_COMMAND(ID_TOOLS_BACK, OnToolsBack)
	ON_COMMAND(ID_TOOLS_NEXT, OnToolsNext)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHvmView construction/destruction

//extern transfer tr;

CHvmView::CHvmView()
	: CFormView(CHvmView::IDD)
{
	//{{AFX_DATA_INIT(CHvmView)
	m_etq = _T("");
	m_hk = _T("");
	m_mitq = _T("");
	m_mkg = _T("");
	m_mtg = _T("");
	m_mtq = _T("");
	m_nkq = _T("");
	m_ykq = _T("");
	m_ytq = _T("");
	m_etmkq = _T("");
	m_fatq = _T("");
	m_kg = _T("");
	m_mtog = _T("");
	m_mtogm = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	index=0;
}

CHvmView::~CHvmView()
{
}

void CHvmView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHvmView)
	DDX_Control(pDX, IDC_MSFLEXGRID1, m_msg1);
	DDX_Text(pDX, IDC_ETQ, m_etq);
	DDX_Text(pDX, IDC_HK, m_hk);
	DDX_Text(pDX, IDC_MITQ, m_mitq);
	DDX_Text(pDX, IDC_MKG, m_mkg);
	DDX_Text(pDX, IDC_MTG, m_mtg);
	DDX_Text(pDX, IDC_MTQ, m_mtq);
	DDX_Text(pDX, IDC_NKQ, m_nkq);
	DDX_Text(pDX, IDC_YKQ, m_ykq);
	DDX_Text(pDX, IDC_YTQ, m_ytq);
	DDX_Control(pDX, IDC_MSFLEXGRID2, m_msg2);
	DDX_Text(pDX, IDC_ETMKQ, m_etmkq);
	DDX_Text(pDX, IDC_FATQ, m_fatq);
	DDX_Text(pDX, IDC_KG, m_kg);
	DDX_Text(pDX, IDC_MTOG, m_mtog);
	DDX_Text(pDX, IDC_MTOGM, m_mtogm);
	//}}AFX_DATA_MAP
}

BOOL CHvmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CHvmView::OnInitialUpdate()
{
	CString s;
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	CHvmDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	m_msg1.SetCols(pDoc->gr.getcq()+1);
	m_msg2.SetCols(pDoc->gr.gettq()+1);
	m_msg2.SetRows(pDoc->gr.gettq()+1);
	m_msg1.SetTextMatrix(1,0,"Start");
	m_msg1.SetTextMatrix(2,0,"End");
	for(int i=0;i<pDoc->gr.getcq();i++)
	{
		if(pDoc->gr.p[i].t[0]!=-1)
		{
			s.Format("%u",pDoc->gr.p[i].t[0]);
			m_msg1.SetTextMatrix(1,i+1,s);
		}
		if(pDoc->gr.p[i].t[1]!=-1)
		{
			s.Format("%u",pDoc->gr.p[i].t[1]);
			m_msg1.SetTextMatrix(2,i+1,s);
		}
		s.Format("Connec%u",i+1);
		m_msg1.SetTextMatrix(0,i+1,s);
	}
	is_run=(pDoc->gr.lq==0);
	is_next=is_back=false;
	s.Format("%u",pDoc->gr.lq);
	m_msg1.SetTextMatrix(0,0,s);
	m_ytq.Format("%u",pDoc->gr.gettq());
	m_ykq.Format("%u",pDoc->gr.getcq());
	UpdateData(false);
	for(i=0;i<pDoc->gr.gettq();i++)
	{
		s.Format("%u",i+1);
		m_msg2.SetTextMatrix(0,i+1,s);
		m_msg2.SetTextMatrix(i+1,0,s);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHvmView printing

BOOL CHvmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHvmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHvmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHvmView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CHvmView diagnostics

#ifdef _DEBUG
void CHvmView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHvmView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHvmDoc* CHvmView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHvmDoc)));
	return (CHvmDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHvmView message handlers

bool CHvmView::test(int r,int c,short int mt,CHvmDoc* pDoc)
{
	if((r==1 && mt>=1 && mt<=pDoc->gr.gettq())||
			(r==2 && mt>=0 && mt<=pDoc->gr.gettq()))
			if(pDoc->gr.p[c-1].t[2-r]>-1)
			{
				if(mt!=pDoc->gr.p[c-1].t[2-r])
				{
					bool t=true;
					for(int i=0;i<pDoc->gr.getcq();i++)
					{
						if((pDoc->gr.p[i].t[0]!=-1 && pDoc->gr.p[i].t[1]!=-1)&&
							(pDoc->gr.p[i].t[0]==mt && pDoc->gr.p[i].t[1]==pDoc->gr.p[c-1].t[2-r])||
							(pDoc->gr.p[i].t[0]==pDoc->gr.p[c-1].t[2-r] && pDoc->gr.p[i].t[1]==mt))
						{
							t=false;
							break;
						}
					}
					if(t)
					{
						pDoc->gr.p[c-1].t[r-1]=mt;
						CString s;
						s.Format("%u",mt);
						m_msg1.SetTextMatrix(r,c,s);
						if(is_minus)
						{
							pDoc->gr.lq--;
							s.Format("%u",pDoc->gr.lq);
							m_msg1.SetTextMatrix(0,0,s);
						}
						nul();
						return true;
					}
				}
			}
			else
			{
				pDoc->gr.p[c-1].t[r-1]=mt;
				CString s;
				s.Format("%u",mt);
				m_msg1.SetTextMatrix(r,c,s);
				if(is_minus)
				{
					pDoc->gr.lq--;
					s.Format("%u",pDoc->gr.lq);
					m_msg1.SetTextMatrix(0,0,s);
				}
				nul();
				return true;
			}
	return false;
}

BEGIN_EVENTSINK_MAP(CHvmView, CFormView)
    //{{AFX_EVENTSINK_MAP(CHvmView)
	ON_EVENT(CHvmView, IDC_MSFLEXGRID1, -603 /* KeyPress */, OnKeyPressMsflexgrid1, VTS_PI2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CHvmView::OnKeyPressMsflexgrid1(short FAR* KeyAscii) 
{
	char nChar=static_cast<char>(*KeyAscii);
	int r=m_msg1.GetRow(),c=m_msg1.GetCol();
	if(r>0 && c>0)
	{
		CHvmDoc* pDoc=GetDocument();
		ASSERT_VALID(pDoc);
		if(nChar>='0' && nChar<='9')
		{
			short int mt;
			if(pDoc->gr.p[c-1].t[r-1]==-1)
			{
				is_minus=true;
				mt=nChar-'0';
			}
			else
			{
				mt=pDoc->gr.p[c-1].t[r-1]*10+nChar-'0';
				is_minus=false;
			}
			if(test(r,c,mt,pDoc))
			{
				pDoc->UpdateAllViews(this,0L,NULL);
				pDoc->SetModifiedFlag();
			}
		}
		else
			if(nChar==static_cast<char>(8))
			{
				int r=m_msg1.GetRow(),c=m_msg1.GetCol(),mt;
				if(pDoc->gr.p[c-1].t[r-1]>=10)
				{
					mt=pDoc->gr.p[c-1].t[r-1]/10;
					if(test(r,c,mt,pDoc))
					{
						pDoc->UpdateAllViews(this,0L,NULL);
						pDoc->SetModifiedFlag();
					}
				}
				else
				{
					pDoc->gr.p[c-1].t[r-1]=-1;
					m_msg1.SetTextMatrix(r,c,"");
					nul();
					pDoc->gr.lq++;
					CString s;
					s.Format("%u",pDoc->gr.lq);
					m_msg1.SetTextMatrix(0,0,s);
				}
			}
		is_run=(pDoc->gr.lq==0);
	}
}

void CHvmView::OnUpdateToolsRun(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(is_run);
}

void CHvmView::OnUpdateToolsNext(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(is_next);
}

void CHvmView::OnUpdateToolsBack(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(is_back);
}

void CHvmView::OnUpdateToolsComplate(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(true);	
}

void CHvmView::OnToolsComplate() 
{
	CHvmDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	for(int	i=0;i<pDoc->gr.getcq();i++)
	{
		if(pDoc->gr.p[i].t[0]==-1)
			while(!test(1,i+1,rand()%pDoc->gr.gettq()+1,pDoc));
		if(pDoc->gr.p[i].t[1]==-1)
			while(!test(2,i+1,rand()%(pDoc->gr.gettq()+1),pDoc));
	}
	pDoc->gr.lq=0;
	m_msg1.SetTextMatrix(0,0,"0");
	is_run=true;
	pDoc->UpdateAllViews(this,0L,NULL);
	pDoc->SetModifiedFlag();
}

void CHvmView::OnToolsRun() 
{
	CHvmDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	short int mtq,etq,mitq;
	int nkq,etmkq;
	double mkg,mtg,mtogm,kg;
	short int hk=pDoc->gr.run(mtq,etq,mitq,nkq,mkg,mtg,mtogm,kg,etmkq);
	m_mtq.Format("%u",mtq);
	m_etq.Format("%u",etq);
	m_mitq.Format("%u",mitq);
	m_nkq.Format("%u",nkq);
	m_mkg.Format("%.3f",mkg);
	m_mtg.Format("%.3f",mtg);
	m_hk.Format("%u",hk);
	m_mtogm.Format("%.3f",mtogm);
	m_kg.Format("%.3f",kg);
	m_etmkq.Format("%u",etmkq);
	UpdateData(false);
	is_next=true;
	DrowThis();
}

void CHvmView::DrowThis()
{
	CHvmDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	short int i,j,q=pDoc->gr.gettq();
	CString s;
	for(i=0;i<q;i++)
		for(j=0;j<q;j++)
		{
			s.Format("%u",pDoc->gr.vm[index].m[i+1][j+1]);
			m_msg2.SetTextMatrix(i+1,j+1,s);
		}
	if(index==pDoc->gr.n_vm)
		s="delta";
	else
		s.Format("A^%u",index+1);
	m_msg2.SetTextMatrix(0,0,s);
	if(index<pDoc->gr.n_vm)
	{
		m_fatq.Format("%u",pDoc->gr.fatq[index]);
		m_mtog.Format("%.3f",pDoc->gr.mtog[index]);
	}
	else
		m_fatq=m_mtog="";
	UpdateData(false);
}

void CHvmView::OnToolsBack() 
{
	CHvmDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	index--;
	is_next=true;
	if(index==0)
		is_back=false;
	DrowThis();
}

void CHvmView::OnToolsNext() 
{
	CHvmDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	index++;
	is_back=true;
	if(index==pDoc->gr.n_vm)
		is_next=false;
	DrowThis();
}

void CHvmView::nul()
{
	is_next=is_back=false;
	m_mtq="";
	m_etq="";
	m_mitq="";
	m_nkq="";
	m_mkg="";
	m_mtg="";
	m_hk="";
	m_fatq="";
	m_mtog="";
	m_mtogm="";
	m_kg="";
	m_etmkq="";
	UpdateData(false);
	CHvmDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	short int i,j,q=pDoc->gr.gettq();
	for(i=0;i<q;i++)
		for(j=0;j<q;j++)
			m_msg2.SetTextMatrix(i+1,j+1,"");
}
