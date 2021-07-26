// P.h: interface for the P class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_P_H__A636EC36_0DD9_4D60_903E_F80185C04AE8__INCLUDED_)
#define AFX_P_H__A636EC36_0DD9_4D60_903E_F80185C04AE8__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<algorithm>
#include "answer.h"
#define WIDE (500)  //拼图主体的总大小（正方形的宽度）

#define X (30)  //拼图主体显示位置（左上角横坐标）
#define Y (27)  ////拼图主体显示位置（左上角纵坐标）

class P  
{
/////////////////////数据成员///////////////////////////////////////////////////////////////
    int N; //阶数
	enum{LEFT,UP,RIGHT,DOWN};  //{0,1,2,3}
/****************************************************/
	char *a;   //核心成员-分块数组   
/****************************************************/
	char ij;   //行列标识符
	int wide;  //单块拼图的宽度

public:

	int step[1000];  //自动演示算法的步骤数组
	
//////////////对分块随机化数组的构造函数/////////////////////////////////////////////////////////
    P(){}

	P(int level)
	{
		this->N=level;
		this->a=new char[N*N];
	    int i,j;
	    for(i=0;i<N*N;++i)//按次序初始 
	        a[i]=i;
	    int count;
	
	    //随机打乱且保证有解 
	    do {
	    count=0;
	    srand(time(0));
        std::random_shuffle(a,a+N*N);
	
	    for(i=0;i<N*N-1;++i)
		    for(j=i;j<N*N;++j)
			    if(a[j]&&a[i]>a[j])++count;
		}
	
	    while(count&1);
	        for(i=0;i<N*N;++i)
	            if (!a[i])
				{
		   		    ij=i;
		   	 	    break;
				}	
	}
	
////////////////////储存功能时所需的函数//////////////////////////////////////////////////
    int getN(){
		return N;
	}

	void setN(int n){
		this->N = n;
	}

	char* getA(){
		char* s = new char[N*N];
		memcpy(s, a, N*N);
		return s;
	}

	void setA(char* s){
		memcpy(a, s, N*N);
	}

	void setIJ(char blank){
		ij = blank;
	}
////////////////数组移动操作/////////////////////////////////////////////////////////////////

	bool move(int n)
	{
        if(n==LEFT)  //右侧向空位填充为“左”操作 
		{
   	      if(ij%N==N-1) return 0;
	      a[ij]=a[ij+1];
	      a[ij+1]=0;
	      ++ij;
		}

        if(n==UP)    //下侧向空位填充为“上”操作 
		{
   	      if(ij/N==N-1) return 0;
	      a[ij]=a[ij+N];
	      a[ij+N]=0;
	      ij+=N;
		}

        if(n==RIGHT)  //左侧向空位填充为“右”操作 
		{
   	      if(ij%N==0) return 0;
	      a[ij]=a[ij-1];
	      a[ij-1]=0;
	      --ij;
		}

        if(n==DOWN)  //上侧向空位填充为“下”操作 
		{
   	      if(ij/N==0) return 0;
	      a[ij]=a[ij-N];
	      a[ij-N]=0;
	      ij-=N;
		}
        return 1;
	}

/////////////////////判断函数/////////////////////////////////////////////////////////////////

	bool isok() const   //注意要const
	{
	    int i;
	    for(i=0;i<N*N-1;i++)
	        if(a[i]!=i+1) return 0;
	 
	    if(a[i]!=0) return 0;  //判断a[n-1]是否为0，即要求空白图案为右下角
	 
	    return 1;
	}

///////////////////绘制函数//////////////////////////////////////////////////////////////////
    
