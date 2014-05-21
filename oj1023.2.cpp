#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100000
struct Stu{
    char id[7];//学号，姓名，成绩
    char name[9];
    short g;
};
Stu stu[MAX];
bool cmp1(Stu x, Stu y) { return strcmp(x.id, y.id)<0;}
bool cmp2(Stu x, Stu y) { return strcmp(x.name, y.name)<0;}
bool cmp3(Stu x, Stu y) { return x.g<y.g;}
int main()
{
    int n, c, k=1;
    while(scanf("%d %d\n", &n, &c), n)
    {
        for(int i=0; i<n; i++) { scanf("%s %s %d\n", stu[i].id, stu[i].name, &stu[i].g);}
        sort(stu, stu+n, cmp1);
        switch(c)
        {
            case 1:break;
            case 2:stable_sort(stu, stu+n, cmp2);break;
            case 3:stable_sort(stu, stu+n, cmp3);break;
        }
        printf("Case %d:\n", k++);
        for(int i=0; i<n; i++) { printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].g);}
    }
    return 0;
}
