#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
using ll = long long ;
using db = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
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
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
const long long MAXN = 2e5 +7;

void check(){
	int N;
	cin >> N;
	vector<vector<int>> adj(N, vector<int>(N, 0));
 
	auto set_edge = [&](int a, int b, int win) {
		adj[a][b] = win;
		adj[b][a] = -win;
	};
 
	auto get_sum = [&](int a) {
		return accumulate(adj[a].begin(), adj[a].end(), 0);
	};
 
	if (N % 2 == 0) {
		for (int i = 0; i < N; i += 2)
			set_edge(i, (i + 1) % N, 0);
 
		if (N % 4 != 0) {
			for (int i = 1; i < N; i += 2)
				set_edge(i, (i + 1) % N, 1);
 
			for (int i = 0; i < N; i += 2)
				set_edge(i, (i + N / 2) % N, 1);
		} else {
			for (int i = 1; i < N; i += 2)
				set_edge(i, (i + 1) % N, i < N / 2 ? 1 : -1);
 
			for (int i = 0; i < N / 2; i++) {
				int sum = get_sum(i);
				assert(sum != 0 && get_sum(i + N / 2) == -sum);
				set_edge(i, i + N / 2, sum < 0 ? 1 : -1);
			}
		}
	} else {
		for (int i = 0; i < N; i++)
			set_edge(i, (i + 1) % N, 1);
	}
 
	if (N == 2)
		set_edge(0, 1, 0);
 
	for (int len = 2; len <= (N - 1) / 2; len++) {
		for (int i = 0; i < N; i++)
			set_edge(i, (i + len) % N, 1);
	}
 
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			cout << adj[i][j] << ' ';
 
	cout << '\n';
 
	for (int i = 0; i < N; i++)
		assert(get_sum(i) == 0);

}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
