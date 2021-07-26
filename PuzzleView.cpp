// PuzzleView.cpp : implementation of the CPuzzleView class
//


#include "stdafx.h"
#include "Puzzle.h"
#include "P.h"
#include "PuzzleDoc.h"
#include "PuzzleView.h"
#include "LookPic.h"
#include "FreeLevelDlg.h"
#include "EndDlg.h"
//ʵ�������ʼ����Ҫ��ͷ�ļ�
#include "time.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/*********************************************************/
//ʵ����Ч��Ҫ��ͷ�ļ��Ϳ�
#include "windows.h"
#include "Mmsystem.h"
#pragma comment(lib,"WINMM.LIB")
/*********************************************************/

/////////////////////////////////////////////////////////////////////////////
// CPuzzleView

IMPLEMENT_DYNCREATE(CPuzzleView, CFormView)

BEGIN_MESSAGE_MAP(CPuzzleView, CFormView)
	//{{AFX_MSG_MAP(CPuzzleView)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MENUITEM32776, OnEasy)
	ON_COMMAND(ID_MENUITEM32777, OnMd)
	ON_COMMAND(ID_MENUITEM32778, OnHard)
	ON_COMMAND(ID_QUICKSTART, OnQuickstart)
	ON_COMMAND(ID_MENUITEM32781, OnFreeLevel)
	ON_COMMAND(ID_AOTUPLAYER, OnAotuplayer)
	ON_COMMAND(ID_PIC_OPEN, OnPicOpen)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTONLOOKPIC, OnButtonlookpic)
	ON_BN_CLICKED(IDC_BUTTONRESTART, OnButtonrestart)
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPuzzleView construction/destruction

CPuzzleView::CPuzzleView() : CFormView(CPuzzleView::IDD)
{
	//{{AFX_DATA_INIT(CPuzzleView)
	m_mstep = _T("0 ��");
	m_mtime = _T("0 �� ");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
/**********************************************************/
	//�ֲ�ˢ�¾��θ�ֵ
	mainrect.left = X;
	mainrect.right = X+WIDE;
	mainrect.top = Y;
	mainrect.bottom = Y+WIDE;
/**********************************************************/
    flag = false;  //�趨��ɴ��ڿɵ���

/**********************************************************/
	//��ȡԤ��ͼƬ��Դ���
	PIC1 = IDB_BITMAP1;
    PIC2 = IDB_BITMAP2;
	PIC3 = IDB_BITMAP3;
	PIC4 = IDB_BITMAP4;
	PIC5 = IDB_BITMAP5;
	PIC6 = IDB_BITMAP6;
	PIC = PIC1;  //Ĭ�ϵõ�PIC1
/*********************************************************/
	//��ȡ��Ч��Դ���
	WAV = IDR_WAVE1;
	WAVEND = IDR_WAVE2;
	WAVRESET = IDR_WAVE3;
/************************************************************************/
    m_bitmap = new CBitmap();    
	m_bitmap->LoadBitmap(PIC);  //װ��ͼƬ��Դ������ 
/************************************************************************/	
}


CPuzzleView::~CPuzzleView()
{
}

void CPuzzleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPuzzleView)
	DDX_Control(pDX, IDC_STEP, m_static2);
	DDX_Control(pDX, IDC_STATICTIME, m_timecontrol);
	DDX_Text(pDX, IDC_STEP, m_mstep);
	DDX_Text(pDX, IDC_STATICTIME, m_mtime);
	//}}AFX_DATA_MAP
}

//////////////////////////////���水ť����///////////////////////////////////
BOOL CPuzzleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	this->Button1.LoadBitmaps(IDB_BUTTON1);//�Ի�
	this->Button1.SubclassDlgItem(IDC_BUTTONLOOKPIC,this);
	this->Button1.SizeToContent();

	this->Button2.LoadBitmaps(IDB_BUTTON2);//�Ի�
	this->Button2.SubclassDlgItem(IDC_BUTTONRESTART,this);
	this->Button2.SizeToContent();
	this->stepstyle();
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CPuzzleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CPuzzleView printing

BOOL CPuzzleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation

	return DoPreparePrinting(pInfo);
}

void CPuzzleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPuzzleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPuzzleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here

}

/////////////////////////////////////////////////////////////////////////////
// CPuzzleView diagnostics

