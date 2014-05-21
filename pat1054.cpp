#include <stdio.h>
#include <memory.h>

#define MAXSIZE 1024*1024*16+10

long long hash[MAXSIZE];

void init(){
  memset(hash,0,MAXSIZE*sizeof(int));
}

long long dc(long long k){
  long long max=0;
  for(long long i=0;i<=k;i++){
    if(hash[i]>hash[max]) max=i;
  }
  return max;
}
int m,n;
int main(){
  while(scanf("%d%d",&m,&n)!=EOF){
    init();
    long long k=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++){
	long long tmp;
	scanf("%lld",&tmp);
	hash[tmp]++;
	if(tmp>k) k=tmp;
      }
    long long out=dc(k);
    printf("%lld\n",out);
  }
  return 0;
}
