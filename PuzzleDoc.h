// PuzzleDoc.h : interface of the CPuzzleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUZZLEDOC_H__9C4D00F6_3C22_4071_B9DB_C6B34C940464__INCLUDED_)
#define AFX_PUZZLEDOC_H__9C4D00F6_3C22_4071_B9DB_C6B34C940464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P.h"

class CPuzzleDoc : public CDocument
{
protected: // create from serialization only
	CPuzzleDoc();
	DECLARE_DYNCREATE(CPuzzleDoc)

// Attributes
public:
/********************************************************************************/
	//拼图类的对象指针
	P *p1;  //简单
	P *p2;  //中等
	P *p3;  //困难
	P *pfree;  //自定义
	P *p;  //指向当前对象的指针
/********************************************************************************/
	// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPuzzleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPuzzleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPuzzleDoc)
	afx_msg void OnFileSave();
	afx_msg void OnFileKeepPlaying();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PUZZLEDOC_H__9C4D00F6_3C22_4071_B9DB_C6B34C940464__INCLUDED_)
