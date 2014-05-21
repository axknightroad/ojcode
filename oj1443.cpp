#include <stdio.h>

int buf[10][10];
int ans[10][10];


void matrixMul(int n){
  int tmp[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){      
      tmp[i][j]=0;
      for(int k=0;k<n;k++){
	tmp[i][j]+=ans[i][k]*buf[k][j];
	tmp[i][j]%=9973;
      }
    }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){      
      ans[i][j]=tmp[i][j];
    }
  return;
}

void matrixPow(int n){
  int tmp[n][n];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){      
      tmp[i][j]=0;
      for(int k=0;k<n;k++){
	tmp[i][j]+=buf[i][k]*buf[k][j];
	tmp[i][j]%=9973;
      }
    }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){      
      buf[i][j]=tmp[i][j];
    }
  return;
}


void power(int n,int k){
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i==j)
	ans[i][j]=1;
      else
	ans[i][j]=0;
  while(k){
    if(k%2==1){
      matrixMul(n);
    }
    k/=2;
    matrixPow(n);
  }
  return;
}


int main(){
  int t;
  while(scanf("%d",&t)!=EOF){
    for(int i=0;i<t;i++){
      int n,k;
      scanf("%d%d",&n,&k);
      for(int x=0;x<n;x++)
	for(int y=0;y<n;y++)
	  scanf("%d",&buf[x][y]);
      power(n,k);
      int res=0;
      for(int j=0;j<n;j++){
	res+=ans[j][j];
	res%=9973;
      }
      res%=9973;
      printf("%d\n",res);
    }
  }
  return 0;
}
