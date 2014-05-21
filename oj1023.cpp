#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int c;
int n;

struct info
{
  char id[7];
  char name[9];
  short score;
} buf[100000];


bool cmp1(info a,info b)
{
  return strcmp(a.id,b.id)<0;
}
bool cmp2(info a,info b)
{
  return strcmp(a.name,b.name)<0;
}
bool cmp3(info a,info b)
{
  return a.score<b.score; 
}
int main()
{
  int k=1;
  while(scanf("%d %d\n",&n,&c),n)
    {
      for(int i=0;i<n;i++)
	scanf("%s %s %d\n",buf[i].id,buf[i].name,&buf[i].score);
      sort(buf,buf+n,cmp1);
      switch(c)
	{
	case 1:break;
	case 2:stable_sort(buf,buf+n,cmp2);break;
	case 3:stable_sort(buf,buf+n,cmp3);break;
	}
      printf("Case %d:\n",k++);
      for(int i=0;i<n;i++)
	{
	  printf("%s %s %d\n",buf[i].id,buf[i].name,buf[i].score);
	  //printf("%s ",buf[i].name);
	  //printf("%d\n",buf[i].score);
	}
    }
  return 0;
}
