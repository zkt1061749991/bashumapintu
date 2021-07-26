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
#define WIDE (500)  //ƴͼ������ܴ�С�������εĿ�ȣ�

#define X (30)  //ƴͼ������ʾλ�ã����ϽǺ����꣩
#define Y (27)  ////ƴͼ������ʾλ�ã����Ͻ������꣩

class P  
{
/////////////////////���ݳ�Ա///////////////////////////////////////////////////////////////
    int N; //����
	enum{LEFT,UP,RIGHT,DOWN};  //{0,1,2,3}
/****************************************************/
	char *a;   //���ĳ�Ա-�ֿ�����   
/****************************************************/
	char ij;   //���б�ʶ��
	int wide;  //����ƴͼ�Ŀ��

public:

	int step[1000];  //�Զ���ʾ�㷨�Ĳ�������
	
//////////////�Էֿ����������Ĺ��캯��/////////////////////////////////////////////////////////
    P(){}

	P(int level)
	{
		this->N=level;
		this->a=new char[N*N];
	    int i,j;
	    for(i=0;i<N*N;++i)//�������ʼ 
	        a[i]=i;
	    int count;
	
	    //��������ұ�֤�н� 
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
	
////////////////////���湦��ʱ����ĺ���//////////////////////////////////////////////////
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
////////////////�����ƶ�����/////////////////////////////////////////////////////////////////

	bool move(int n)
	{
        if(n==LEFT)  //�Ҳ����λ���Ϊ���󡱲��� 
		{
   	      if(ij%N==N-1) return 0;
	      a[ij]=a[ij+1];
	      a[ij+1]=0;
	      ++ij;
		}

        if(n==UP)    //�²����λ���Ϊ���ϡ����� 
		{
   	      if(ij/N==N-1) return 0;
	      a[ij]=a[ij+N];
	      a[ij+N]=0;
	      ij+=N;
		}

        if(n==RIGHT)  //������λ���Ϊ���ҡ����� 
		{
   	      if(ij%N==0) return 0;
	      a[ij]=a[ij-1];
	      a[ij-1]=0;
	      --ij;
		}

        if(n==DOWN)  //�ϲ����λ���Ϊ���¡����� 
		{
   	      if(ij/N==0) return 0;
	      a[ij]=a[ij-N];
	      a[ij-N]=0;
	      ij-=N;
		}
        return 1;
	}

/////////////////////�жϺ���/////////////////////////////////////////////////////////////////

	bool isok() const   //ע��Ҫconst
	{
	    int i;
	    for(i=0;i<N*N-1;i++)
	        if(a[i]!=i+1) return 0;
	 
	    if(a[i]!=0) return 0;  //�ж�a[n-1]�Ƿ�Ϊ0����Ҫ��հ�ͼ��Ϊ���½�
	 
	    return 1;
	}

///////////////////���ƺ���//////////////////////////////////////////////////////////////////
    
	void draw(CDC * pDC,CBitmap * m_bitmap) const  //ע��Ҫconst
	{
		BITMAP m_bmp;  //bmp�ṹ����������ݴ�ͼ����Ϣ
		m_bitmap->GetBitmap(&m_bmp);	 //m_bmp�����Ϣ �ŵ�BITMAP�ṹ����
		int wide;
		if(m_bmp.bmWidth<=m_bmp.bmHeight)
	        wide =  m_bmp.bmWidth/N;   //���ÿ��Ŀ��
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
				pDC->Rectangle(X+j*WIDE/N,Y+i*WIDE/N,X+WIDE/N+j*WIDE/N,Y+WIDE/N+i*WIDE/N);  //�߿�
			CString str;
				if(0!=a[i*N+j])
				{
					c = (a[i*N+j]-1)%N;  //�ֿ������Ӧ��ͼ����һ�������
					r = (a[i*N+j]-1)/N;  //�ֿ������Ӧ��ͼ����һ�������
					
					pDC->StretchBlt (   //���ƶ�Ӧ���ͼ��
					X+j*(WIDE/N),
					Y+i*(WIDE/N),   //�ڴ��ڵ���һ�����
					WIDE/N,
					WIDE/N,
					&puzzle,	
					c*(wide),   //��������ʾ�����εĸߺͿ�
					r*(wide),	
					wide,
					wide,
					SRCCOPY
					);
				}
				
				//str.Format("%d",a[i*N+j]);    //��ŵĻ��ƣ�����ʱע�͵�
				//pDC->TextOut(X+wide/2+j*wide,Y+wide/2+i*wide,str);
			}
		
		
	}

	void drawlastpart(CDC * pDC,CBitmap * m_bitmap) const
	{
		BITMAP m_bmp;  //bmp�ṹ����������ݴ�ͼ����Ϣ
		m_bitmap->GetBitmap(&m_bmp);	 //m_bmp�����Ϣ �ŵ�BITMAP�ṹ����
	    int wide;
		if(m_bmp.bmWidth<=m_bmp.bmHeight)
	        wide =  m_bmp.bmWidth/N;   //���ÿ��Ŀ��
		else
            wide =  m_bmp.bmHeight/N;
	    CDC puzzle;	
	    puzzle.CreateCompatibleDC(pDC);
	    puzzle.SelectObject(m_bitmap);
		pDC->StretchBlt (   //���ƶ�Ӧ���ͼ��

					X+(N-1)*(WIDE/N),
					Y+(N-1)*(WIDE/N),   //�ڴ��ڵ���һ�����
					WIDE/N,
					WIDE/N,
					&puzzle,	
					(N-1)*(wide),   //��������ʾ�����εĸߺͿ�
					(N-1)*(wide),	
					wide,
					wide,
					SRCCOPY
					);

	}

///////////////////��������ж�/////////////////////////////////////////////////////////////
    
	bool click(CPoint point,CBitmap * m_bitmap)
	{
        BITMAP m_bmp;  //bmp�ṹ����������ݴ�ͼ����Ϣ
		m_bitmap->GetBitmap(&m_bmp);	 //m_bmp�����Ϣ �ŵ�BITMAP�ṹ����
	    
		int i,j;
		int n = -1;  //��¼����
	    for(i = 0;i<N;i++)
			for(j = 0;j<N;j++)
			{
			   if(a[i*N+j]!=0) //��������Ϊ0
			   {
			       RECT rc;
				   rc.left = X+j*(WIDE/N);
				   rc.top = Y+i*(WIDE/N);
				   rc.right = X+j*(WIDE/N)+WIDE/N;
				   rc.bottom = Y+i*(WIDE/N)+WIDE/N;

				   if(point.x>=rc.left&&point.x<=rc.right&&point.y>=rc.top&&point.y<=rc.bottom)
				   {
				       if(a[i*N+j+1]==0 && j!=N-1)  //����Ϊ0
					       n = 2; 
					   else if(a[i*N+j-1]==0 && j!=0)  //����Ϊ0
						   n = 0;
					   else	if(a[(i*N+j)+N]==0 && i!=N-1)    //����Ϊ0
						   n = 3;
					   else	if(a[(i*N+j)-N]==0 && i!=0)   //����Ϊ0
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

////////////////////////�Զ�����㷨///////////////////////////////////////////////

    int autoplayanswer()
    {
	    int i;
	    answer a(a);  //��a[]������һ��answe����
        i = a.player(step);  //����ÿ�����߷��򣬲��洢��step������
	    return i;  //�������貽��
    }

};

#endif // !defined(AFX_P_H__A636EC36_0DD9_4D60_903E_F80185C04AE8__INCLUDED_)






















