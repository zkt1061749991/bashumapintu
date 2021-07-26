// SelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle.h"
#include "SelectDlg.h"
#include "Resource.h"
#include "winuser.h"

#include "PuzzleDoc.h"
#include "PuzzleView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SelectDlg dialog


SelectDlg::SelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SelectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SelectDlg)
	//}}AFX_DATA_INIT
}


void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SelectDlg)
	DDX_Control(pDX, IDC_STATICPIC6, m_pic6);
	DDX_Control(pDX, IDC_STATICPIC5, m_pic5);
	DDX_Control(pDX, IDC_STATICPIC4, m_pic4);
	DDX_Control(pDX, IDC_STATICPIC3, m_pic3);
	DDX_Control(pDX, IDC_STATICPIC2, m_pic2);
	DDX_Control(pDX, IDC_STATICPIC1, m_pic1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialog)
	//{{AFX_MSG_MAP(SelectDlg)
	ON_BN_CLICKED(IDC_STATICPIC1, OnStaticpic1)
	ON_BN_CLICKED(IDC_STATICPIC4, OnStaticpic4)
	ON_BN_CLICKED(IDC_STATICPIC6, OnStaticpic6)
	ON_BN_CLICKED(IDC_STATICPIC5, OnStaticpic5)
	ON_BN_CLICKED(IDC_STATICPIC3, OnStaticpic3)
	ON_BN_CLICKED(IDC_STATICPIC2, OnStaticpic2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SelectDlg message handlers

BOOL SelectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here


	
	this->Button1.LoadBitmaps(IDB_BITMAP14);  //��ť�Ի�ͼƬ��װ��
	this->Button1.SubclassDlgItem(IDCANCEL,this);
	this->Button1.SizeToContent();

//����Ԥ��ͼƬ
	drawpic(&m_pic1,IDB_BITMAP1);
	drawpic(&m_pic2,IDB_BITMAP2);
	drawpic(&m_pic3,IDB_BITMAP3);
	drawpic(&m_pic4,IDB_BITMAP4);
	drawpic(&m_pic5,IDB_BITMAP6);
	drawpic(&m_pic6,IDB_BITMAP5);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

////////////////////////Ԥ��ͼƬ��ʽ�����ƺ���//////////////////////////////////////////////
void SelectDlg::drawpic(CStatic * m_pic,int ID)
{
    CRect r(0, 0, 180, 180);  
    CDC* pdcpic = m_pic->GetDC();  //m_Pic��Picture�ؼ��ı���  
  
    CBitmap bitmap;  
    bitmap.LoadBitmap(ID);   //ID��Ҫ���ص�λͼ��ID  
    BITMAP bmp;  
    bitmap.GetBitmap(&bmp);  
    CDC memdc;  
    memdc.CreateCompatibleDC(pdcpic);  
    memdc.SelectObject(&bitmap);  
  
    CDC ppdc;  
    ppdc.CreateCompatibleDC(pdcpic);  
    CBitmap bmpbuf;                    //bmpbuf��Ҫ����ؼ��е�λͼ  
    bmpbuf.CreateCompatibleBitmap(pdcpic, r.right, r.bottom);  
    ppdc.SelectObject(&bmpbuf);  
    ppdc.SetStretchBltMode(HALFTONE);
    ppdc.StretchBlt(0, 0, 200,200,&memdc,0,0,bmp.bmWidth,bmp.bmHeight, SRCCOPY);  //��IDB_BITMAP���Ƶ�bmpbufλͼ�У�����ָ���Ĵ�Сת��  
  
    m_pic->SetBitmap((HBITMAP)bmpbuf.Detach());  
    m_pic->ReleaseDC(pdcpic);  
    memdc.DeleteDC();  
    ppdc.DeleteDC();

}

/////////////////////////////ͼƬѡ����ִ�к���//////////////////////////////////////////////

void SelectDlg::OnStaticpic1() 
{
	// TODO: Add your control notification handler code here
	CMainFrame*   pFrame=(CMainFrame*)AfxGetMainWnd();   
    CPuzzleView* pView = (CPuzzleView*)pFrame->GetActiveView();
	pView->Onpic1(); 
	this->EndDialog(0);
}

void SelectDlg::OnStaticpic2() 
{
	// TODO: Add your control notification handler code here
CMainFrame*   pFrame=(CMainFrame*)AfxGetMainWnd();   
    CPuzzleView* pView = (CPuzzleView*)pFrame->GetActiveView();
	pView->Onpic2(); 
	this->EndDialog(0);
}

void SelectDlg::OnStaticpic3() 
{
	// TODO: Add your control notification handler code here
    CMainFrame*   pFrame=(CMainFrame*)AfxGetMainWnd();   
    CPuzzleView* pView = (CPuzzleView*)pFrame->GetActiveView();
	pView->Onpic3(); 
	this->EndDialog(0);
}
void SelectDlg::OnStaticpic4() 
{
	// TODO: Add your control notification handler code here
	CMainFrame*   pFrame=(CMainFrame*)AfxGetMainWnd();   
    CPuzzleView* pView = (CPuzzleView*)pFrame->GetActiveView();
	pView->Onpic4(); 
	this->EndDialog(0);
}

void SelectDlg::OnStaticpic5() 
{
	// TODO: Add your control notification handler code here
    CMainFrame*   pFrame=(CMainFrame*)AfxGetMainWnd();   
    CPuzzleView* pView = (CPuzzleView*)pFrame->GetActiveView();
	pView->Onpic5(); 
	this->EndDialog(0);
}

void SelectDlg::OnStaticpic6() 
{
	// TODO: Add your control notification handler code here
    CMainFrame*   pFrame=(CMainFrame*)AfxGetMainWnd();   
    CPuzzleView* pView = (CPuzzleView*)pFrame->GetActiveView();
	pView->Onpic6(); 
	this->EndDialog(0);
}






