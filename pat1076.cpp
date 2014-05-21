#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

vector<int> edge[1010];
struct E{
  int id;
  int level;
};
queue<E>  q;
bool mark[1010];
void init(){
  for(int i=0;i<1010;i++)
    edge[i].clear();
  return;
}
void bfsInit(){
  memset(mark,0,1010*sizeof(bool));
 while(!q.empty())
   q.pop();
}

int bfs(int start,int l){
  bfsInit();
  int ret=0;
  E tmp;
  mark[start]=true;
  for(int i=0;i<edge[start].size();i++){
    tmp.id=edge[start][i];
    tmp.level=1;
    q.push(tmp);
    mark[tmp.id]=true;
    ret++;
  }
  while(!q.empty()){
    tmp=q.front();
    q.pop();
    int nowId=tmp.id;
    int nowL=tmp.level;
    if(nowL==l)
      break;      
    for(int i=0;i<edge[nowId].size();i++){
      tmp.id=edge[nowId][i];
      tmp.level=nowL+1;
      if(!mark[tmp.id]){
	q.push(tmp);
	ret++;
	mark[tmp.id]=true;
      }
    }      
  } 
  return ret;
}

int main(){
  int n,l;
  while(scanf("%d%d",&n,&l)!=EOF){
    init();
    for(int i=1;i<=n;i++){
      int size;
      scanf("%d",&size);
      for(int j=0;j<size;j++){
	int f;
	scanf("%d",&f);
	edge[f].push_back(i);
      }
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){     
      int start;
      scanf("%d",&start);
      int ans=bfs(start,l);
      printf("%d\n",ans);
    }
  }
  return 0;
}
