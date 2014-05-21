#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;
int n,num;
char op;


int main(){
  while(scanf("%d",&n)&&n)
    {
      while(!s.empty())
	s.pop();
      for(int i=0;i<n;i++)
	{
	  while(getchar()!='\n');
	  scanf("%c",&op);
	  switch(op)
	    {
	    case 'P':
	      scanf("%d",&num);
	      s.push(num);
	      break;
	    case 'O':
	      if(!s.empty())
		s.pop();
	      break;
	    case 'A':
	      if(!s.empty()){
		int tmp=s.top();
		printf("%d\n",tmp);
	      }
	      else
		printf("E\n");
	    }
	}
      printf("\n");
    }
  return 0;
}
