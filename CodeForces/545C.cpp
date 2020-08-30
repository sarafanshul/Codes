
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
// #define int long long
using namespace std;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> trp(n) ,trh(n);
	for(int i = 0 ; i< n; i++){cin>> trp[i];cin>>trh[i];}
	if(n<3){cout << n ;return 0;}
	int ans = 2; // first=>left;last=>right
	int left = trp[0];
	for(int i = 1; i < n-1; i++){
		if(left < (trp[i] - trh[i])){ans++ ;left = trp[i];}
		else if((trp[i] + trh[i]) < trp[i+1]){ans++; left = trp[i]+trh[i];}
		else left = trp[i];
	}
	cout<<ans;

	return 0;
}