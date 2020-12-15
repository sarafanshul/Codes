#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,_sm = 0 ,temp;
	cin >> n;
	for(int i = 0; i < n ;i++) {cin >> temp;_sm+=temp;}
	if(_sm%n) cout << n-1;
	else cout << n;
	return 0;
}