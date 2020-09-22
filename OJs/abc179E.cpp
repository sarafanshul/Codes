/*

//  There are at most M possible values of Ai
 	Therefore, the sequence starts to repeat at some point. 
 	Precalculate

	1) the number of terms before the cycle starts and their sum, and
	2) the number of terms in the cycle and their sum,
	3) and calculate three values: 
		-> the sum of elements before the cycle, 
		-> the sum of repeating elements, and 
		-> the sum of remaining elements; 
then the problem could be solved in a total of O(M)time. 
Note that it may reach to the N -th element before entering the cycle.

*/


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
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

const size_t MAXN = 1e5 +7;

void check(){
	ll n ,x ,m;
	cin >> n >> x >> m;
	ll used[m]={0} ,sum[m] = {0};
	ll a = x ,s = 0;
	bool cycle = 0;
	for(ll i = 1 ;i <= n ;){
		if(used[a] && !cycle){
			ll cycleSum = s - sum[a];
			ll cycleLen = i - used[a];
			ll rounds = (n - i - 1) / cycleLen;
			s += rounds * cycleSum;
			i += rounds * cycleLen;
			cycle = 1;
			continue;
		}
		used[a] = i;
		sum[a] = s;
		s += a;
		a = a*a % m;
		i++;
	}
	cout << s;

}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
