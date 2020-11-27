#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
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

using namespace std;


#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}
#endif

const long long MAXN = 1e5 +7;

int f( string s ){
	if( s == "Anka" ) return 0;
	if( s == "Chapay" ) return 1;
	if( s == "Cleo" ) return 2;
	if( s == "Troll" ) return 3;
	if( s == "Dracul" ) return 4;
	if( s == "Snowy" ) return 5;
	if( s == "Hexadecimal" ) return 6;
}

void check(){
	int n, mas[ 8 ][ 8 ] = {0};
	string s;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		cin >> s;
		int x1 = f( s );
		cin >> s >> s;
		int x2 = f( s );
		mas[ x1 ][ x2 ] = 1;
	}
	int a, b, c, mn = -1, symph;
	cin >> a >> b >> c;
	for( int i = 1 ; i < 6 ; i++ )
		for( int j = 1 ; j < 6 ; j++ )
			if( i + j < 7 ){
				int ma[ 8 ];
				for( int k = 0 ; k < 7 ; k++ )
					ma[ k ] = k;
				do{
					int op1 = a / i, op2 = b / j, op3 = c / ( 7 - i - j );
					int mmx = max( op1, max( op2, op3 ) ), mmn = min( op1, min( op2, op3 ) );
 
					if( mn == -1 || ( mmx - mmn < mn ) ){
						mn = mmx - mmn;
						symph = 0;
						for( int x = 0 ; x < i ; x++ )
							for( int y = 0 ; y < i ; y++ )
								symph += mas[ ma[x] ][ ma[y] ];
						for( int x = i ; x < i + j ; x++ )
							for( int y = i ; y < i + j ; y++ )
								symph += mas[ ma[x] ][ ma[y] ];
						for( int x = i + j ; x < 7 ; x++ )
							for( int y = i + j ; y < 7 ; y++ )
								symph += mas[ ma[x] ][ ma[y] ];
					}
					else if( mmx - mmn == mn ){
						int symph1 = 0;
						for( int x = 0 ; x < i ; x++ )
							for( int y = 0 ; y < i ; y++ )
								symph1 += mas[ ma[x] ][ ma[y] ];
						for( int x = i ; x < i + j ; x++ )
							for( int y = i ; y < i + j ; y++ )
								symph1 += mas[ ma[x] ][ ma[y] ];
						for( int x = i + j ; x < 7 ; x++ )
							for( int y = i + j ; y < 7 ; y++ )
								symph1 += mas[ ma[x] ][ ma[y] ];
						symph = max( symph, symph1 );
					}
 
				}
				while( next_permutation( ma, ma + 7 ) );
			}
	cout << mn << " " << symph << '\n';
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
