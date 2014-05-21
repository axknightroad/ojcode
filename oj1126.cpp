#include <stdio.h>

int n,m;
int main(){
  while(scanf("%d",&n)!=EOF)
    {
      int buf[n][80];
      for(int i=0;i<n;i++)
	{
	  scanf("%d",&m);
	  for(int j=0;j<m;j++)
	    scanf("%d",&buf[i][j]);
	  int firstFlag=1;
	  int outFlag=0;
	  for(int j=0;j<m;j++)
	    {
	      if(j==0)
		{
		  if(buf[i][j]!=buf[i][j+1])
		    outFlag=1;
		}
	      else if(j==m-1)
		{
		  if(buf[i][j]!=buf[i][j-1])
		    outFlag=1;
		}
	      else
		{
		  if(buf[i][j]>buf[i][j+1]&&buf[i][j]>buf[i][j-1]||buf[i][j]<buf[i][j+1]&&buf[i][j]<buf[i][j-1])
		    outFlag=1;
		}
	      if(outFlag==1)
		{
		  if(firstFlag==1)
		    firstFlag=0;
		  else 
		    printf(" ");
		  printf("%d",j);
		  outFlag=0;
		}
	    }
	  printf("\n");
	}
    }
  return 0;
}
