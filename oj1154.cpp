#include <stdio.h>
#include <algorithm>
using namespace std;

int tree[26];

void treeInit(){
  for(int i=0;i<26;i++)
    tree[i]=-1;
  return;
}

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
  void init(){
    a=-1;
    b=-1;
    cost=1000;
  }
  bool operator < (const Edge &A) const{
    return cost<A.cost;
  }
} edge[100];

int main(){
  int n;
  while(scanf("%d",&n)&&n){
    treeInit();
    for(int i=0;i<100;i++)
      edge[i].init();
    int edgeSize=0;
    for(int i=0;i<n-1;i++){
      char start[3],end[3];
      int a,b,k,cost;
      scanf("%s%d",start,&k);
      a=start[0]-'A';
      for(int j=0;j<k;j++){
	scanf("%s%d",end,&cost);
	b=end[0]-'A';
	edge[edgeSize].a=a;
	edge[edgeSize].b=b;
	edge[edgeSize++].cost=cost;
      }	
    }
    sort(edge,edge+edgeSize);
    int ans=0;
    for(int i=0;i<edgeSize;i++){
      int a=findRoot(edge[i].a);
      int b=findRoot(edge[i].b);
      if(a!=b){
	ans+=edge[i].cost;
	tree[a]=b;
      }	
    }
    printf("%d\n",ans);
  }
  return 0;
}
