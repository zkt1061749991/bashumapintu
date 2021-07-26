#if !defined(AFX_SELECTDLG_H__E9AAD51B_6532_4957_BBB3_E609920F53A0__INCLUDED_)
#define AFX_SELECTDLG_H__E9AAD51B_6532_4957_BBB3_E609920F53A0__INCLUDED_
#include "MainFrm.h"
class CPuzzleView;
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SelectDlg dialog

class SelectDlg : public CDialog
{
// Construction
public:
	SelectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SelectDlg)
	enum { IDD = IDD_DIALOG2 };
	//待选择图片
	CStatic	m_pic6;
	CStatic	m_pic5;
	CStatic	m_pic4;
	CStatic	m_pic3;
	CStatic	m_pic2;
	CStatic	m_pic1;
	CBitmapButton Button1; //自绘制按钮必要的位图对象
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SelectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SelectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void drawpic(CStatic * m_pic,int ID);
	afx_msg void OnStaticpic1();
	afx_msg void OnStaticpic4();
	afx_msg void OnStaticpic6();
	afx_msg void OnStaticpic5();
	afx_msg void OnStaticpic3();
	afx_msg void OnStaticpic2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTDLG_H__E9AAD51B_6532_4957_BBB3_E609920F53A0__INCLUDED_)
