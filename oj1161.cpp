#include <stdio.h>
#include <string.h>

char buf[2][3001][3001];
int n,q;

int main(){
  while(scanf("%d",&n)&&n)
    {
      char tmp[n][n];
      getchar();
      for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	    scanf("%c",&tmp[i][j]);
	  getchar();
	}
      scanf("%d",&q);
      int x=n;
      for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	  buf[0][i][j]=tmp[i][j];
      for(int i=1;i<q;i++)
	{
	  x=x*n;
	  for(int j=0;j<n;j++)
	    for(int k=0;k<n;k++)
	      {
		if(tmp[j][k]==' ')
		  for(int a=x*j/n;a<x*(j+1)/n;a++)
		    for(int b=x*k/n;b<x*(k+1)/n;b++)
		      buf[1][a][b]=' ';
		else
		  for(int a=x*j/n,a0=0;a<x*(j+1)/n;a++,a0++)
		    for(int b=x*k/n,b0=0;b<x*(k+1)/n;b++,b0++)
		      buf[1][a][b]=buf[0][a0][b0];		      
	      }
	  for(int j=0;j<x;j++)
	    for(int k=0;k<x;k++)
	      buf[0][j][k]=buf[1][j][k];
	}
      for(int i=0;i<x;i++)
	{
	  for(int j=0;j<x;j++)
	    printf("%c",buf[0][i][j]);
	  printf("\n");
	}
    }
  return 0;
}
