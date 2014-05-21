#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct info
{
  char name[101];
  int age;
  int score;
} buf[1000];

bool cmp(info a,info b)
{
  if(a.score!=b.score)
    return a.score<b.score;
  int tmp=strcmp(a.name,b.name);
  if(tmp!=0)
    return tmp<0;
  return a.age<b.age;
}

int n;
int main()
{
  while(scanf("%d",&n)!=EOF)
    {
      for(int i=0;i<n;i++)
	scanf("%s %d %d",buf[i].name,&buf[i].age,&buf[i].score);
      sort(buf,buf+n,cmp);
      for(int i=0;i<n;i++)
	printf("%s %d %d\n",buf[i].name,buf[i].age,buf[i].score);
    }
  return 0;
}
