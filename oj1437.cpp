#include <stdio.h>
#include <algorithm>

using namespace std;

struct gasStation
{
  float pr; //price
  float di;  //distance
} buf[501];

float Cmax,D,Davg;
int n;
float gas;

bool cmp(gasStation a,gasStation b){
  return a.di<b.di;
}

float fee(gasStation a,gasStation b){
  float money;
  float addgas;
  if(a.pr>b.pr)
    addgas=(b.di-a.di)/Davg-gas;
  else
    addgas=Cmax-gas;
  gas=gas+addgas-(b.di-a.di)/Davg;
  money=addgas*a.pr;
    return money;
}

int findStation(int a,int b){
  int min=a;
  for(int i=a;i<b;i++)
    if(buf[i].pr<buf[min].pr)
      min=i;
  if(min==a)
    return -1;
  else
    return min;
}

int findLong(int a){
  int max;
  float tmp=Cmax*Davg;
  for(int i=a;i<=n;i++)
    {
      if(buf[i].di-buf[a].di<=tmp)
	max=i;
      else 
	break;
    }
  if(max==a)
    return -1;
  else
    return max;
}

int main(){
  while(scanf("%f%f%f%d",&Cmax,&D,&Davg,&n)!=EOF){
    for(int i=0;i<n;i++)
      scanf("%f%f",&buf[i].pr,&buf[i].di);
    sort(buf,buf+n,cmp);
    buf[n].di=D;
    buf[n].pr=0;
    int start=0;
    int end=0;
    float distance=0;
    float price=0;
    int flag=0;
    gas=0;
    if(buf[0].di!=0)
      {
	flag=1;
	goto print;
      }
    while(start!=n)
      {
	end=findLong(start);
	if(end==-1)
	  {
	    distance=distance+Davg*Cmax;
	    flag=1;
	    break;
	  }
	int tmp=0;
	while(tmp=findStation(start,end))
	  {
	    if(tmp!=-1)
	      end=tmp;
	    else
	      break;
	  }
	price=price+fee(buf[start],buf[end]);
	distance=buf[end].di;
	start=end;
      }
  print:if(flag)
      printf("The maximum travel distance = %.2f\n",distance);
    else
      printf("%.2f\n",price);
  }
  return 0;  
}
