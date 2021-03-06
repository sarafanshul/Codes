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

const int N = 50000;
int cnt[27];
string s; int n;
int counter;

bool valid(){return (counter == 26);}

void fillall(){for(int i = 0; i < n; i++){if(s[i] == '?') s[i] = 'A';}}

void check(){
	cin >> s;
	n = s.length();
	if(n < 26) {cout << -1; return;}
	counter = 0;
	for(int i = 0; i < 26; i++){
		if(s[i] == '?'){
			counter++; continue;
		}
		cnt[s[i]-'A']++;
		if(cnt[s[i]-'A'] == 1) counter++;
	}
	if(valid()){
		int cur = 0;
		while(cnt[cur]>0) cur++;
		for(int i = 0; i < 26; i++){
			if(s[i] == '?'){
				s[i] = cur + 'A';
				cur++;
				while(cnt[cur]>0) cur++;
			}
		}
		fillall();
		cout << s;
		return;
	}
	for(int i = 26; i < n; i++){
		if(s[i] != '?') {cnt[s[i]-'A']++; if(cnt[s[i]-'A']==1) counter++;}
		if(s[i-26] != '?') {cnt[s[i-26]-'A']--; if(cnt[s[i-26]-'A']==0) counter--;}
		if(s[i-26] == '?') counter--;
		if(s[i] == '?') counter++;
		if(valid()){
			int cur = 0;
			while(cnt[cur]>0) cur++;
			for(int j = i - 25; j <= i; j++){
				if(s[j] == '?'){
					s[j] = cur + 'A';
					cur++;
					while(cnt[cur]>0) cur++;
				}
			}
			fillall();
			cout << s;
			return;
		}
	}
	cout << -1;
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
