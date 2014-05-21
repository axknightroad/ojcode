#include <stdio.h>
#include <string.h>

char s[2000];
char a[2000];
bool flag[2000];

void init(){
  for(int i=0;i<2000;i++)
    flag[i]=false;
}
bool isRepeat(int x,int len){
  int y;
  for(int i=0;i<2000;i++)
    if(flag[i]){
      if(strncmp(s+x,s+i,len)==0)
	return true;
    }      
  return false;
}
int output(){
  int ans=0;
  int len=strlen(s);
  for(int cslen=1;cslen<=len/2;cslen++){
    init();
    for(int i=0;i<=len-cslen*2;i++){
      strncpy(a,s+i,cslen);
      a[cslen]='\0';
      char *b=strstr(s+i+cslen,a);
      if(b!=NULL){
	if(isRepeat(i,cslen)) continue;
	flag[i]=true;
	ans++;
      }
    }
  }      
  return ans;
}

int main(){
  while(scanf("%s",s)!=EOF){
    int ans=output();
    printf("%d\n",ans);
  }
  return 0;
}
