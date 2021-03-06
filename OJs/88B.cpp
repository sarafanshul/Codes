#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const size_t MAXN = 1e5 +7;

template<typename B = bool ,typename T = long long >
B calc(T i ,T j ,T xx , T yy ,T x){
	double ans = sqrt(pow(xx - j, 2) + pow(yy - i, 2) * 1.0);
	ans = ceil(ans);
	if(ans <= x) return 0;
	return 1;
}

bool can[26];
int n, m, k, q, res = 0;
char key[31][31];
char text[1000000];
vector<pair<int, int>> posKey[26], shift;
 
int dist(int i, int j, int shr, int shc){
	return (i - shr)*(i - shr) + (j - shc)*(j - shc);
}
 
bool check(int i, int j){
	for (int w = 0;w < shift.size();w++){
		int dis = dist(i, j, shift[w].first, shift[w].second);
		if (dis <= k*k)
			return true;
	}
	return false;
}
 

void check(){
	cin >> n >> m >> k;
	for (int i = 0;i < n; i++) cin >> keys[i];

	for (int i = 0;i<n;i++){
		for (int j = 0;j < m;j++){
			if (key[i][j] == 'S') shift.push_back(make_pair(i, j));// position of each key
			else posKey[key[i][j] - 'a'].push_back(make_pair(i, j));
		}
	}

	for (int i = 0;i<26; i++){
		for (int j = 0;j <posKey[i].size() && !can[i]; j++){
		//check of each key if can press on it with one hand
			can[i] = can[i] | check(posKey[i][j].first, posKey[i][j].second);
		}
	}

	cin >> q >> text;
	for (int i = 0;i < q;i++){
		if (islower(text[i])){
			if (posKey[text[i] - 'a'].empty()){res = -1;break;}
		}else{
			text[i] = tolower(text[i]);
			if (shift.empty() || posKey[text[i] - 'a'].empty()){res = -1;break;}
			if (!can[text[i] - 'a'])++res;
		}
	}
	cout << res << "\n";
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
