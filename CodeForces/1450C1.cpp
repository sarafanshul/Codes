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
	ll n;
	cin >> n;
	char a[1000][1000] ;
	memset(a ,'.' ,sizeof(a));
	string s;
	for(ll i = 2 ; i < n+2 ; i++){
		cin >> s;
		for(ll j = 0 ; j < n ; j++){
			a[i][j+2] = s[j];
		}
	}
	n += 2;
	ll cnt = 0 ,tot = 0;

	for(ll i = 2 ; i < n ; i++){
		for(ll j = 2 ; j < n; j++ ){
			tot += (a[i][j] == 'X');
		}
	}
	print();

	auto val = [&](ll i ,ll j) -> char {
		cnt++;
		if(a[i][j] == 'O') return 'X';
		else return 'O';
	};
	const ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

	auto go = [&](ll i ,ll j){
		// for 1 ,1
		auto ok = [&](ll ii ,ll jj ,ll x ,ll y) -> bool {
			return (( a[ii][jj] == a[x][y] ) && (a[x][y] != '.') );
		};

		auto can = [&](ll x , ll y) -> bool { // all			
			bool f = 0;
			for(ll z = 0 ; z < 2 ; z++){
				ll xx = dx[z] ,yy = dy[y];
				if( ok(x ,y ,x ,y) && ok(x - xx ,y - yy ,x ,y) && ok(x - xx*2 ,y - yy*2 ,x ,y)){ 
					return true ;
				}
			}
			return false ;
		};

		if(a[i][j] == '.') return ;
		if( can(i ,j)){
			a[i][j] = val(i ,j);
			if(can(i ,j)){
				a[i-1][j] = val(i-1 ,j);
				a[i][j-1] = val(i ,j-1);
				a[i][j] = val(i ,j);
			}
		}
	};

	for(ll i = 2 ; i <= n ; i++){
		for(ll j = 2 ; j <= n ; j++){
			go(i ,j);
			print(i ,j);
			for(ll x = 2 ; x < n ; x++){
				for(ll y = 2 ;y < n ; y++){
					cout << a[x][y] ;
				}cout << '\n';
			}
		}
	}
	// assert(cnt <= tot/3);
	print(cnt , tot);
	for(ll i = 2 ; i < n ; i++){
		for(ll j = 2 ; j < n ; j++){
			cout << a[i][j] ;
		}cout << '\n';
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