#ifdef _DEBUG
void CPuzzleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPuzzleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPuzzleDoc* CPuzzleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPuzzleDoc)));
	return (CPuzzleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPuzzleView message handlers

///////////////////////////���ڻ���//////////////////////////////////////////////////////////

//ƴͼ����Ļ���
void CPuzzleView::OnDraw(CDC* pDC) 
{

	// TODO: Add your specialized code here and/or call the base class
	this->GetDocument()->p->draw(pDC, m_bitmap);	//����ƴͼ����
	if(this->GetDocument()->p->isok())
	    this->GetDocument()->p->drawlastpart(pDC, m_bitmap);

}

//�Ʋ���������
void CPuzzleView::stepstyle()
{
	m_static2.SubclassDlgItem(IDC_STEP,this);

    LOGFONT   log; 
    GetObject(::GetStockObject(DEFAULT_GUI_FONT),sizeof(log),&log); 
    log.lfHeight=22;     //�� 
    log.lfWidth=10;       //�� 
    log.lfCharSet=GB2312_CHARSET; 
    lstrcpy(log.lfFaceName, _T("���Ĳ���")); 
    font.CreateFontIndirect(&log); 
    m_static2.SetFont(&font); 
}

//��ʱ���趨
void CPuzzleView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_timecontrol.SubclassDlgItem(IDC_STATICTIME,this);

    LOGFONT   log; 
    GetObject(::GetStockObject(DEFAULT_GUI_FONT),sizeof(log),&log); 
    log.lfHeight=22;     
    log.lfWidth=10;       
    log.lfCharSet=GB2312_CHARSET; 
    lstrcpy(log.lfFaceName, _T("���Ĳ���")); 
    font.CreateFontIndirect(&log); 
    m_timecontrol.SetFont(&font); 

	CString strTime;
	strTime.Format("%d ��",++m_time);
	this->m_mtime=strTime;
	UpdateData(FALSE);

	CFormView::OnTimer(nIDEvent);
}

//////////////////////��갴����Ӧ��ִ��//////////////////////////////////////////////////////////

void CPuzzleView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    if(point.x>=mainrect.left&&point.x<=mainrect.right&&point.y>=mainrect.top&&point.y<=mainrect.bottom&&!flag) 
	{
	    if(this->GetDocument()->p->click(point,m_bitmap)) //��ƴͼ�����жϿ�ִ���ƶ�ʱ
		{
	    PlaySound(MAKEINTRESOURCE(WAV), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC); 
	    if(!m_Timer)
		{
	        this->SetTimer(1,1000,NULL);//���ö�ʱ��
	        this->m_Timer=true;
		}
	    stepstyle();
	    ++(this->m_step);
	    CString strStep;
	    strStep.Format("%d ��",this->m_step);
	    this->m_mstep=strStep;
	    UpdateData(FALSE);
		}
	    this->InvalidateRect(&mainrect);
	}
	if(this->GetDocument()->p->isok()&&!flag)  //ÿ�β�������ж��Ƿ�ƴ��
	{
	    this->KillTimer(1);
		PlaySound(MAKEINTRESOURCE(WAVEND), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC); 
		EndDlg end;
	    end.DoModal();
	}
	CFormView::OnLButtonUp(nFlags, point);
}

//////////////////////�Զ�ƴ��////////////////////////////////////////////////////////////

//��ʱ��
void CPuzzleView::MySleep(DWORD nMilliseconds)
{
	HANDLE hTimer = CreateWaitableTimer(NULL, FALSE, NULL);
	LARGE_INTEGER liDuring;
	liDuring.QuadPart = - (__int64)nMilliseconds * 10000; //��λ��100����

	if (hTimer == NULL)
		RaiseException(EXCEPTION_INVALID_HANDLE, 0, 0, 0);

	SetWaitableTimer(hTimer, &liDuring, 0, 0, 0, 0);

	for(;;) {
		DWORD dwRet = MsgWaitForMultipleObjects(1, &hTimer, FALSE, INFINITE, QS_ALLEVENTS);
		if (dwRet == WAIT_OBJECT_0)
			break;
		else if (dwRet == WAIT_OBJECT_0 + 1) {
			MSG msg;
			while(PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE) != 0) {
				if (AfxGetThread()->PumpMessage() == 0) {
					AfxPostQuitMessage(0);
					break;
				}
			}
		}
	}

	CloseHandle(hTimer);
}

//�Զ�ƴ�ù���
void CPuzzleView::OnAotuplayer() 
{
	// TODO: Add your command handler code here
	this->timereset();
	this->stepreset();
	int stepnum = this->GetDocument()->p->autoplayanswer();  //�����㷨
		if(!m_Timer)
	{
	this->SetTimer(1,1000,NULL);//���ö�ʱ��
	this->m_Timer=true;
	}
	int s=0;
	for(s = 0;s<stepnum;s++)
	{
		switch(this->GetDocument()->p->step[s])
		{
		    case 0 : this->GetDocument()->p->move(0);break;
		    case 1 : this->GetDocument()->p->move(1);break;
		    case 2 : this->GetDocument()->p->move(2);break;
		    case 3 : this->GetDocument()->p->move(3);break;
		}
		stepstyle();
		++(this->m_step);
	    CString strStep;
	    strStep.Format("%d ��",this->m_step);
	    this->m_mstep=strStep;
    	UpdateData(FALSE);
		MySleep(300);  //������ʱ��ģ�飬��λΪ����
	    this->InvalidateRect(&mainrect); 
	}
		if(this->GetDocument()->p->isok())
		this->KillTimer(1);
}


