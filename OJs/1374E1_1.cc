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
	int N, K;
    cin >> N >> K;
    vector<int> A, B, both;
 
    for (int i = 0; i < N; i++) {
        int t, a, b;
        cin >> t >> a >> b;
 
        if (a + b == 2)
            both.push_back(t);
        else if (a == 1)
            A.push_back(t);
        else if (b == 1)
            B.push_back(t);
    }
 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(both.begin(), both.end());
    int64_t best = INF64;
    int64_t sum = 0;
 
    vector<int64_t> A_sum(A.size() + 1, 0);
    vector<int64_t> B_sum(B.size() + 1, 0);
 
    for (int i = 0; i < int(A.size()); i++)
        A_sum[i + 1] = A_sum[i] + A[i];
 
    for (int i = 0; i < int(B.size()); i++)
        B_sum[i + 1] = B_sum[i] + B[i];
 
    for (int x = 0; x <= int(both.size()); x++) {
        if (x > 0)
            sum += both[x - 1];
 
        int need = K - x;
 
        if (need >= 0 && int(A.size()) >= need && int(B.size()) >= need)
            best = min(best, sum + A_sum[need] + B_sum[need]);
    }
 
    cout << (best < INF64 ? best : -1) << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
