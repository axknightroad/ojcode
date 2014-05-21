#include <stdio.h>
#include <math.h>

int tree[1001];

int main(){
  int n,m;
  while(scanf("%d",&n)!=EOF){
    for(int i=1;i<=n;i++)
      tree[i]=0;
    for(int i=1;i<=n;i++)
      scanf("%d",&tree[i]);
    scanf("%d",&m);
    int k=pow(2,m-1);
    int flag=0;
    for(int i=k;i<k*2;i++){
      if(i>n) break;
      if(!flag) flag=1;
      else printf(" ");
      printf("%d",tree[i]);
    }
    printf("\n");
  }
  return 0;
}
