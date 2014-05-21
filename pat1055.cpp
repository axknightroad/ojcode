#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

#define INF -1000100

struct Rich{
  char name[10];
  int age;
  long long  worth;
  bool operator < (const Rich &A) const{
    if(worth!=A.worth)
      return worth>A.worth;
    else if(age!=A.age)
      return age<A.age;
    else{
      int tmp=strcmp(name,A.name);
      return tmp<0?true:false;
    }
  }
} rich[100010];

queue<Rich> q;
long long n;
int k;

void output(int size,int min,int max,int num,int newSize){
  printf("Case #%d:\n",num);
  bool flag=false;
  for(long long i=0;i<newSize;i++){
    if(rich[i].age>=min&&rich[i].age<=max){
      printf("%s %d %lld\n",rich[i].name,rich[i].age,rich[i].worth);
      size--;
      flag=true;
    }
    if(!size) break;
  }
  if(!flag) printf("None\n");    
  return;
}

int main(){
  while(scanf("%lld%d",&n,&k)!=EOF){
    for(long long i=0;i<n;i++) 
      scanf("%s %d %lld",rich[i].name,&rich[i].age,&rich[i].worth);
    sort(rich,rich+n);
    int newSize=n;
    int ageCount[210]={0};
    for(int i=0;i<n;i++){
      int tmp=rich[i].age;
      ageCount[tmp]++;
      if(ageCount[tmp]>100){
	rich[i].worth=INF;
	newSize--;
      }
    }
    sort(rich,rich+n);
    for(int i=1;i<=k;i++){
      int size,min,max;
      scanf("%d%d%d",&size,&min,&max);
      output(size,min,max,i,newSize);
    }
  }
  return 0;
}
