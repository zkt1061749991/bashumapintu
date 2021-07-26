// answer.h: interface for the answer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANSWER_H__1C27E6F0_AC22_4925_B75D_0D1A19A870AD__INCLUDED_)
#define AFX_ANSWER_H__1C27E6F0_AC22_4925_B75D_0D1A19A870AD__INCLUDED_
#include <cstdio>
#include <cstdlib>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <set>
#define NUM3 (3)
using namespace std;
//////////////////////////////////算法类：由算法负责人提供////////////////////////////////////////////
class answer  
{
public:
	enum {LEFT,UP,RIGHT,DOWN};
	char a[NUM3*NUM3];
	char ij;

	answer(){}

	answer(char *s){
		memcpy(a,s,NUM3*NUM3);
		for(int i=0;i<NUM3*NUM3;++i)
	       if (!a[i])
		   {
		   		ij=i;
		   		break;
		   }
	}

bool move(answer *g, int n)
{
   if(n==LEFT)//右侧向空位填充为“左”操作 
   {
   	  if(g->ij%NUM3==NUM3-1) return 0;
	  g->a[g->ij]=g->a[g->ij+1];
	  g->a[g->ij+1]=0;
	  ++g->ij;
   }
   if(n==UP)//下侧向空位填充为“上”操作 
   {
   	  if(g->ij/NUM3==NUM3-1) return 0;
	  g->a[g->ij]=g->a[g->ij+NUM3];
	  g->a[g->ij+NUM3]=0;
	  g->ij+=NUM3;
   }
   if(n==RIGHT)//左侧向空位填充为“右”操作 
   {
   	  if(g->ij%NUM3==0) return 0;
	  g->a[g->ij]=g->a[g->ij-1];
	  g->a[g->ij-1]=0;
	  --g->ij;
   }
    if(n==DOWN)//上侧向空位填充为“下”操作 
   {
   	  if(g->ij/NUM3==0) return 0;
	  g->a[g->ij]=g->a[g->ij-NUM3];
	  g->a[g->ij-NUM3]=0;
	  g->ij-=NUM3;
   }
   return 1;
}

/***********************************************************************/
//////////////////判断类应与实现程序中的保持一致/////////////////////////
bool isok(const answer* g)
{
	int i;
	 for(i=0;i<NUM3*NUM3-1;i++)
	 
	        if(
				g->a[i]!=i+1) return 0;
	 
			if(g->a[i]!=0) return 0;
	 
	 return 1;
}
/***********************************************************************/
	struct State
{
	char a[NUM3*NUM3];
	State(const char* s)
	{
		memcpy(a,s,NUM3*NUM3);
	}
	bool operator<(const State& other)const
	{
		return memcmp(a,other.a,NUM3*NUM3)<0;
	}
};

int player(int * step) //标准广搜 
{

	
	int  i,j;

	answer *q=new answer[9*8*7*720];
	int *parent=new int[9*8*7*720];

	int front=0,rear=0;
	set<State> s;
	if(s.insert(a).second&&!isok(this))
	{parent[rear]=-1;q[rear++]=*this;}
	else 
		return 0;
	while(front<rear)
	{
		answer tmp;
		for(i=0;i<4;++i)
		{   tmp=q[front];
            if(move(&tmp,i)&&s.insert(tmp.a).second)
			{parent[rear]=front;q[rear++]=tmp;}	
			if(isok(&tmp)) goto L;
		}
		++front;
	}
	char t[1000];	
L:  --rear;
	i=0;
    while(rear)
	{
		switch(q[rear].ij-q[parent[rear]].ij)
		{
		   case 1:t[i]=0;break;
		   case NUM3:t[i]=1;break;
		   case -1:t[i]=2;break;
		   case -NUM3:t[i]=3;break;
		}
		rear=parent[rear];
		i++;
	}
	i;
	for(j=0;j<i;j++)
		step[j]=t[i-j-1];
	delete[]q;
	delete[]parent;
	return i;
}

};

#endif // !defined(AFX_ANSWER_H__1C27E6F0_AC22_4925_B75D_0D1A19A870AD__INCLUDED_)
