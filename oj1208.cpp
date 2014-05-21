#include <stdio.h>
#include <string.h>

struct bigInteger{
  int digit[1000];
  int size;
  void init(){
    for(int i=0;i<1000;i++)
      digit[i]=0;
    size=0;
  }
  void input(char a[]){
    init();
    int len=strlen(a);
    for(int i=len-1,w=1,f=0,tmp=0;i>=0;i--){
      tmp+=(a[i]-'0')*w;
      w*=10;
      f++;
      if(f>3||i==0){
	digit[size++]=tmp;
	tmp=0;
	w=1;
	f=0;
      }
    }
    return;
  }
  void set(int x){
    init();
    do{
      digit[size++]=x%10000;
      x/=10000;
    }while(x);
    return;
  }
  bigInteger operator + (const bigInteger &A) const{
    int carry=0;
    bigInteger ret;
    ret.init();
    for(int i=0;i<size||i<A.size;i++){
      ret.digit[i]=digit[i]+A.digit[i]+carry;
      carry=ret.digit[i]/10000;
      ret.digit[ret.size++]%=10000;
    }
    if(carry)
      ret.digit[ret.size++]=carry;
    return ret;
  }
  bigInteger operator * (int a) const{
    int carry=0;
    bigInteger ret;
    ret.init();
    for(int i=0;i<size;i++){
      ret.digit[i]=digit[i]*a+carry;
      carry=ret.digit[i]/10000;
      ret.digit[ret.size++]%=10000;
    }
    if(carry)
      ret.digit[ret.size++]=carry;
    return ret;
  }
  bigInteger operator / (int a) const{
    int remainder=0;
    bigInteger ret;
    ret.init();
    for(int i=size;i>=0;i--){
      ret.digit[i]=(digit[i]+remainder*10000)/a;
      remainder=(digit[i]+remainder*10000)%a;
    }
    for(int i=0;i<size;i++)
      if(ret.digit[i])
	ret.size=i;
    ret.size++;
    return ret;
  }
  int operator % (int a) const{
    int remainder=0;
    for(int i=size;i>=0;i--){
      int t=(digit[i]+remainder*10000)/a;
      remainder=(digit[i]+remainder*10000)%a;
    }
    return remainder;
  }
  void display(){
    printf("%d",digit[size-1]);
    for(int i=size-2;i>=0;i--)
      printf("%04d",digit[i]);
    printf("\n");
    return;
  }  
} a;

struct bigBin{
  int digit[10001];
  int size;
  void init(){
    for(int i=0;i<10001;i++)
      digit[i]=0;
    size=0;
    return;
  }
} b;

bigBin DtoB(bigInteger a){
  bigBin ret;
  ret.init();
  do{
    ret.digit[ret.size++]=a%2;
    a=a/2;
  }while(a.size!=1||a.digit[0]!=0);
  return ret;
} 
bigBin reversion(bigBin a){
  bigBin b;
  b.init();
  b.size=a.size;
  for(int i=0;i<a.size;i++){
    b.digit[i]=a.digit[a.size-i-1];
  }
  while(b.digit[b.size-1]==0) b.size--;
  return b;
}

bigInteger BtoD(bigBin x){
  bigInteger a,b;
  a.set(0);
  b.set(1);
  for(int i=0;i<x.size;i++){
    a=a+(b*x.digit[i]);
    b=b*2;
  }    
  return a;
}

char str[1001];

int main(){
  while(scanf("%s",str)!=EOF){
    a.input(str);
    b=DtoB(a);
    b=reversion(b);
    a=BtoD(b);
    a.display();
  }
  return 0;
}
