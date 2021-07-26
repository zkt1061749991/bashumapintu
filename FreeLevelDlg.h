#if !defined(AFX_FREELEVELDLG_H__8DF4325B_9F07_44D9_94B5_BF9B3698A5DE__INCLUDED_)
#define AFX_FREELEVELDLG_H__8DF4325B_9F07_44D9_94B5_BF9B3698A5DE__INCLUDED_
#include "MainFrm.h"
class CPuzzleView;
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FreeLevelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// FreeLevelDlg dialog

class FreeLevelDlg : public CDialog
{
// Construction
public:
	FreeLevelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(FreeLevelDlg)
	enum { IDD = IDD_DIALOG4 };
	int		m_freelevel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(FreeLevelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(FreeLevelDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FREELEVELDLG_H__8DF4325B_9F07_44D9_94B5_BF9B3698A5DE__INCLUDED_)
