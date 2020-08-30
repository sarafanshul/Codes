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
	int a ,b;
	cin >> a >> b; // 3 coins at a time;
	cout << (!((a + b) % 3) && min(a, b) * 2 >= max(a, b) ? "YES\n" : "NO\n");
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >>t;
	while(t--) check();
	return 0;
}
