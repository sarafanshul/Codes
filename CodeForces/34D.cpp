#include<iostream>
#include<map>
#include<deque>
#include<cstdio>
#define LMT 1000005
using namespace std;

deque<pair<int,int> > q;
map<pair<int,int>,int> m;
int x[]={1,-1,0,0,-1,-1,1,1},y[]={0,0,1,-1,1,-1,1,-1};
int x0,y0,x1,y1,n;

int main(void){
    int xx,yy;
    scanf("%d%d%d%d%d",&y0,&x0,&y1,&x1,&n);
    while(n--)
    {
        int ri,ai,bi;
        scanf("%d%d%d",&ri,&ai,&bi);
        for(int j=ai;j<=bi;j++)m[make_pair(ri,j)]=-1;
    }
    m[make_pair(y0,x0)]=0;
    q.push_back(make_pair(y0,x0));
    while(!q.empty())
    {
        yy=q.front().first;
        xx=q.front().second;
        q.pop_front();
        for(int i=0;i<8;i++)
        if(m[make_pair(yy+y[i],xx+x[i])]<0)
        {
           m[make_pair(yy+y[i],xx+x[i])]=m[make_pair(yy,xx)]+1;
           q.push_back(make_pair(yy+y[i],xx+x[i]));
        }
    }
    printf("%d\n",m[make_pair(y1,x1)]);
    return 0;
}