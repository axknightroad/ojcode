#include <stdio.h>
#include <string.h>

char s[10],out[10];
bool mark[10];
void fp(int k,int len){
  if(k==len){
    out[len]='\0';
    printf("%s\n",out);
    return;
  }
  for(int i=0;i<len;i++){
    if(mark[i]) continue;
    out[k]=s[i];
    mark[i]=true;
    fp(k+1,len);
    mark[i]=false;
  }
  return;
}
void init(){
  for(int i=0;i<10;i++)
    mark[i]=false;
}

int main(){
  while(scanf("%s",s)!=EOF){
    init();
    int len=strlen(s);
    fp(0,len);
    printf("\n");
  }
  return 0;
}
