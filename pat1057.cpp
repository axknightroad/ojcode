#include <stdio.h>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;

stack<long long> s;
long long mid;
multiset<long long> up,low;
multiset<long long>::iterator now; 
long long peekMedian(){
  return mid;  
}

void init(){
  mid=0;
  up.clear();
  low.clear();
  return;
}

bool push(long long a){
  if(s.empty()){
    s.push(a);
    mid=a;
    return true;
  }
  s.push(a);
  if(a>=mid) up.insert(a);
  else low.insert(a);
  if(up.size()>low.size()+1){
    low.insert(mid);
    now=up.begin();
    mid=*now;
    up.erase(now);
  }
  else if(low.size()>up.size()){
    up.insert(mid);
    now=low.end();
    now--;
    mid=*now;
    low.erase(now);
  }
return true;
}

long long pop(){
  long long tmp=s.top();
  s.pop();
  if(tmp==mid){
    if(s.empty()){
      mid=0;
      return tmp;
    }
    if(up.size()==low.size()){
      now=low.end();
      now--;
      mid=*now;
      low.erase(now);
    }
    else{
      now=up.begin();
      mid=*now;
      up.erase(now);
    }
  }
  else if(tmp>mid) {now=up.find(tmp);up.erase(now);}
  else {now=low.find(tmp);low.erase(now);}
  if(up.size()>low.size()+1){
    low.insert(mid);
    now=up.begin();
    mid=*now;
    up.erase(now);
  }
  else if(low.size()>up.size()){
    up.insert(mid);
    now=low.end();
    now--;
    mid=*now;
    low.erase(now);
  }
  return tmp;
}

int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    char command[15];
    init();
    long long tmp;
    while(n){
      scanf("%s",command);
      if(strcmp(command,"Pop")==0){
	if(s.empty())
	  printf("Invalid\n");
	else{
	  printf("%lld\n",pop());
	}
      }
      if(strcmp(command,"Push")==0){
	scanf("%lld",&tmp);
	push(tmp);
      }
      if(strcmp(command,"PeekMedian")==0){
	if(s.empty())
	  printf("Invalid\n");
	else{
	  printf("%lld\n",peekMedian());
	}
      }
      n--;
    }
  }
  return 0;
}
