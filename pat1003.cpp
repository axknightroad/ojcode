#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x7FFFFFFF

struct E{
  int next;
  int len;
};

vector<E> edge[600];
int team[600],maxTeam[600],roadNum[600],dis[600]; 
bool mark[600];
int s,e,m,n;
void init(){
  for(int i=0;i<600;i++){
    team[i]=0;
    maxTeam[i]=0;
    edge[i].clear();
    mark[i]=false;
    roadNum[i]=0;
    dis[i]=-1;
  }
  return;
}

void dij(){
  mark[s]=true;
  dis[s]=0;
  roadNum[s]=1;
  maxTeam[s]=team[s];
  int now=s;
  for(int i=1;i<n;i++){
    for(int j=0;j<edge[now].size();j++){
      E tmp;
      tmp=edge[now][j];
      int next=tmp.next;
      int len=tmp.len;
      if(mark[next]) continue;
      if(dis[next]==-1||dis[next]>len+dis[now]){
	dis[next]=len+dis[now];
	maxTeam[next]=maxTeam[now]+team[next];
	roadNum[next]=roadNum[now];
      }
      else if(dis[next]==len+dis[now]){
	roadNum[next]+=roadNum[now];
	if(maxTeam[next]<maxTeam[now]+team[next])
	  maxTeam[next]=maxTeam[now]+team[next];
      }
    }
    int min=INF;
    for(int j=0;j<n;j++){
      if(mark[j]||dis[j]==-1) continue;
      if(dis[j]<min) { min=dis[j]; now=j;}
    }
    mark[now]=true;
    //if(now==e)  break;
  }
  return;
}

int main(){
  while(scanf("%d%d%d%d",&n,&m,&s,&e)!=EOF){
    init();
    for(int i=0;i<n;i++)
      scanf("%d",&team[i]);
    for(int i=0;i<m;i++){
      int a,b,len;
      scanf("%d%d%d",&a,&b,&len);
      E tmp;
      tmp.len=len;
      tmp.next=a;
      edge[b].push_back(tmp);
      tmp.next=b;
      edge[a].push_back(tmp);
    }
    dij();
    printf("%d %d\n",roadNum[e],maxTeam[e]);
  }
  return 0;
}
