#include <stdio.h>

int hash[201]={0};
int m,n;

int main(){
  while(scanf("%d %d",&n,&m)!=EOF)
    {
      for(int i=0;i<201;i++)
	hash[i]=0;
      if(n<2||m>200)
	break;
      int reader[n];
      for(int i=0;i<n;i++)
	{
	  scanf("%d",&reader[i]);
	  if(reader[i]>m||reader[i]<1)
	    return 0;
	  hash[reader[i]]++;
	}
      for(int i=0;i<n;i++)
	{
	  if(hash[reader[i]]-1)
	    printf("%d\n",hash[reader[i]]-1);
	  else
	    printf("BeiJu\n");
	}
    }
  return 0;
}
