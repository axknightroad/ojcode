#include <stdio.h>

int main(){
  for(int a=0;a<=5;a++)
    for(int b=0;b<=5;b++)
      for(int c=0;c<=9;c++){
	int p1=a*100+b*10+c;
	int p2=b*100+c*10+c;
	if(p1+p2==532)
	  printf("%d %d %d\n",a,b,c);
      }
  return 0;
}
