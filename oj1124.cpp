#include <stdio.h>
#include <string.h>

int summed(int a){
  int ans=0;
  while(a){
    ans+=a%10;
    a/=10;
  }
  return ans;
}

int summedStr(char a[]){
  int n=strlen(a);
  char tmp[n];
  strcpy(tmp,a);
  int ans=0;
  for(int i=0;i<n;i++){
    ans+=tmp[i]-'0';
  }
  return ans;
}

int main(){
  char  s[100];
  while(scanf("%s",s)){
    if(!strcmp(s,"0")) break;
      int n=summedStr(s);
    while(n>=10)
      n=summed(n); 
    printf("%d\n",n);
  }
  return 0;
}