///////////////////////////////��ʼ������////////////////////////////////////////////////////////////
//ƴͼ�����ʼ��
void CPuzzleView::reset()
{
		PlaySound(MAKEINTRESOURCE(WAVRESET), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC); 
	flag = false;
	int i;
	if(this->GetDocument()->p==this->GetDocument()->p1)
        i=1;
    if(this->GetDocument()->p==this->GetDocument()->p2)
		i=2;
	if(this->GetDocument()->p==this->GetDocument()->p3)
		i=3;
	switch(i)
	{
	case 1:delete[] this->GetDocument()->p1;this->GetDocument()->p1=new P(3);this->GetDocument()->p=this->GetDocument()->p1;break;
    case 2:delete[] this->GetDocument()->p2;this->GetDocument()->p2=new P(4);this->GetDocument()->p=this->GetDocument()->p2;break;
	case 3:delete[] this->GetDocument()->p3;this->GetDocument()->p3=new P(5);this->GetDocument()->p=this->GetDocument()->p3;break;
	}
}

//�Ʋ�����ʼ��
void CPuzzleView::stepreset()
{
	this->m_step=0;
	CString strStep;
	strStep.Format("%d ��",0);
	this->m_mstep=strStep;
	UpdateData(FALSE);
}

//��ʱ����ʼ��
void CPuzzleView::timereset()
{
	//////////////////////////���¿�ʼʱ��Ҫ�ĳ�ʼ��
	m_timecontrol.SubclassDlgItem(IDC_STATICTIME,this);

    LOGFONT   log; 
    GetObject(::GetStockObject(DEFAULT_GUI_FONT),sizeof(log),&log); 
    log.lfHeight=22;     
    log.lfWidth=10;       
    log.lfCharSet=GB2312_CHARSET; 
    lstrcpy(log.lfFaceName, _T("���Ĳ���")); 
    font.CreateFontIndirect(&log); 
    m_timecontrol.SetFont(&font); 
	this->m_Timer=false;
	this->KillTimer(1);
	this->m_time=0;
	CString strTime;
	strTime.Format("%d ��",0);
	this->m_mtime=strTime;
	UpdateData(FALSE);
}

//����ͳ�ʼ��
void CPuzzleView::random()
{
		PlaySound(MAKEINTRESOURCE(WAVRESET), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC); 
	flag = false;
	srand(time(NULL));

	int rlevel = rand()%3+1;	
	switch(rlevel)
	{
	case 1:delete[] this->GetDocument()->p1;this->GetDocument()->p1=new P(3);this->GetDocument()->p=this->GetDocument()->p1;break;
    case 2:delete[] this->GetDocument()->p2;this->GetDocument()->p2=new P(4);this->GetDocument()->p=this->GetDocument()->p2;break;
	case 3:delete[] this->GetDocument()->p3;this->GetDocument()->p3=new P(5);this->GetDocument()->p=this->GetDocument()->p3;break;
	}
	
	int rpic = rand()%6+1;
	switch(rpic)
	{
	case 1:m_bitmap->DeleteObject();m_bitmap->LoadBitmap(IDB_BITMAP1);break;
    case 2:m_bitmap->DeleteObject();m_bitmap->LoadBitmap(IDB_BITMAP2);break;
	case 3:m_bitmap->DeleteObject();m_bitmap->LoadBitmap(IDB_BITMAP3);break;
	case 4:m_bitmap->DeleteObject();m_bitmap->LoadBitmap(IDB_BITMAP4);break;
	case 5:m_bitmap->DeleteObject();m_bitmap->LoadBitmap(IDB_BITMAP5);break;
	case 6:m_bitmap->DeleteObject();m_bitmap->LoadBitmap(IDB_BITMAP6);break;
	}
}

//�����ʼ
void CPuzzleView::OnQuickstart() 
{
	// TODO: Add your command handler code here
	this->random();
	this->timereset();
	this->stepreset();
	this->Invalidate();
}

//////////////////////////////////////////ѡ�����//////////////////////////////////
void CPuzzleView::OnEasy() 
{
	// TODO: Add your command handler code here
	this->reset();
	this->GetDocument()->p=this->GetDocument()->p1;
		this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}

