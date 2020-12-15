//https://www.youtube.com/watch?v=doOPlmXxPPQ

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
using namespace std;

const size_t MAXN = 1e5 +7;

int64_t ceil_div(int64_t a, int64_t b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

void check(){
	int N;
    cin >> N;
    vector<int> A(N);
 
    for (auto &a : A)
        cin >> a;
 
    vector<int64_t> diffs(N - 1);
    int64_t diff_sum = 0;
 
    for (int i = 0; i < N - 1; i++) {
        diffs[i] = A[i + 1] - A[i];
        diff_sum += min(diffs[i], INT64_C(0));
    }
 
    int64_t a_back = A.back();
 
    auto &&update = [&](int index, int add) {
        diff_sum -= min(diffs[index], INT64_C(0));
        diffs[index] += add;
        diff_sum += min(diffs[index], INT64_C(0));
    };
 
    auto &&query = [&] {
        return ceil_div(a_back - diff_sum, 2);
    };
 
    cout << query() << '\n';
    int Q;
    cin >> Q;
 
    for (int q = 0; q < Q; q++) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        if (L > 0) update(L - 1, X);
        if (R < N) update(R - 1, -X);
        if (R == N) a_back += X;
        cout << query() << '\n';
    }
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
// 	cin.exceptions(cin.failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
