#include <stdio.h>
#include <vector>

using namespace std;

struct Edge{
  int next;
  int cost;
};

vector<Edge> edge[1000];

int flag[1000];

struct Road{
  int a,b;
  int cost;
} road[10100];

void init(){
  for(int i=0;i<1000;i++){
    edge[i].clear();
    flag[i]=0;
  }
  for(int i=0;i<10100;i++){
    road[i].a=0;
    road[i].b=0;
    road[i].cost=0;
  }
  return;
}

int dis[1000];
bool mark[1000];

void dijkstra(int n){
  for(int i=1;i<=n;i++){
    dis[i]=-1;
    mark[i]=false;
  }
  int newP=1;
  dis[1]=0;
  mark[1]=true;  
  for(int i=2;i<=n;i++){
    for(int j=0;j<edge[newP].size();j++){
      int next=edge[newP][j].next;
      int cost=edge[newP][j].cost;
      if(mark[next]) continue;
      if(dis[next]==-1||dis[next]>cost+dis[newP])
	dis[next]=cost+dis[newP];
    }
    int min=32000;
    for(int j=2;j<=n;j++){
      if(mark[j]||dis[j]==-1) continue;
      if(dis[j]<min){
	newP=j;
	min=dis[j];
      }
    }
    mark[newP]=true;
  }
  return;
}

void rtoe(int m){
  for(int i=0;i<m;i++){
    int a=road[i].a;
    int b=road[i].b;
    int cost=road[i].cost;
    Edge e;
    e.cost=cost;
    if(flag[a]==flag[b]){
      e.next=a;
      edge[b].push_back(e);
      e.next=b;
      edge[a].push_back(e);
    }
    else if(flag[a]==1){
      e.next=b;
      edge[a].push_back(e);
    }
    else{
      e.next=a;
      edge[b].push_back(e);
    }
  }
  return;
}

int main(){
  int n,m;
  while(scanf("%d",&n)&&n){
    init();
    scanf("%d",&m);
    for(int i=0;i<m;i++)
      scanf("%d%d%d",&road[i].a,&road[i].b,&road[i].cost);
    for(int i=1;i<=n;i++)
      scanf("%d",&flag[i]);
    rtoe(m);
    dijkstra(n);
    printf("%d\n",dis[2]);
  }
  return 0;
}
