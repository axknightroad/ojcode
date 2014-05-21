#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int inDegree[1000];
vector<int> match[1000];
//queue <int> q;
int out[1000];
bool first;
int start,end;
void init(){
  for(int i=0;i<1000;i++){
    inDegree[i]=0;
    match[i].clear();
    out[i]=0;
  }
  first=true;
  start=0;
  end=0;
  return;
}

void getOut(int n){
  for(int i=1;i<=n;i++)
    if(inDegree[i]==0){
      out[end++]=i;
    }
  stable_sort(out+start,out+end);
  while(start<end){
    sort(out+start,out+end);
      if(first){
	printf("%d",out[start]);
	first=false;
      }
      else{
	printf(" %d",out[start]);
      }      
    for(int i=0;i<match[out[start]].size();i++){
      if(--inDegree[match[out[start]][i]]==0){
	out[end++]=match[out[start]][i];
      }
    }
    start++;
  }
  return;
}

int main(){
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF){
    init();
    int a,b;
    for(int i=0;i<m;i++){
      scanf("%d%d",&a,&b);
      match[a].push_back(b);
      inDegree[b]++;
    }
    getOut(n);
    printf("\n");
  }
  return 0;
}
