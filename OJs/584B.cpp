/*

Give an n to indicate that 3 * n people are sitting at a table

You want to send money to everyone, 
 you can send 1, 2, 3, the i-th person's money is ai (i starts from 0)

There is a requirement: 
	a ia i  +  n  +  a i  + 2 n  ≠ 6 , 
	then Tanya is satisfied., then Tanya is satisfied.

That is, as long as there is a group that 
	a i  +  a i  +  n  +  a i  + 2 n  ≠ 6 ,   ...

Problem-solving ideas:

For n = 1, we can find that the triangle has 20 conditions that meet the conditions, 
	and 7 types that do not meet the conditions;

We can think of it this way, as long as at least one situation is satisfied, so we think about it from its opposite,

Is the total quantity minus its unsatisfied quantity, 
	which is also
	=> ret == 27 ^ n --  7 ^ n

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
const ll MOD = 1e9 + 7;

template<typename T = long long >
T fastExpo(T a, T n) {
    T ans = 1;
    while(n >= 1) {
        if(n % 2 == 0) {a = (1LL * a * a) % MOD;n /= 2;}
        else {ans = (1LL * ans * a) % MOD; n--;}
    }
    return ans;
}

void check(){
	ll n;
	cin >> n;
	cout << (fastExpo(27LL ,n) - fastExpo(7 ,n) + MOD)%MOD;	
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
