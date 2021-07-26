// FreeLevelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle.h"
#include "FreeLevelDlg.h"
#include "PuzzleDoc.h"
#include "PuzzleView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// FreeLevelDlg dialog


FreeLevelDlg::FreeLevelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FreeLevelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(FreeLevelDlg)
	m_freelevel = 0;
	//}}AFX_DATA_INIT
}


void FreeLevelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(FreeLevelDlg)
	DDX_Text(pDX, IDC_EDIT1, m_freelevel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(FreeLevelDlg, CDialog)
	//{{AFX_MSG_MAP(FreeLevelDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// FreeLevelDlg message handlers

void FreeLevelDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(1);
	CPuzzleView* m_pView = (CPuzzleView*)((CMainFrame*) AfxGetMainWnd())->GetActiveView();

	if(m_freelevel>1&&m_freelevel<=10)
	{
	m_pView->freelevel(m_freelevel);
	}
	else
	{
		MessageBox("阶数应为2—10之间的整数");
	    
	}
	
	
	CDialog::OnOK();
}
