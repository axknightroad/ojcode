#include <stdio.h>

int weight[1010];
int win0[1010];
int win1[1010];
int rank[1010];
int order[1010];
int loser[1010];

void init(int n){
  for(int i=0;i<n;i++){    

    weight[i]=0;
    win0[i]=0;
    win1[i]=0;
    rank[i]=0;
    order[i]=0;
    loser[i]=0;
  }
}

void game(int n,int k){
  int lsize=0;
  while(n>1){
    int max;
    int size=0;
    for(int i=0,c=0;i<n;i++){
      int tmp=win0[i];
      if(c==0) max=tmp;
      else if(weight[tmp]>weight[max]) {loser[lsize++]=max; max=tmp;}
      else {loser[lsize++]=tmp;}
      c++;
      if(c==k||i==n-1){
	win0[size++]=max;
	c=0;
	rank[max]++;
      }	
    }
    //  for(int i=0;i<size;i++)
    //    win0[i]=win1[i];
    n=size;
  }
  int win=win0[0];
  int r=rank[win]-1;
  int now=2;
  order[win]=1;
  for(int i=lsize-1,j=2;i>=0;i--,j++){
    int tmp=loser[i];
    if(rank[tmp]<r){
      r--;
      now=j;
    } 
    order[tmp]=now;     
  } 
  return;
}

int main(){
  int n,k;
  while(scanf("%d%d",&n,&k)!=EOF){
    //    init(n);
    for(int i=0;i<n;i++)
      scanf("%d",&weight[i]);
    for(int i=0;i<n;i++){
      int tmp;
      scanf("%d",&win0[i]);
    }
    game(n,k);
    for(int i=0;i<n;i++){
      if(i)
	printf(" ");
      printf("%d",order[i]);
    }
    printf("\n");
  }
  return 0;
}
