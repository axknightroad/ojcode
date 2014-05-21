#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char alr[200];
char aup[200];
string utor(string a);
string delChar(string sa,string sb){
  string sal=utor(sa);
  string sbl=utor(sb);
  int tmp=sal.find(sbl,0);
  while(tmp!=string::npos){
    sa.erase(tmp,sb.size());
    sal.erase(tmp,sb.size());
    tmp=sal.find(sbl,tmp);
  }
  tmp=sa.find(' ',0);
  while(tmp!=string::npos){
    sa.erase(tmp,1);
    tmp=sa.find(' ',tmp);
  }
  return sa;
}

string utor(string a){
  int len=a.size();
  char b[len+1];
  strcpy(b,a.c_str());
  for(int i=0;i<len;i++)
    if(b[i]>='A'&&b[i]<='Z')
      b[i]=b[i]-'A'+'a';
  b[len]='\0';
  a=b;
  return a;
}
bool isSpace(string a){
  int len=a.size();
  char b[200];
  strcpy(b,a.c_str());
  for(int i=0;i<len;i++)
    if(b[i]!=' ') return false;
  return true;
}
char b0[200],a0[200];

int main(){
  string a,b;
  gets(b0);
  b=b0;
  while(gets(a0)){
    a=a0;
    if(!strcmp(a.c_str(),"\000")||isSpace(a))
      printf("\n");
    else{
      a=delChar(a,b);
      printf("%s\n",a.c_str());
    }
  }
  return 0;
}
