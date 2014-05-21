#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
    {
      int buf[n];
      if(n==1)
	{
	  scanf("%d",&buf[0]);
	  printf("%d\n",buf[0]);
	  printf("%d\n",-1);
	}
      else
	{
	  for(int i=0;i<n;i++)
	    scanf("%d",&buf[i]);
	  sort(buf,buf+n);
	  printf("%d\n",buf[n-1]);
	  for(int i=0;i<n-1;i++)
	    {
	      if(i!=n-2)
		printf("%d ",buf[i]);
	      else
		printf("%d\n",buf[i]);
	    }	  
	}
    }
  return 0;
}
