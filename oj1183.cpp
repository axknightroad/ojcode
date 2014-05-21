#include <stdio.h>
#include <math.h>

int numBit(int a){
  int k=0;
  int tmp=1;
  while(a>=tmp){
    k++;
    tmp*=10;
  }
  return k;
}

bool flag(int a){
  int k=numBit(a);
  int b=a*a;
  k=pow(10,k);
  if((b%k+k)%k==a)
    return true;
  else
    return false;  
}



int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    if(flag(n))  printf("Yes!\n");
    else  printf("No!\n");
    } 
  return 0;
}
