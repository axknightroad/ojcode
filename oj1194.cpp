#include <stdio.h>

int Dec;
int Otc[6];

int DtoO(int a){
  int len=0;
  while(a){
    Otc[len++]=a%8;
    a/=8;
  }
  return len;
}

int main(){
  while(scanf("%d",&Dec)!=EOF){
    if(!Dec)
      printf("0");
    else{
      int len=DtoO(Dec);
      for(int i=len-1;i>=0;i--)
	printf("%d",Otc[i]);
    }
    printf("\n");
  }
  return 0;
}
