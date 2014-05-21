#include <stdio.h>
#include <algorithm>

using namespace std;

int l,n;

bool cmp(int a,int b)
{
  return a>b;
}

int main(){
  while(scanf("%d%d",&l,&n)!=EOF){
    int buf[n];
    for(int i=0;i<n;i++)
      scanf("%d",&buf[i]);
    sort(buf,buf+n,cmp);
    int tmp=0,num=0;
    for(int i=0;i<n;i++)
      {
	tmp=tmp+buf[i];
	if(tmp>=l)
	  {
	    num=i+1;
	    break;
	  }
      }
    if(num)
      printf("%d\n",num);
    else
      printf("impossible\n");	
  }
}
