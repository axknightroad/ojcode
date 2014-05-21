#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str[200];

int main(){
  while(scanf("%s",str)!=EOF)
    {
      int i=strlen(str);
      sort(str,str+i);
      printf("%s\n",str);
    }
  return 0;
}
