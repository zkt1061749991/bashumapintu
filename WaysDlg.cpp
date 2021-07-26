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
	m_text = "��Ϸ����:\n\r\n\r�����հ׿��������ڿ����ƴͼ\n\r\n\r�淨˵��:\n\r\n\r1.ͨ�����̷��������λ�á�\n\r\n\r2.ͨ�������������ǿհ׿齻��λ��\n\r\n\r�淨����:\n\r\n\r1.�鿴ԭͼ�����׼ȷ��\n\r\n\r2.���ʵ��ƴͼ�����Ч��";
	UpdateData(FALSE);
    
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void WaysDlg::OnButtonok() 
{
	EndDialog(0); //�رնԻ���
}
