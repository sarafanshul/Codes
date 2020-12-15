#include <bits/stdc++.h>
using namespace std;

const long long Alp = 20;

void check(){
	int n;
	vector<int> a(n);
	long long curr = 1;
	for (int i = 0 ; i < n ; ++i){
		cin >> a[i];
		if (curr <= a[i]) curr++;
	}
	cout << curr <<"\n";
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
