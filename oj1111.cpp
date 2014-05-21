#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;

string change(string s,string a,string b){  
  s.insert(0," "); s+=" ";
  a.insert(0," "); a+=" ";
  b.insert(0," "); b+=" ";
  int len=a.size();
  int tmp=s.find(a,0);
  while(tmp>=0){
    s.replace(tmp,len,b);
    tmp=s.find(a,tmp);
  }
  s.erase(s.begin());
  s.erase(s.end()-1);
  return s;
}

char s0[200],a0[200],b0[200];
string s,a,b;
int main(){
  while(gets(s0)){
    gets(a0);
    gets(b0);
    s=s0;
    a=a0;
    b=b0;
    s=change(s,a,b);
    puts(s.c_str());
    //char c;
    //while(c=getchar()&&c!='\n');
  }
  return 0;
}
