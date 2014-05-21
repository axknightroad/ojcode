#include <stdio.h>
#include <algorithm>

using namespace std;

int n;

int main()
{
  while(scanf("%d",&n)!=EOF)
    {
      int array[n];
      for(int i=0;i<n;i++)
	  scanf("%d",&array[i]);
      sort(array,array+n);
      for(int i=0;i<n;i++)
	printf("%d ",array[i]);
      printf("\n");
    }
  return 0;
}
