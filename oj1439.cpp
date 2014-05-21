#include <stdio.h>

int n;
long long m[10000]={0};
long long gcd(long long a,long long b){  
  if(!a||!b)
    return 0;
  while(b){
    long long t=(a%b+b)%b;
    a=b;
    b=t;
  }
  return a;
} 

long long lcm(long long a,long long b){
  if(!a||!b)
    return 0;
  else
    return a*b/gcd(a,b);
}

int main(){
  while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++){
    int k=0;
    scanf("%d",&k);
    for(int j=0;j<k;j++)
      scanf("%lld",&m[j]);
    for(int j=0;j<k-1;j++)
      m[j+1]=lcm(m[j],m[j+1]);
    printf("%lld\n",m[k-1]);
    }
  }
  return 0;
}
