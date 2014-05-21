#include <stdio.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char in[85];
char out[40][40];
int n1,n2;
int size;
int bc(int n){
	int max=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++)
			if(2*j+i-2==n&&j>max)
				max=j;
	}
	return max;		
}

void getout(){
	int now=0;
	for(int y=0;y<n1;y++)
		for(int x=0;x<n2;x++){
			if(y<n1-1){
				if(x==0) out[x][y]=in[now];
				else if(x==n2-1) { out[x][y]=in[size-now-1]; now++;}
				else out[x][y]=' ';
			}
			else	out[x][y]=in[now++];		
		}
	return;		
}


int main(int argc, char** argv) {
	while(scanf("%s",in)!=EOF){
		size=strlen(in);
		n1=bc(size);
		n2=size+2-n1*2;
		getout();
		for(int y=0;y<n1;y++){
			for(int x=0;x<n2;x++)
				printf("%c",out[x][y]);
			printf("\n");
		}
	}
	return 0;
}
