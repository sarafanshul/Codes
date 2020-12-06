#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;

string s[8];
bool b[16];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	for(int i = 0; i < 8 ; ++i){
		cin >> s[i];
	}
	int p[8] ,ans = 0;
	iota(p ,p+8 ,0);
	do{
		bool ok = 1;
		for(int i = 0; i < 8; ++i){
			ok &= s[i][p[i]] == '.';
		}
		memset(b ,0 ,16);
		for(int i = 0; i <8; i++){
			if(b[i + p[i]])
				ok = 0;
			b[i+p[i]] = 1;
		}
		memset(b ,0 ,16);
		for(int i = 0; i < 8 ; ++i){
			if (b[i + 7 - p[i]])
				ok = 0;
			b[i + 7 - p[i]] = 1;
		}
		ans += ok;
	} while(next_permutation(p ,p+8));

	cout << ans;
	return 0;
}
