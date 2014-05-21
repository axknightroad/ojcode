#include <stdio.h>

int k;
bool isPrime[150001];
long long primeNum[10001];
int count=0;

void initPrime(){
  for(long long i=0;i<150000;i++)
    isPrime[i]=true;
  isPrime[0]=false;
  isPrime[1]=false;
  for(long long i=2;i<150000;i++){
    if(!isPrime[i]) continue;
    primeNum[++count]=i;
    for(long long j=i*i;j<150000;j+=i)
      isPrime[j]=false;
    if(count>=10000)
      break;
  }
  return;
}

int main(){
  initPrime();
  while(scanf("%d",&k)!=EOF){
    printf("%lld\n",primeNum[k]);
  }
  return 0;
}
