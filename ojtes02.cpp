#include<stdio.h>

int a[10010];
int s,e;

void init(){
  s=0;
  e=0;
  for(int i=0;i<10010;i++)
    a[i]=0;
 }

bool output(int x,int n){
  int tmp=0;
  for(int i=0;i<n;i++){
    tmp=a[i];
    for(int j=i+1;j<n;j++){
      tmp+=a[j];
      if(tmp==x)
	{
	  s=i+1;
	  e=j+1;
	  return true;
	}
    }
  }
  return false;
}
int main(){
  int n,x;
  while(scanf("%d",&n)!=EOF){
    init();
    for(int i=0;i<n;i++)
      scanf("%d",&a[i]);
    scanf("%d",&x);
    if(output(x,n))
      printf("%d %d\n",s,e);
    else
      printf("No\n");
  }
  return 0;
}
