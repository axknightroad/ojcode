#include<stdio.h>

int hash[10001];
int l,m,x,y;
int main(){
  while(scanf("%d %d",&l,&m)!=EOF)
    {
      for(int i=0;i<l+1;i++)
	hash[i]=1;
      for(int i=0;i<m;i++)
	{
	  scanf("%d %d",&x,&y);
	  for(int j=x;j<=y;j++)
	    hash[j]=0;
	}
      int n=0;
      for(int i=0;i<l+1;i++)
	{
	  if(hash[i])
	    n++;
	}
      printf("%d\n",n);
    }
  return 0;
}
