#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;

void check(){
	int x ,y;
	cin >> y >> x;
	int a = max(x ,y);
	int b = min(x ,y);
	ll s = (ll)(a-1)*(a-1);
	if (a==b) s += a;
	else if(a%2){
		if (x == a) s+= a*2 - y;
		else s+=x;
	}else {
		if (y == a) s += a*2 - x;
		else s += y;
	}
	cout << s << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		check();
	}

	return 0;
}
