#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Num{
  char address[7];
  int data;
  int next;
} num[100010];

int h[100010];
int q[100010];
int last;

int ctoi(char a[]){
  int tmp=0;
  for(int i=0;i<5;i++){
    tmp*=10;
    tmp+=a[i]-'0';
  }
  return tmp;
}

void init(){
  for(int i=0;i<100010;i++){
    strcpy(num[i].address,"\000");
    num[i].next=0;
    num[i].data=0;
    h[i]=0;
    q[i]=0;
  }
  return;
}

void output(int k,int n,int start){
  int tmp=h[start];
  int next=start;
  int size=0;
  for(int i=0;i<n;i++){
    q[size++]=tmp;
    next=num[tmp].next;
    if(next==-1)
      break;
    tmp=h[next];
  }
  // last=num[q[size-1]].next;  
  for(int i=0,t=0;i<=size;i++,t++){
    if(t==k){
      reverse(q+i-k,q+i);
      t=0;
    }
  }
  for(int i=0;i<size;i++){
    int tmp=q[i];
    int next=q[i+1];
    if(i<size-1)
      printf("%s %d %s\n",num[tmp].address,num[tmp].data,num[next].address);
    else
      printf("%s %d %d\n",num[tmp].address,num[tmp].data,-1);
  }
  return;
}  

int main(){
  int n,k;
  char s[7];
  while(scanf("%s%d%d",s,&n,&k)!=EOF){
    init();
    int start=ctoi(s);
    for(int i=0;i<n;i++){
      scanf("%s%d%d",num[i].address,&num[i].data,&num[i].next);
      h[ctoi(num[i].address)]=i;
    }
    output(k,n,start);
  }
  return 0;
}
