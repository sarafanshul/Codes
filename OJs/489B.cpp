
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
// #define int long long
using namespace std;

inline bool sgn(int x){return (x>0)?1:0;}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,m;
	cin >> n;
	int res = 0;
	vector<int> a(n);
	for(int i = 0;i<n;i++){cin >> a[i];}
	sort(ALL(a));
	cin >> m;
	vector<int>b(m);
	for(int i = 0; i <m ;i++) cin>> b[i];
	sort(ALL(b));

	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			if (abs(a[i]-b[j]) <= 1){
				b[j] = 1001;
				res++;
				break;
			}
		}
	}cout << res;
	return 0;
}