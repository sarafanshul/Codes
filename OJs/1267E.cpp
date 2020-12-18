#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 1e5 +7;

void check(){
	#define int long long int
	#define vi vector<int>
	#define vvi vector<vi>
	int n, m;
	cin >> n >> m;
	vvi a(m);
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			int num;
			cin >> num;
			a[i].PB(num);
		}
	}
	vi ans = { -1 };
	for(int i = 0; i < n - 1; i++) {
		vvi v;
		vi temp;
		int sum = 0;
		for(int j = 0; j < m; j++) {
			sum += (a[j][i] - a[j][n - 1]);
			v.PB({ a[j][i] - a[j][n - 1], j });
		}
		sort(v.begin(), v.end());
		for(int k = 0; k < v.size() && sum < 0; k++) {
			temp.PB(v[k][1]);
			sum -= v[k][0];
		}
		if(ans == vi({ -1 }) || ans.size() > temp.size()) {
			ans = temp;
		}
	}
	cout << ans.size() << endl;
	for(int i : ans)
		cout << i + 1 << " ";
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
