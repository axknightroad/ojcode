#include <stdio.h>

bool isPrime[32*1024+1];
//int prime[4000];
//int k;

void initPrime(){
  for(long long i=0;i<32*1024+1;i++)
    isPrime[i]=true;
  isPrime[0]=false;
  isPrime[1]=false;
  // k=0;
  for(long long i=2;i<32*1024+1;i++){
    if(!isPrime[i]) continue;
    //  prime[k++]=i;
    for(long long j=i*i;j<32*1024+1;j+=i)
      isPrime[j]=false;
  }
  return;
}

int goldCon(int a){
  int count=0;
  for(int i=2;i<=a/2;i++){
    if(!isPrime[i]) continue;
    if(isPrime[a-i]) count++;
  }
  return count;
}

int main(){
  int n;
  initPrime();
  while(scanf("%d",&n)&&n){
    int count=goldCon(n);
    printf("%d\n",count);
  }
  return 0;
}
