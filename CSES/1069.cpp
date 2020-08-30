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
	string s;
	cin >> s;
	set <int> s1;
	int count = 1 ,_mx = 1;
	for(int i = 1 ; i < s.size(); ++i){
		if (s[i-1] == s[i]){
			count++;
			_mx = max(_mx , count);
		}
		else count = 1;
	}
	cout << _mx;
	return 0;
}
