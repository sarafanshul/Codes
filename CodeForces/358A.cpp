#include <bits/stdc++.h>
using namespace std;

const long long Alp = 20;

void check(){
	long long n ,m;
	cin >> n >> m;
	vector<long long> pre{0 ,0 ,0 ,0 ,0};
	for(long long i = 1 ;i <= m ; ++i){
		pre[i%5]++;
	}
	long long ans = 0;
	for(long long i = 1; i <= n ; ++i){
		ans += pre[(5 - i%5)%5];
	}
	cout << ans <<"\n";
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	long long t;
	// cin >> t;
	t = 1LL;
	while(t--){
		check();
	}
	return 0;
}