	void draw(CDC * pDC,CBitmap * m_bitmap) const  //注意要const
	{
		BITMAP m_bmp;  //bmp结构体对象，用于暂存图像信息
		m_bitmap->GetBitmap(&m_bmp);	 //m_bmp获得信息 放到BITMAP结构体中
		int wide;
		if(m_bmp.bmWidth<=m_bmp.bmHeight)
	        wide =  m_bmp.bmWidth/N;   //获得每块的宽度
		else
            wide =  m_bmp.bmHeight/N;
	    CDC puzzle;	
	    puzzle.CreateCompatibleDC(pDC);
	    puzzle.SelectObject(m_bitmap);
		
		int i,j;
		int c,r;
      

	    for(i = 0;i<N;i++)
			for(j = 0;j<N;j++)
			{
				pDC->Rectangle(X+j*WIDE/N,Y+i*WIDE/N,X+WIDE/N+j*WIDE/N,Y+WIDE/N+i*WIDE/N);  //边框
			CString str;
				if(0!=a[i*N+j])
				{
					c = (a[i*N+j]-1)%N;  //分块数组对应的图像哪一块的列数
					r = (a[i*N+j]-1)/N;  //分块数组对应的图像哪一块的行数
					
					pDC->StretchBlt (   //绘制对应块的图案
					X+j*(WIDE/N),
					Y+i*(WIDE/N),   //在窗口的这一点输出
					WIDE/N,
					WIDE/N,
					&puzzle,	
					c*(wide),   //窗口中显示出矩形的高和宽
					r*(wide),	
					wide,
					wide,
					SRCCOPY
					);
				}
				
				//str.Format("%d",a[i*N+j]);    //标号的绘制，发布时注释掉
				//pDC->TextOut(X+wide/2+j*wide,Y+wide/2+i*wide,str);
			}
		
		
	}

	void drawlastpart(CDC * pDC,CBitmap * m_bitmap) const
	{
		BITMAP m_bmp;  //bmp结构体对象，用于暂存图像信息
		m_bitmap->GetBitmap(&m_bmp);	 //m_bmp获得信息 放到BITMAP结构体中
	    int wide;
		if(m_bmp.bmWidth<=m_bmp.bmHeight)
	        wide =  m_bmp.bmWidth/N;   //获得每块的宽度
		else
            wide =  m_bmp.bmHeight/N;
	    CDC puzzle;	
	    puzzle.CreateCompatibleDC(pDC);
	    puzzle.SelectObject(m_bitmap);
		pDC->StretchBlt (   //绘制对应块的图案

					X+(N-1)*(WIDE/N),
					Y+(N-1)*(WIDE/N),   //在窗口的这一点输出
					WIDE/N,
					WIDE/N,
					&puzzle,	
					(N-1)*(wide),   //窗口中显示出矩形的高和宽
					(N-1)*(wide),	
					wide,
					wide,
					SRCCOPY
					);

	}

///////////////////点击动作判定/////////////////////////////////////////////////////////////
    
	bool click(CPoint point,CBitmap * m_bitmap)
	{
        BITMAP m_bmp;  //bmp结构体对象，用于暂存图像信息
		m_bitmap->GetBitmap(&m_bmp);	 //m_bmp获得信息 放到BITMAP结构体中
	    
		int i,j;
		int n = -1;  //记录方向
	    for(i = 0;i<N;i++)
			for(j = 0;j<N;j++)
			{
			   if(a[i*N+j]!=0) //所点区域不为0
			   {
			       RECT rc;
				   rc.left = X+j*(WIDE/N);
				   rc.top = Y+i*(WIDE/N);
				   rc.right = X+j*(WIDE/N)+WIDE/N;
				   rc.bottom = Y+i*(WIDE/N)+WIDE/N;

				   if(point.x>=rc.left&&point.x<=rc.right&&point.y>=rc.top&&point.y<=rc.bottom)
				   {
				       if(a[i*N+j+1]==0 && j!=N-1)  //区右为0
					       n = 2; 
					   else if(a[i*N+j-1]==0 && j!=0)  //区左为0
						   n = 0;
					   else	if(a[(i*N+j)+N]==0 && i!=N-1)    //区下为0
						   n = 3;
					   else	if(a[(i*N+j)-N]==0 && i!=0)   //区上为0
						   n = 1;
                      if(n==2||n==1||n==0||n==3)
					{
                       this->move(n);
					   return 1;
					}
					   
					}
				}
			
			}
        return 0;
	}

////////////////////////自动完成算法///////////////////////////////////////////////

    int autoplayanswer()
    {
	    int i;
	    answer a(a);  //用a[]来创建一个answe对象
        i = a.player(step);  //计算每步所走方向，并存储在step数组中
	    return i;  //返回所需步数
    }

};

#endif // !defined(AFX_P_H__A636EC36_0DD9_4D60_903E_F80185C04AE8__INCLUDED_)






















