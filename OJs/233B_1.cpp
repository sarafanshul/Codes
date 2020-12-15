
#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int s( LL x ) {
    int r=0;
    while ( x ) {
        r+=x%10;
        x/=10;
    }
    return r;
}
int main()
{
    LL n;
    cin>>n;
    LL x=sqrtl(n)+1;//bounds
    while ( x*x+100*x > n ) {
        if ( x*x+s(x)*x==n ) {
            cout<<x<<'\n';
            return 0;
        }
        x--;
    }
    cout << -1;
    return 0;
}

