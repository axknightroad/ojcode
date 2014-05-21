#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
  int n,m;
  while(scanf("%d",&n)!=EOF)
    {
      int a[n];
      for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
      sort(a,a+n);
      scanf("%d",&m);
      int b[m];
      for(int i=0;i<m;i++)
	scanf("%d",&b[i]);
      for(int i=0;i<m;i++)
	{
	  int flag=0;
	  int base=0;
	  int top=n-1;
	  while(top>=base)
	    {
	      int mid=(base+top)/2;
	      if(a[mid]==b[i])
		{
		  flag=1;
		  break;
		}
	      else if(a[mid]<b[i])
		base=mid+1;
	      else
		top=mid-1;
	    }
	  if(flag==1)
	    printf("YES\n");
	  else
	    printf("NO\n");	  
	}
    }
  return 0;
}
