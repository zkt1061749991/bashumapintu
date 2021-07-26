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
	CStatic	m_timecontrol;  //时间控制控件
	CString	m_mstep;   //时间显示控件
	CString	m_mtime;  //步数显示控件
	//}}AFX_DATA

// Attributes
public:
	CPuzzleDoc * GetDocument();
	RECT mainrect;  //局部刷新矩形
/********************************************************************************/
	CBitmap * m_bitmap;   //定义图像指针，用于调取资源里的图片
/********************************************************************************/
	int PIC; //值为当前加载图片的ID
/********************************************************************************/
	//预设图片编号表
	int PIC1;
	int PIC2;
	int PIC3;
	int PIC4;
	int PIC5;
	int PIC6;
/********************************************************************************/
	//计时器计步器变量
    bool m_Timer;
	int m_time;
	int m_step;
/********************************************************************************/
	//音效编号表
	int WAV;
	int WAVEND;
	int WAVRESET;
/********************************************************************************/
	bool flag; //用于判断完成对话框是否继续弹出

	CFont font;  //显示字体必要的对象

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
	void timereset();//时间初始化
	void stepreset();//步数初始化
	void stepstyle();//步数样式设置

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
	static void MySleep(DWORD nMilliseconds);  //延时器函数声明
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
