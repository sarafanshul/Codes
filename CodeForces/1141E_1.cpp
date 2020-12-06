// using binary search

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
	const ll N = 200005 ;
	ll h,n;
	ll d[N] ,sm=0, bkj=-1;
	cin >> h >> n;

	for(ll i = 1; i <= n ; i++) cin >> d[i];
	for(ll i = 1 ; i <= n ; i++ ) {
		sm += d[i];
		if(h + sm <= 0) {
			cout << i;
			return ;
		}
	}

	if(sm >= 0)  {
		cout << -1;
		return ;
	}

	ll low=1 , high=1e12;
	high /= ( max(1ll , abs(sm)-1 ) );
	high += N ;
	ll ans = high;

	auto ok = [&] (ll mid) -> bool {
		ll tmp = h + (mid - 1)*sm;

		for(ll i = 1 ; i <= n ; i++){
			tmp += d[i];
			if(tmp <= 0){
				bkj = (mid - 1)*n + i;
				return true;
			}
		}
		return false;
	};

	while( low <= high ) {

		ll mid = (low+high)/2;
		if(ok(mid)) {
			ans=mid;
			high=mid-1;
		}
		else {
			low=mid+1;
		}
	}

	ok(ans);
	cout<<bkj;
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
