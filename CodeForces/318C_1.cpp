#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
 
 
int main(){
    long long x,y,m;
    cin>>x>>y>>m;
 
    if(y<x)swap(x,y);
    if(m<=y){
        cout<<0<<endl;
    }else if(x<=0&&y<=0){
        cout<<-1<<endl;
    }else {
        long long ans=0;
        if(x<=0){
            ans=(1-x + y-1)/y;
            x += ans*y;
        }
        while(x<m&&y<m){
            if(x<y)x+=y;
            else y+=x;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
