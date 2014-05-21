#include <stdio.h>
#include <math.h>

int a,b,k;

int main(){
  while(scanf("%d%d%d",&a,&b,&k)&&(a||b)){
    k=pow(10,k);
    if((a%k+k)%k==(b%k+k)%k)
      printf("%d\n",-1);
    else
      printf("%d\n",a+b);
  }
  return 0;
}
