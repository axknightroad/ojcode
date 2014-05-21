#include <stdio.h>
#include <algorithm>
using namespace std;

int tree[110];

int findRoot(int x){
  if(tree[x]==-1)
    return x;
  int tmp=findRoot(tree[x]);
  tree[x]=tmp;
  return tmp;
}

struct Edge{
  int a,b;
  int cost;
  bool operator < (const Edge &A) const{
    return cost<A.cost;
  }
} edge[110];

void init(){
  for(int i=0;i<100;i++){
    tree[i]=-1;
    edge[i].a=-1;
    edge[i].b=-1;
    edge[i].cost=10000;
  }
  return;
}


int main(){
  int n,m;
  while(scanf("%d%d",&n,&m)&&n){
    init();
    for(int i=0;i<n;i++)
      scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
    sort(edge,edge+n);
    int ans=0;
    for(int i=0;i<n;i++){
      int a=findRoot(edge[i].a);
      int b=findRoot(edge[i].b);
      if(a!=b){
	ans+=edge[i].cost;
	tree[a]=b;
      }
    }
    bool link=true;
    for(int i=1,root=findRoot(1);i<=m;i++)
      if(findRoot(i)!=root){
	link=false;
	break;
      }
    if(link)
      printf("%d\n",ans);
    else
      printf("?\n");
  }
  return 0;
}
