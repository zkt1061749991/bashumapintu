// PuzzleDoc.cpp : implementation of the CPuzzleDoc class
//

#include "stdafx.h"
#include "Puzzle.h"

#include "PuzzleDoc.h"
#include <fstream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPuzzleDoc

IMPLEMENT_DYNCREATE(CPuzzleDoc, CDocument)

BEGIN_MESSAGE_MAP(CPuzzleDoc, CDocument)
	//{{AFX_MSG_MAP(CPuzzleDoc)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_KEEP_PLAYING, OnFileKeepPlaying)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPuzzleDoc construction/destruction

CPuzzleDoc::CPuzzleDoc()
{
	// TODO: add one-time construction code here
//初始化对象指针
	this->p1=new P(3);
	this->p2=new P(4);
	this->p3=new P(5);
	this->pfree=new P(6);
	this->p=p1;
}

CPuzzleDoc::~CPuzzleDoc()
{
}

BOOL CPuzzleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPuzzleDoc serialization

void CPuzzleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPuzzleDoc diagnostics

#ifdef _DEBUG
void CPuzzleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPuzzleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPuzzleDoc commands

/////////////////////////////////////存档保存////////////////////////////////////
void CPuzzleDoc::OnFileSave() 
{
	// TODO: Add your command handler code here
	int n = p->getN();
	if (3 == n){
		char* currentMap = p->getA();

        ofstream out("PuzzleSave.txt");

        for (int j = 0; j < n*n; ++j){
		    out <<currentMap[j]<<endl;
		}

	    out.close();
	    
		delete [] currentMap;
		AfxMessageBox("已保存当前进度");
	}
	else
		AfxMessageBox("只能保存三阶拼图");
}

//////////////////////////////////////////存档读取///////////////////////////////////
void CPuzzleDoc::OnFileKeepPlaying() 
{
	// TODO: Add your command handler code here
	int n = p->getN();
	if (3 == n){

		ifstream in("PuzzleSave.txt");

        char* lastMap = new char[n*n];

	    for (int j = 0; j < 9; ++j){
		   in >> lastMap[j];
		}
	    p->setA(lastMap);
	    int IJ;
	    for(int i=0;i<9;++i){
		   if (!lastMap[i]){
			  IJ = i;
			  break;
		   }
		}
	    p->setIJ(IJ);

	    in.close();
	    delete [] lastMap;
		AfxMessageBox("已读取当前进度，点击拼图任意位置刷新");
	}
	else
		AfxMessageBox("非三阶拼图，读取失败");

}
