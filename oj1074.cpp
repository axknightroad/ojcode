#include <stdio.h>

bool isSym(int a){
  int i=0;
  int b=a*a;
  int c[5]={0};
  while(b!=0){
    c[i++]=b%10;
    b/=10;
  }
  for(int j=0;j<i;j++){
    if(c[j]!=c[i-j-1])
      return false;
  }
  return true;
}

int main(){
  for(int i=0;i<256;i++)
    if(isSym(i))
      printf("%d\n",i);
  return 0;
}
