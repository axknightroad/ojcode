#include <stdio.h>

int student[110];
int addNum[110];
int minNum[110];

void init(){
  for(int i=0;i<110;i++){
    student[i]=0;
    addNum[i]=0;
    minNum[i]=0;
  }
}
int max(int a,int b){return a>b?a:b;}
int getOut(int n){
  addNum[0]=1;
  for(int i=1;i<n;i++){
    int tmp=1;
    for(int j=0;j<i;j++)
      if(student[i]>student[j]){
	tmp=max(tmp,addNum[j]+1);
      }
    addNum[i]=tmp;
  }
  minNum[n-1]=0;
  for(int i=n-2;i>=0;i--){
    int tmp=0;
    for(int j=n-1;j>i;j--){
      if(student[i]>student[j]){
	tmp=max(tmp,minNum[j]+1);
      }
    }
    minNum[i]=tmp;
    addNum[i]+=minNum[i];
  }
  int tmp=1;
  for(int i=0;i<n;i++)
    tmp=max(tmp,addNum[i]);
  return n-tmp;
}

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++)
      scanf("%d",&student[i]);
    int ans=getOut(n);
    printf("%d\n",ans);
  }
  return 0;
}
