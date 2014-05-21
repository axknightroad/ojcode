#include <stdio.h>
double hash[1010];
void init(){
  for(int i=0;i<15;i++)
    hash[i]=0;
}

void output(){
  int size=0;
  int max=0;
  for(int i=0;i<1010;i++)
    if(hash[i]!=0){
      size++;
      max=i;
    }
  printf("%d",size);
  for(int i=max;i>=0;i--){
    if(hash[i]==0) continue;
    printf(" %d %.1f",i,hash[i]);
  }
  printf("\n");
}

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    init();
    for(int i=0;i<n;i++){
      int e;
      double c;
      scanf("%d%lf",&e,&c);
      hash[e]+=c;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      int e;
      double c;
      scanf("%d%lf",&e,&c);
      hash[e]+=c;
    }
    output();
  }
  return 0;
}
