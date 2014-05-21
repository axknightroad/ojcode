#include <stdio.h>
#include <string.h>

struct bigFloat{
  int intNum[100];
  int floatNum[100];
  int intSize;
  int floatSize;
  void init(){
    for(int i=0;i<100;i++){
      intNum[i]=0;
      floatNum[i]=0;
    }
    intSize=0;
    floatSize=0;
    return;
  }
  void set(char a[]){
    init();
    int len=strlen(a);
    int point=0;
    while(a[point]!='.') point++;
    bool floatFlag=true;
    for(int i=point-1,w=1,f=0,tmp=0;i>=0;i--){
      tmp+=(a[i]-'0')*w;
      w*=10;
      f++;
      if(f>3||i==0){
	intNum[intSize++]=tmp;
	tmp=0;
	w=1;
	f=0;
      }      
    }
    for(int i=point+1,w=1000,f=0,tmp=0;i<len;i++){
      tmp+=(a[i]-'0')*w;
      w/=10;
      f++;
      if(f>3||i==len-1){
	floatNum[floatSize++]=tmp;
	tmp=0;
	w=1000;
	f=0;
      }   
    }
    return;
  }
  void outPut(){
    for(int i=intSize-1;i>=0;i--){
      if(i!=intSize-1)
	printf("%04d",intNum[i]);
      else printf("%d",intNum[i]);
    }
    printf(".");
    for(int i=0;i<floatSize;i++)
      if(i!=floatSize-1)
	printf("%04d",floatNum[i]);
      else{
	int temp=4;
	while(floatNum[i]%10==0&&floatNum[i]!=0)
	  {
	    floatNum[i]/=10;
	    temp--;
	  }
	if(!floatNum[i])
	  temp=1;
	switch(temp){
	case 4:	
	  printf("%04d\n",floatNum[i]);
	  break;
	case 3:	
	  printf("%03d\n",floatNum[i]);
	  break;
	case 2:	
	  printf("%02d\n",floatNum[i]);
	  break;
	case 1:	
	  printf("%d\n",floatNum[i]);
	  break;
	default:
	  break;
	}
      }
    return;
  }
  bigFloat operator +(const bigFloat &A) const{
    bigFloat ans;
    ans.init();
    int carry=0;
    ans.floatSize=floatSize>=A.floatSize?floatSize:A.floatSize;
    for(int i=ans.floatSize-1;i>=0;i--){
      ans.floatNum[i]=floatNum[i]+A.floatNum[i]+carry;
      carry=ans.floatNum[i]/10000;
      ans.floatNum[i]%=10000;
    }
    while(!ans.floatNum[ans.floatSize-1]&&ans.floatSize>1) 
      ans.floatSize--;
    for(int i=0;i<intSize||i<A.intSize;i++){
      ans.intNum[i]=intNum[i]+A.intNum[i]+carry;
      carry=ans.intNum[i]/10000;
      ans.intNum[ans.intSize++]%=10000;
    }
    if(carry)
      ans.intNum[ans.intSize++]=carry;
    return ans;
  }
}a,b,c;
  
char str1[102],str2[102];

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    for(int i=0;i<n;i++){
      scanf("%s%s",str1,str2);
      a.set(str1);
      b.set(str2);
      c=a+b;
      c.outPut();
    }
  }
  return 0;
}
