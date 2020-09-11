// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
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
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 3*(1e5 +7);
const int INF = 1e9 + 1;
int h[MAXN], dp[MAXN], lge[MAXN], lle[MAXN], rge[MAXN], rle[MAXN];
vector<int> jumps[MAXN];

void check(){
	int n;
	cin >> n;
	for(int i = 0 ;i < n; i++){
		cin >> h[i];
		dp[i] = INF;
	}
	dp[0] = 0;
	vector<pair<int ,int>> st;
	st.reserve(MAXN*2);
	for(int i = 0; i < n ; i++){ // nearest greater from left
		while(!st.empty() && st.back().F < h[i]) st.pop_back();
		if(st.empty()) lge[i] = -1;
		else lge[i] = st.back().S;
		st.PB({h[i] ,i});
	}
	st.clear();
	for(int i = 0; i < n ; i++){ // nearest less from left
		while(!st.empty() && st.back().F > h[i]) st.pop_back();
		if(st.empty()) lle[i] = -1;
		else lle[i] = st.back().S;
		st.PB({h[i] ,i});
	}
	st.clear();
	for(int i = n-1; i >= 0 ; i--){ // nearest greater from right
		while(!st.empty() && st.back().F < h[i]) st.pop_back();
		if(st.empty()) rge[i] = -1;
		else rge[i] = st.back().S;
		st.PB({h[i] ,i});
	}
	st.clear();
	for(int i = n-1; i >= 0 ; i--){ // nearest less from right
		while(!st.empty() && st.back().F > h[i]) st.pop_back();
		if(st.empty()) rle[i] = -1;
		else rle[i] = st.back().S;
		st.PB({h[i] ,i});
	}
	
	for(int i = 0; i < n ;i++){
		if(rle[i] != -1) jumps[i].PB(rle[i]);
		if(rge[i] != -1) jumps[i].PB(rge[i]);
		if(lle[i] != -1) jumps[lle[i]].PB(i);
		if(lge[i] != -1) jumps[lge[i]].PB(i);
	}
	for (int i = 0; i < n; i++) {
        for (int to : jumps[i]) {
            dp[to] = min(dp[to], dp[i] + 1);
        }
    }
    cout << dp[n - 1]<<"\n";
    return;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t = 1;
	// cin >> t;
	while(t--){check();}
	return 0;
}
