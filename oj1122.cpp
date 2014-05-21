#include <stdio.h>
int f[21];
int main(){
  f[1]=1;
  f[2]=2;
  for(int i=3;i<21;i++)
    f[i]=f[i-1]+f[i-2];
  int n;
  while(scanf("%d",&n)!=EOF)
    printf("%d\n",f[n]);
  return 0;
}
