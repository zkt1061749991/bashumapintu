// PuzzleView.h : interface of the CPuzzleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUZZLEVIEW_H__C47A5EF7_A561_4621_9F18_6DE1CD416F92__INCLUDED_)
#define AFX_PUZZLEVIEW_H__C47A5EF7_A561_4621_9F18_6DE1CD416F92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"

class CPuzzleView : public CFormView
{
	
protected: // create from serialization only
	CPuzzleView();
	DECLARE_DYNCREATE(CPuzzleView)
    
public:
	//{{AFX_DATA(CPuzzleView)
	enum { IDD = IDD_PUZZLE_FORM };
	CStatic	m_static2;
	CStatic	m_timecontrol;  //ʱ����ƿؼ�
	CString	m_mstep;   //ʱ����ʾ�ؼ�
	CString	m_mtime;  //������ʾ�ؼ�
	//}}AFX_DATA

// Attributes
public:
	CPuzzleDoc * GetDocument();
	RECT mainrect;  //�ֲ�ˢ�¾���
/********************************************************************************/
	CBitmap * m_bitmap;   //����ͼ��ָ�룬���ڵ�ȡ��Դ���ͼƬ
/********************************************************************************/
	int PIC; //ֵΪ��ǰ����ͼƬ��ID
/********************************************************************************/
	//Ԥ��ͼƬ��ű�
	int PIC1;
	int PIC2;
	int PIC3;
	int PIC4;
	int PIC5;
	int PIC6;
/********************************************************************************/
	//��ʱ���Ʋ�������
    bool m_Timer;
	int m_time;
	int m_step;
/********************************************************************************/
	//��Ч��ű�
	int WAV;
	int WAVEND;
	int WAVRESET;
/********************************************************************************/
	bool flag; //�����ж���ɶԻ����Ƿ��������

	CFont font;  //��ʾ�����Ҫ�Ķ���

// Operations
public:
    void freelevel(int level); 
	void selectpic(int num);

	void Onpic1();
	void Onpic2();
	void Onpic3();
	void Onpic4();
	void Onpic5();
	void Onpic6();

	void reset();
	void random();
	void timereset();//ʱ���ʼ��
	void stepreset();//������ʼ��
	void stepstyle();//������ʽ����

	CBitmapButton Button1;
	CBitmapButton Button2;
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzleView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPuzzleView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	
	
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPuzzleView)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEasy();
	afx_msg void OnMd();
	afx_msg void OnHard();
	afx_msg void OnQuickstart();
	afx_msg void OnFreeLevel();
	afx_msg void OnAotuplayer();
	afx_msg void OnPicOpen();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtonlookpic();
	afx_msg void OnButtonrestart();
	//}}AFX_MSG
/***********************************************************************************/
	static void MySleep(DWORD nMilliseconds);  //��ʱ����������
/***********************************************************************************/

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PuzzleView.cpp
inline CPuzzleDoc* CPuzzleView::GetDocument()
   { return (CPuzzleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZLEVIEW_H__C47A5EF7_A561_4621_9F18_6DE1CD416F92__INCLUDED_)
