#include <stdio.h>

int tree[1001];

int findRoot(int x){
  if(tree[x]==-1)
    return x;
  else{
    int tmp=findRoot(tree[x]);
    tree[x]=tmp;
    return tmp;
  }
}
void initTree(){
  for(int i=0;i<1001;i++)
    tree[i]=-1;
  return;
}


int main(){
  int m,n;
  while(scanf("%d%d",&n,&m)&&n){
    initTree();
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      a=findRoot(a);
      b=findRoot(b);
      if(a!=b)
	tree[b]=a;
    }
    bool flag=true;
    int root=findRoot(1);
    for(int i=1;i<=n;i++)
      if(findRoot(i)!=root){
	flag=false;
	break;
      }
    if(flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
