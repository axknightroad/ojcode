#include <stdio.h>
#include <math.h>

int order(int m,int n){
  int tmpr=m*2+1;
  int tmpl=m*2;
  int ans=1;
  int floor=1;
  while(tmpr<=n){
    floor*=2;
    ans+=floor;
    tmpl=tmpl*2;
    tmpr=tmpr*2+1;
  }
  for(;tmpl<=n;tmpl++){
    ans++;
  }
  return ans;
}

int main(){
  int n,m;
  while(scanf("%d%d",&m,&n)&&m&&n){
    int ans=order(m,n);    
    printf("%d\n",ans);
    }
  return 0;
}
