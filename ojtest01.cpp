#include <stdio.h>
#include <string.h>

double time[12][60];

void getTime(){
  double a[12],b[60];
  for(int i=0;i<12;i++)
    a[i]=360*i/12;
  for(int i=0;i<60;i++)
    b[i]=360*i/60;
  for(int i=0;i<12;i++)
    for(int j=0;j<60;j++){
      double hour=a[i]+30*double(j)/60;
      double min=b[j];
      time[i][j]=hour>min?hour-min:min-hour;
      if(time[i][j]>180)
	time[i][j]=360-time[i][j];
    }
  return;
}

int main(){
  char s[8];
  getTime();
  while(scanf("%s",s)!=EOF){
    int a=((s[0]-'0')*10+s[1]-'0')%12;
    int b=(s[3]-'0')*10+s[4]-'0';
    float out=time[a][b];
    printf("%.2f\n",out);
  }
  return 0;
}
