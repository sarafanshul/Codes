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
	int sm = n*(n+1)/2;
	for (int i = 0; i < n-1 ;i++) {
		cin >> m;
		sm -= m;
	}
	cout << sm;

	return 0;
}
