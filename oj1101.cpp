#include <stdio.h>
#include <stack>
using namespace std;

int rank[5][5]={
  1,0,0,0,0,
  1,0,0,0,0,
  1,0,0,0,0,
  1,1,1,0,0,
  1,1,1,0,0,
};
char buf[1000];

bool op;
float num;
int opRank;

stack<int> opStack;
stack<float> numStack;
 
void getOP(bool &retOp,int &retRank,float &retNum,int &i){
  if(buf[i]=='\0')
    {
      retOp=true;
      retRank=0;
      retNum=-1;
    }
  else if(buf[i]<='9'&&buf[i]>='0')
    {
      retOp=false;
      retRank=-1;
      retNum=buf[i]-'0';
      while(buf[i+1]<='9'&&buf[i+1]>='0')
	{
	  retNum*=10;
	  retNum+=buf[++i]-'0';
	}
    }
  else
    switch(buf[i])
      {
      case '+':
	retOp=true;
	retRank=1;
	retNum=-1;
	break;
      case '-':
	retOp=true;
	retRank=2;
	retNum=-1;
	break;
      case '*':
	retOp=true;
	retRank=3;
	retNum=-1;
	break;
      case '/':
	retOp=true;
	retRank=4;
	retNum=-1;
	break;
      }
  i++;
  return;
}

int main(){
  while(scanf("%s",buf)!=EOF){
    while(!opStack.empty())
      opStack.pop();
    while(!numStack.empty())
      numStack.pop();
    int i=0;
    opStack.push(0);
    while(true)
      {
	getOP(op,opRank,num,i);
	if(!op)
	  numStack.push(num);
	else
	  {
	    while(!rank[opRank][opStack.top()])
	      { 
		float a,b;
		b=numStack.top();
		numStack.pop();
		a=numStack.top();
		numStack.pop();
		switch(opStack.top())
		  {
		  case 1:
		    a+=b;
		    break;
		  case 2:
		    a-=b;
		    break;
		  case 3:
		    a*=b;
		    break;
		  case 4:
		    a/=b;
		    break;
		  }
		numStack.push(a);
		opStack.pop();
	      }
	    opStack.push(opRank);
	  }
	if(opStack.size()==2&&!opStack.top())
	  break;
      }
    int ans=numStack.top();
    printf("%d\n",ans);
  }
  return 0;
}
