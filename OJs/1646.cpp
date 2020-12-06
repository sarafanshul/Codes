#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;
const int MOD = 1e9+7;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,q;
	cin >> n >> q;
	vector<int> a(n) ,p(n+1 ,0);
	for(int i = 0; i < n ; i++){
		cin >> a[i];
		p[i+1] = p[i] + a[i];
	}
	for(int i =0; i< q ; ++i){
	    int l ,r;
	    cin >> l >> r;
	    cout << p[r] - p[l-1] << "\n";
	}
	return 0;
}
