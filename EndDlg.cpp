// EndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle.h"
#include "EndDlg.h"
#include "MainFrm.h"
#include "PuzzleDoc.h"
#include "PuzzleView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// EndDlg dialog


EndDlg::EndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(EndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(EndDlg)
	m_Text = _T("");
	m_end = _T("");
	//}}AFX_DATA_INIT
}


void EndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(EndDlg)
	DDX_Text(pDX, IDC_STATICENDTEXT, m_Text);
	DDX_Text(pDX, IDC_STATICEND, m_end);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(EndDlg, CDialog)
	//{{AFX_MSG_MAP(EndDlg)
	ON_BN_CLICKED(IDC_BUTTONPLAYAGAIN, OnButtonplayagain)
	ON_BN_CLICKED(IDC_BUTTONUNPLAY, OnButtonunplay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// EndDlg message handlers

BOOL EndDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

////////////////////////////////////////////////
	this->Button1.LoadBitmaps(IDB_BITMAP17);//×Ô»æ
	this->Button1.SubclassDlgItem(IDC_BUTTONPLAYAGAIN,this);
	this->Button1.SizeToContent();

	
////////////////////////////////////////////////
	this->Button2.LoadBitmaps(IDB_BITMAP16);//×Ô»æ
	this->Button2.SubclassDlgItem(IDC_BUTTONUNPLAY,this);
	this->Button2.SizeToContent();


///////////////////////////////////////////////

	m_static.SubclassDlgItem(IDC_STATICENDTEXT,this);
    LOGFONT   log; 
    GetObject(::GetStockObject(DEFAULT_GUI_FONT),sizeof(log),&log); 
    log.lfHeight=25;     
    log.lfWidth=10;      
    log.lfCharSet=GB2312_CHARSET; 
    lstrcpy(log.lfFaceName, _T("Î¢ÈíÑÅºÚ")); 
    font.CreateFontIndirect(&log); 
    m_static.SetFont(&font); 
	
	CPuzzleView* m_pView = (CPuzzleView*)((CMainFrame*) AfxGetMainWnd())->GetActiveView();
	CString strsteptime;
	strsteptime.Format("%s" "%s" "%s" "%d" "%s" ,"³É¼¨£º ",m_pView->m_mtime,"  ",m_pView->m_step," ²½");
	this->m_Text=strsteptime;

	m_end="¹§Ï²ÄúÍê³ÉÁËÆ´Í¼£¡";
	UpdateData(FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void EndDlg::OnButtonplayagain() 
{
	// TODO: Add your control notification handler code here
	CPuzzleView* m_pView = (CPuzzleView*)((CMainFrame*) AfxGetMainWnd())->GetActiveView();
    m_pView->reset();
	m_pView->stepreset();
	m_pView->timereset();
	m_pView->InvalidateRect(&(m_pView->mainrect));
	this->EndDialog(0);

}

void EndDlg::OnButtonunplay() 
{
	// TODO: Add your control notification handler code here
	CPuzzleView* m_pView = (CPuzzleView*)((CMainFrame*) AfxGetMainWnd())->GetActiveView();
	m_pView->flag = true;
	this->EndDialog(0);
	
}