void CPuzzleView::OnMd() 
{
	// TODO: Add your command handler code here
	this->reset();
	this->GetDocument()->p=this->GetDocument()->p2;
		this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
	
}

void CPuzzleView::OnHard() 
{
	// TODO: Add your command handler code here
	this->reset();
	this->GetDocument()->p=this->GetDocument()->p3;
		this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
	
}

void CPuzzleView::OnFreeLevel() 
{
	// TODO: Add your command handler code here
	FreeLevelDlg cin;
	cin.DoModal();
}

void CPuzzleView::freelevel(int level)
{
		PlaySound(MAKEINTRESOURCE(WAVRESET), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC); 
	delete GetDocument()->pfree;
	this->GetDocument()->pfree=new P(level);
    this->GetDocument()->p=this->GetDocument()->pfree;
		this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}

/////////////////////////������Ӧģ��////////////////////////////////////////////////////////////

BOOL CPuzzleView::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    if(pMsg->message==WM_KEYUP&&!flag)
	{
		if(pMsg->wParam>=37&&pMsg->wParam<=40) //�޶�ֻ�з��������Ӧ
		{
	        if(this->GetDocument()->p->move(pMsg->wParam-37))
			{
			PlaySound(MAKEINTRESOURCE(WAV), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
			    if(!m_Timer)
				{
	              this->SetTimer(1,1000,NULL);//���ö�ʱ��
	              this->m_Timer=true;
				}
			    stepstyle();
			    ++(this->m_step);
	            CString strStep;
	            strStep.Format("%d ��",this->m_step);
	            this->m_mstep=strStep;
	            UpdateData(FALSE);
			}
	        this->InvalidateRect(&mainrect); 
	        if(this->GetDocument()->p->isok()&&!flag)  //ÿ�β�������ж��Ƿ�ƴ��
			{
			this->KillTimer(1);
			PlaySound(MAKEINTRESOURCE(WAVEND), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC); 
			EndDlg end;
	        end.DoModal();
			}
		}
	}
	return CFormView::PreTranslateMessage(pMsg);
}

////////////////////////////////////ѡ��ͼƬ//////////////////////////////////////////
void CPuzzleView::Onpic1()
{
	m_bitmap->DeleteObject();
	m_bitmap->LoadBitmap(IDB_BITMAP1);
	reset();
	this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}

void CPuzzleView::Onpic2()
{
	m_bitmap->DeleteObject();
	m_bitmap->LoadBitmap(IDB_BITMAP2);
	reset();
	this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}


void CPuzzleView::Onpic3()
{
	m_bitmap->DeleteObject();
	m_bitmap->LoadBitmap(IDB_BITMAP3);
	reset();
	this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}


void CPuzzleView::Onpic4()
{
	m_bitmap->DeleteObject();
	m_bitmap->LoadBitmap(IDB_BITMAP4);
	reset();
	this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}


void CPuzzleView::Onpic5()
{
	m_bitmap->DeleteObject();
	m_bitmap->LoadBitmap(IDB_BITMAP6);
	reset();
	this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}

void CPuzzleView::Onpic6()
{
	m_bitmap->DeleteObject();
	m_bitmap->LoadBitmap(IDB_BITMAP5);
	reset();
	this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}

//�Զ���ͼƬ
void CPuzzleView::OnPicOpen() 
{
	// TODO: Add your command handler code here
    CFileDialog dlg(TRUE,NULL,NULL,NULL,"λͼ�ļ�(*.bmp)|*.bmp"); //���öԻ���
	if(dlg.DoModal()==IDOK)
	{
		HBITMAP	hbitmap=(HBITMAP)::LoadImage(NULL,dlg.GetFileName(),IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
		m_bitmap->DeleteObject();
		m_bitmap->Attach(hbitmap);
		reset();
		this->timereset();
	    this-> stepreset();
        this->InvalidateRect(&mainrect);
	}	
}

CScrollBar* CPuzzleView::GetScrollBarCtrl(int nBar) const
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFormView::GetScrollBarCtrl(nBar);
}

//////////////////////////////////////��ť��Ӧ////////////////////////////////////////
void CPuzzleView::OnButtonlookpic() 
{
	// TODO: Add your control notification handler code here
		LookPic *pic=new LookPic();
	pic->Create(IDD_DIALOG3,this);
	pic->ShowWindow(1);
}

void CPuzzleView::OnButtonrestart() 
{
	// TODO: Add your control notification handler code here
	this->reset();
	this->stepstyle();
		this->timereset();
	this-> stepreset();
	this->InvalidateRect(&mainrect);
}
