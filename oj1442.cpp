#include <stdio.h>

int n,k;
long long buf[3];

long long arith(long long a,long long b,int k){
  long long ans=a;
  while(k){
    if(k%2){
      ans+=b;
      ans%=200907;
    }
    k/=2;
    b+=b;
    b%=200907;
  }
  return ans;
}

long long geo(long long a,long long b,int k){
  long long ans=a;
  while(k){
    if(k%2){
      ans*=b;
      ans%=200907;
    }
    k/=2;
    b*=b;
    b%=200907;
  }
  return ans;
}

int main(){
  while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++){
      for(int j=0;j<3;j++)
	scanf("%lld",&buf[j]);
      scanf("%d",&k);
      long long ans;
      if(buf[2]-buf[1]==buf[1]-buf[0])
	ans=arith(buf[0],buf[1]-buf[0],k-1);
      else
	ans=geo(buf[0],buf[1]/buf[0],k-1);
      printf("%lld\n",ans);
    }
  }
  return 0;
}
