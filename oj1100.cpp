#include <stdio.h>
#include <vector>
using namespace std;

struct BigInt{
  long long digit[100];
  int size;
  void init(){
    for(int i=0;i<100;i++)
      digit[i]=0;
    size=0;
    return;
  }
  void set(long long x){
    digit[0]=x;
    size=1;
    return;
  }
  void mul2(){
    long long carry=0;
    for(int i=0;i<size;i++){
      digit[i]*=2;
      digit[i]+=carry;
      carry=digit[i]/100000;
      digit[i]%=100000;
    }
    if(carry)
      digit[size++]=carry;
    return;
  }
  BigInt operator + (const BigInt &A) const{
    BigInt ret;
    ret.init();
    long long carry=0;
    for(int i=0;i<size||i<A.size;i++){
      ret.digit[i]=digit[i]+A.digit[i]+carry;
      carry=ret.digit[i]/100000;
      ret.digit[ret.size++]%=100000;
    }
    if(carry)
      ret.digit[ret.size++]=carry;
    return ret;
  }
  bool operator < (const BigInt &A) const{
    if(size!=A.size) return size<A.size;
    for(int i=size-1;i>=0;i--)
      if(digit[i]!=A.digit[i])
	return digit[i]<A.digit[i];
    return false;
  }
  void display(){
    printf("%lld\n",digit[0]);
  }
}rdCost;

struct Edge{
  int next;
  BigInt cost;
};

vector<Edge> edge[200];
bool mark[200];
BigInt dis[200];

void dijkstra(int n){
  for(int i=0;i<200;i++){
    mark[i]=false;
    dis[i].set(-1);
  }
  int newP=0;
  mark[0]=true;
  dis[0].set(0);
  for(int i=1;i<n;i++){
    for(int j=0;j<edge[newP].size();j++){
      int next=edge[newP][j].next;
      BigInt cost=edge[newP][j].cost;
      if(mark[next]) continue;
      if(dis[next].digit[0]==-1||(cost+dis[newP])<dis[next])
	dis[next]=cost+dis[newP];
    }
    for(int j=0;j<n;j++){
      if(!mark[j]&&dis[j].digit[0]!=-1){
	newP=j;
	break;
      }
    }
    for(int j=newP+1;j<n;j++){
      if(mark[j]||dis[j].digit[0]==-1) continue;
      if(dis[j]<dis[newP]) newP=j;
    }
    mark[newP]=true;
  }
  return;
}

int main(){
  int m,n;
  while(scanf("%d%d",&n,&m)!=EOF){
    rdCost.init();
    rdCost.set(1);
    for(int i=0;i<200;i++)
      edge[i].clear();
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      Edge e;
      e.cost=rdCost;
      e.next=a;
      edge[b].push_back(e);
      e.next=b;
      edge[a].push_back(e);
      rdCost.mul2();
    }
    dijkstra(n);
    for(int i=1;i<n;i++)
      dis[i].display();
  }
  return 0;
}
