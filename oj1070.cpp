#include <stdio.h>

#define ISLEAP(x) x%100!=0&&x%4==0||x%400==0?1:0

int dayOfMonth[13][2]=
{
  0,0,
  31,31, //January
  28,29, //February
  31,31, //March
  30,30, //April
  31,31, //May
  30,30, //June
  31,31, //July
  31,31, //August
  30,30, //September
  31,31, //October
  30,30, //November
  31,31, //December

};

struct Data{
  int Year;
  int Month;
  int Day;
  void nextDay()
  {
    Day++;
    if(Day>dayOfMonth[Month][ISLEAP(Year)])
      {
	Day=1;
	Month++;
      }
    if(Month>12)
      {
	Month=1;
	Year++;
      }
  }
};

int buf[3001][13][32];

int main(){
  int dayNum=0;
  Data all;
  all.Year=1;
  all.Month=1;
  all.Day=1;
  while(all.Year!=3001)
    {
      buf[all.Year][all.Month][all.Day]=dayNum;
      all.nextDay();
      dayNum++;
    }
  int y,d,m;
  while(scanf("%d %d %d",&y,&m,&d)!=EOF)
    {
      printf("%d\n",buf[y][m][d]-buf[y][1][1]+1);
    }
}
