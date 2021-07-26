#if !defined(AFX_WAYSDLG_H__193B39CF_6643_4CD1_90A1_F6498269C344__INCLUDED_)
#define AFX_WAYSDLG_H__193B39CF_6643_4CD1_90A1_F6498269C344__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WaysDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WaysDlg dialog

class WaysDlg : public CDialog
{
// Construction
public:
	WaysDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(WaysDlg)
	enum { IDD = IDD_DIALOG5 };
	CString	m_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WaysDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WaysDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonok();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WAYSDLG_H__193B39CF_6643_4CD1_90A1_F6498269C344__INCLUDED_)
