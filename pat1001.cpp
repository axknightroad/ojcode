#include <stdio.h>

void output(long long a){
  char out[20];
  int size=0;
  if(a==0)
    out[size++]='0';
  bool flag=a>=0?true:false;
  a=a>=0?a:-a;
  int t=0;
  while(a!=0){
    if(t==3){
      out[size++]=',';
      t=0;
    }
    out[size++]=a%10+'0';
    a/=10;
    t++;
  }
  if(!flag)
    printf("-");
  for(int i=size-1;i>=0;i--){
    printf("%c",out[i]);
  }
  printf("\n");
  return;
}

int main(){
  long long a,b;
  while(scanf("%lld%lld",&a,&b)!=EOF)
    output(a+b);
  return 0;
}
