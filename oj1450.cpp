#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

struct Player{
  char name[100];
} player[2000];

vector<int> edge[2000];
queue<int> q;
int inDegree[2000];
int size;

int ctop(const char *a){
  for(int i=0;i<size;i++)
    if(strcmp(player[i].name,a)==0)
      return i;
  strcpy(player[size].name,a);
  return size++;
}

void init(){
  for(int i=0;i<2000;i++){
    strcpy(player[i].name,"\0");
    edge[i].clear();
    inDegree[i]=0;
  }
  while(!q.empty()) q.pop();
  size=0;
  return;
}

bool ouput(int n){
  int ret=0;
  for(int i=0;i<n;i++){
    if(inDegree[i]==0){
      q.push(i);
      break;
    }
  }
  while(!q.empty()){
    int now=q.front();
    q.pop();
    ret++;
    for(int i=0;i<edge[now].size();i++){
      int tmp=edge[now][i];
      if(--inDegree[tmp]==0)
	q.push(tmp);
    }      
  }
  if(ret==n)
    return true;
  else
    return false;
}

int main(){
  int n;
  while(scanf("%d",&n)&&n){
    init();
    char sa[100],sb[100];
    for(int i=0;i<n;i++){
      int a,b;
      scanf("%s%s",sa,sb);
      a=ctop(sa);
      b=ctop(sb);
      edge[a].push_back(b);
      inDegree[b]++;
    }
    if(ouput(size))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
