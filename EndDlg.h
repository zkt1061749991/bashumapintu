#if !defined(AFX_ENDDLG_H__A72EDF81_1E6D_4B07_A41D_8DBF1E033EEB__INCLUDED_)
#define AFX_ENDDLG_H__A72EDF81_1E6D_4B07_A41D_8DBF1E033EEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EndDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// EndDlg dialog

class EndDlg : public CDialog
{
// Construction
public:
	EndDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(EndDlg)
	enum { IDD = IDD_DIALOG1 };
	
	CString	m_Text;
	CString	m_end;
    CFont   font;  //×ÖÌå¶ÔÏó
	CStatic	m_static;

	CBitmapButton Button1;
	CBitmapButton Button2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(EndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(EndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonplayagain();
	afx_msg void OnButtonunplay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENDDLG_H__A72EDF81_1E6D_4B07_A41D_8DBF1E033EEB__INCLUDED_)
