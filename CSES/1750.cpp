#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
#define int long long
#define INF LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 3*(1e5 +7);

vector<int> to(MAXN);
int n ,m ,total_weight = 0;

void ck(int x ,int k){
    int i = 0;
    for(; i < k; x = to[x] ,i++){}
    cout << x <<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin.exceptions(cin.failbit);
    int u ,v ,w;
    cin >> n >> m;
    for(int i = 1 ;i <= n ;i++) cin >> to[i];
    while(m--){
        cin >> u >> w;ck(u ,w);
    }
    return 0;
}
