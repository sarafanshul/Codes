#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long;

using namespace std;
const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >>n;
	cout << n << " ";
	while(n != 1){
		if(n&1) n/=2;
		else n = (n*3) + 1;
		cout << n << " ";
	}

	return 0;
}
