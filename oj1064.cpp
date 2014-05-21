#include <stdio.h>

int oldnum[4],newnum[4];

bool isRevOrder(int a){
  int b=a;
  for(int i=0;i<4;i++){
    oldnum[i]=b%10;
    b/=10;
  }    
  b=a*9;
  for(int i=0;i<4;i++){
    newnum[3-i]=b%10;
    b/=10;
  }
  for(int i=0;i<4;i++){
    if(newnum[i]!=oldnum[i])
      return false;
  }
  return true;
}

int main(){
  for(int i=1000;i<1111;i++){
    if(isRevOrder(i))
      printf("%d\n",i);
  }
  return 0;
}
