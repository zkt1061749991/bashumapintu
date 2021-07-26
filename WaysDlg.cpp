// WaysDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle.h"
#include "WaysDlg.h"
#include "MainFrm.h"
#include "PuzzleDoc.h"
#include "PuzzleView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WaysDlg dialog


WaysDlg::WaysDlg(CWnd* pParent /*=NULL*/)
	: CDialog(WaysDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(WaysDlg)
	m_text = _T("");
	//}}AFX_DATA_INIT
}


void WaysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WaysDlg)
	DDX_Text(pDX, IDC_STATICTEXT, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WaysDlg, CDialog)
	//{{AFX_MSG_MAP(WaysDlg)
	ON_BN_CLICKED(IDC_BUTTONOK, OnButtonok)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WaysDlg message handlers

BOOL WaysDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_text = "游戏规则:\n\r\n\r交换空白块与其相邻块完成拼图\n\r\n\r玩法说明:\n\r\n\r1.通过键盘方向键交换位置。\n\r\n\r2.通过鼠标左键单击非空白块交换位置\n\r\n\r玩法技巧:\n\r\n\r1.查看原图以提高准确性\n\r\n\r2.逐层实现拼图以提高效率";
	UpdateData(FALSE);
    
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void WaysDlg::OnButtonok() 
{
	EndDialog(0); //关闭对话框
}
