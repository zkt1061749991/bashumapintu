// LookPic.cpp : implementation file
//

#include "stdafx.h"
#include "Puzzle.h"
#include "LookPic.h"

#include "PuzzleDoc.h"
#include "PuzzleView.h"
#include "Resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LookPic dialog


LookPic::LookPic(CWnd* pParent /*=NULL*/)
	: CDialog(LookPic::IDD, pParent)
{
	//{{AFX_DATA_INIT(LookPic)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void LookPic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LookPic)
	DDX_Control(pDX, IDC_STATICLOOKPIC, m_lookpic);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LookPic, CDialog)
	//{{AFX_MSG_MAP(LookPic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LookPic message handlers

BOOL LookPic::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
    CPuzzleView* m_pView = (CPuzzleView*)((CMainFrame*) AfxGetMainWnd())->GetActiveView();
    CBitmap * pic = m_pView->m_bitmap;
	CRect r(0, 0, 350, 350);
	
    CDC* pdcpic = m_lookpic.GetDC();    

    BITMAP bmp;  
    pic->GetBitmap(&bmp);  
    CDC memdc;  
    int wide;
		if(bmp.bmWidth<=bmp.bmHeight)
	        wide =  bmp.bmWidth;  //获得每块的宽度
		else
            wide =  bmp.bmHeight;
    memdc.CreateCompatibleDC(pdcpic);  
    memdc.SelectObject(pic);  
  
    CDC ppdc;  
    ppdc.CreateCompatibleDC(pdcpic);  
    CBitmap bmpbuf;                    //bmpbuf是要放入控件中的位图  
    bmpbuf.CreateCompatibleBitmap(pdcpic, r.right, r.bottom);  
    ppdc.SelectObject(&bmpbuf);  
    ppdc.SetStretchBltMode(HALFTONE);
    ppdc.StretchBlt(0, 0, 350,350,&memdc,0,0,wide,wide, SRCCOPY);  //将IDB_BITMAP复制到bmpbuf位图中，并按指定的大小转换  
  
    m_lookpic.SetBitmap((HBITMAP)bmpbuf.Detach());  
    m_lookpic.ReleaseDC(pdcpic);  
    memdc.DeleteDC();  
    ppdc.DeleteDC();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
