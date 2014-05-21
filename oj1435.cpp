#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      int m,v,w;
      scanf("%d%d%d",&m,&v,&w);
      int p[m];
      for(int j=0;j<m;j++)
	scanf("%d",&p[j]);
      sort(p,p+m);
      int v0=0;
      float w0=0;
      for(int j=0;j<m;j++)
	{
	  w0=w0+p[j];
	  if(w0/(j+1)>w)
	    {
	      if(j>0)
		{
		  w0=(w0-p[j])/(j*100);
		  v0=j*v;
		}
	      else
		{
		  w0=0.00;
		  v0=0;
		}	  
	      break;
	    }
	  else if(j==m-1)
	    {
	      w0=w0/(m*100);
	      v0=m*v;
	    }
	}
      printf("%d %.2f\n",v0,w0);
    }
  return 0;
}
