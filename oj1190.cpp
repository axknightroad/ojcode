#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct bigIntger{
  int digit[1000];
  int size;
  void init(){
    for(int i=0;i<1000;i++)
      digit[i]=0;
    size=0;
  }
  void set(char a[]){
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
  bool operator < (const bigIntger &A) const{
    if(size!=A.size)
      return size<A.size;
    else
      for(int i=size-1;i>=0;i--){
	if(digit[i]!=A.digit[i])
	  return digit[i]<A.digit[i];
      }	
    return false;
  }
  void display(){
    printf("%d",digit[size-1]);
    for(int i=size-2;i>=0;i--)
      printf("%04d",digit[i]);
    printf("\n");
    return;
  }
} buf[101];

int n;
char str[1001];

int main(){
  while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++){
      scanf("%s",str);
      buf[i].set(str);
    }
    sort(buf,buf+n);
    for(int i=0;i<n;i++){
      buf[i].display();
    }
  }
  return 0;
}
