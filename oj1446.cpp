#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct tree{
  int root;
  int weight;
  int size;
  char name[5];
  int totalWeight;
  void init(){
    root=-1;
    weight=0;
    size=1;
    totalWeight=0;
    strcpy(name,"000");
    return ;
  }
} ta[2000];

int treeSize=0;

int findTree(char a[]){
  for(int i=0;i<treeSize;i++){
    if(!strcmp(ta[i].name,a))
      return i;
  }
  return treeSize++;
}

int findroot(int x){
  if(ta[x].root==-1)
    return x;
  int tmp=findroot(ta[x].root);  
  ta[x].root=tmp;
  return tmp;
}

char sa[5],sb[5];

struct gang{
  int head;
  int size;
  int root;
  void findHead(){
      head=root;
      for(int j=0;j<treeSize;j++)
	if(findroot(j)==root&&ta[j].weight>ta[head].weight)
	  head=j;
    }
  bool operator < (const gang &A) const{
    int x=strcmp(ta[head].name,ta[A.head].name);
    if(x<0) return true;
    else return false;
  }
} ga[1000];

int gaSize;

void initGang(){
  for(int i=0;i<1000;i++){
    ga[i].size=0;
    ga[i].head=0;
    ga[i].root=0;
  }
  gaSize=0;
  return;
}
int main(){
  int n,k;
  while(scanf("%d%d",&n,&k)!=EOF){
    for(int i=0;i<2000;i++){
      ta[i].init();
    }
    treeSize=0;
    for(int i=0;i<n;i++){
      int temp;
      scanf("%s%s%d",sa,sb,&temp);
      int a=findTree(sa);
      strcpy(ta[a].name,sa);
      int b=findTree(sb);
      strcpy(ta[b].name,sb);
      ta[a].weight+=temp;
      ta[b].weight+=temp;
      a=findroot(a);
      b=findroot(b);
      if(a!=b){
	ta[a].root=b;
	ta[b].size+=ta[a].size;
      }
    }
    for(int i=0;i<treeSize;i++){
      int tmp=findroot(i);
      ta[tmp].totalWeight+=ta[i].weight;
    }
    initGang();
    for(int i=0;i<treeSize;i++){
      if(ta[i].root==-1&&ta[i].size>2&&ta[i].totalWeight>k*2){
	ga[gaSize].root=i;
	ga[gaSize].size=ta[i].size;
	gaSize++;
      }
    }
    for(int i=0;i<gaSize;i++)
      ga[i].findHead();
    sort(ga,ga+gaSize);
    printf("%d\n",gaSize);
    for(int i=0;i<gaSize;i++)
      printf("%s %d\n",ta[ga[i].head].name,ga[i].size);
  }  
  return 0;
}
