#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > Q;
int n,ans;

int main(){
  while(scanf("%d",&n)&&n){
    ans=0;
    while(!Q.empty())
      Q.pop();
    int tmp;
    for(int i=0;i<n;i++){
      scanf("%d",&tmp);
      Q.push(tmp);
    }
    while(Q.size()!=1){
      int a=Q.top();
      Q.pop();
      int b=Q.top();
      Q.pop();
      a+=b;
      ans+=a;
      Q.push(a);
    }
    printf("%d\n",ans);
  }
  return 0;
}
