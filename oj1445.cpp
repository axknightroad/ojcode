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
  int t;
  while(scanf("%d",&t)!=EOF){
    for(int j=0;j<t;j++){
      int m,n;	
      scanf("%d%d",&n,&m);
      initTree();
      for(int i=0;i<m;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	a=findRoot(a);
	b=findRoot(b);
	if(a!=b)
	  tree[b]=a;
      }
      int table=0;
      for(int i=1;i<=n;i++)
	if(tree[i]==-1)
	  table++;
      printf("%d\n",table);
    }
  }
  return 0;
}
