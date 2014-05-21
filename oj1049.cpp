#include <stdio.h>
#include <string>
using namespace std;

string delc(string a,string b){
  int tmp=a.find(b,0);
  while(tmp>=0){
    a.erase(tmp,1);
    tmp=a.find(b,tmp);
  }
  return a;
}
char in[100];

int main(){
  while(scanf("%s",in)!=EOF){
    char c[2];
    scanf("%s",c);
    string a=in;
    string b=c;
    a=delc(a,b);
    printf("%s\n",a.c_str());
  }
  return 0;
}
