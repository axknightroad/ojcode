#include <stdio.h>

bool isPrime[100001];
int prime[100001];
int primeSize;

void initPrime(){
  for(int i=2;i<100000;i++)
    isPrime[i]=true;
  for(int i=0;i<2;i++)
    isPrime[i]=false;
  for(int i=0;i<100000;i++){
    if(!isPrime[i]) continue;
    prime[primeSize++]=i;
    if(i>1000) continue;
    for(int j=i*i;j<100000;j+=i)
      isPrime[j]=false;
  }
  return;
}

int cntNum[30];
int cntCount[30];
int cntSize;

long long cnt(long long a){
  for(int i=0;i<30;i++){
    cntNum[i]=0;
    cntCount[i]=0;
  }
  cntSize=0;
  for(int i=0;i<primeSize;i++){
    if(prime[i]>a||a==1) break;
    if(a%prime[i]==0){
      cntNum[cntSize++]=i;
      while(a%prime[i]==0){
	cntCount[cntSize-1]++;
	a/=prime[i];
      }
    }
  }
  if(a!=1){
    cntNum[cntSize]=a;
    cntCount[cntSize++]=1;
  }
  long long count=1;
  for(int i=0;i<cntSize;i++)
    count*=cntCount[i]+1;
  return count;
}

int main(){
  int n;
  initPrime();
  while(scanf("%d",&n)&&n){
    for(int i=0;i<n;i++){
      long long tmp;
      scanf("%lld",&tmp);
      long long count=cnt(tmp);
      printf("%lld\n",count);
    }
  }
  return 0;
}
