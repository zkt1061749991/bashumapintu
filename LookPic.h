#if !defined(AFX_LOOKPIC_H__F75FDC86_58AE_4E77_8D5C_2001919AE849__INCLUDED_)
#define AFX_LOOKPIC_H__F75FDC86_58AE_4E77_8D5C_2001919AE849__INCLUDED_
#include "MainFrm.h"
class CPuzzleView;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LookPic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LookPic dialog

class LookPic : public CDialog
{
// Construction
public:
	LookPic(CWnd* pParent = NULL);   // standard constructor
    
// Dialog Data
	//{{AFX_DATA(LookPic)
	enum { IDD = IDD_DIALOG3 };
	CStatic	m_lookpic;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LookPic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LookPic)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOOKPIC_H__F75FDC86_58AE_4E77_8D5C_2001919AE849__INCLUDED_)
