#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,m;
	cin >>n;
	vector<int> a(n+1);
	for(int i = 0; i <n; i++) cin >> a[i];
	a[n] = INT_MAX;
	
	ll _mn = 0;
	for(int i = 0; i< n ; ++i){
	    if (a[i] > a[i+1]){
	        _mn += a[i]-a[i+1];
	        a[i+1] = a[i];
	    }
	}
	cout << _mn;

	return 0;
}
