#include <stdio.h>
#include <string.h>

char strDec[40];
int  digDec[40];
int digBin[101];

int main(){
  while(scanf("%s",strDec)!=EOF)
    {
      if(strDec[0]=='0'){
	printf("0");
      }
      else{
	for(int i=0;i<40;i++) 
	  digDec[i]=0;
	int lenD=strlen(strDec);
	for(int i=0;i<lenD;i++)
	  digDec[i]=strDec[i]-'0';
	int k=0;
	int lenB=0;
	while(k<=lenD){
	  digBin[lenB++]=digDec[lenD-1]%2;
	  int c=0;
	  for(int i=k;i<lenD;i++){
	    int tmp=digDec[i];
	    digDec[i]=(digDec[i]+c)/2;
	    c=(tmp%2)?10:0;	  
	  } 
	  while(!digDec[k])
	    k++;
	}
	for(int i=lenB-1;i>=0;i--)
	  printf("%d",digBin[i]);
      }
    printf("\n");
    }
  return 0;
}
