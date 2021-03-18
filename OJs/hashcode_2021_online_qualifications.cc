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

const long long MAXN = 3e5 +7;

#define int ll 
vector<pair<ll ,ll>> adj[MAXN] ;
map<string , ll> mp_in , mp_out , len ;
bool visited[MAXN] = {0} ;

int x1;
void dfsUtil(int v ,int count ,int& maxCount ){
	visited[v] = 1;
	count++;
	for(auto &[u,  w] : adj[v]){
		if(!visited[u]){
			if(count >= maxCount){
				maxCount = count;
				x1 = u;
			}
			dfsUtil(u ,count ,maxCount);
		}
	}
}

void dfs(int v ,int& maxCount ){
	memset(visited ,0 ,sizeof(visited));
	int count = 0;
	dfsUtil(v ,count + 1 ,maxCount );
}
 
int diameter(int v){
	int maxCount= INT_MIN;
	dfs(v ,maxCount );
	dfs(x1 ,maxCount );
	return maxCount;
}

void check1( string ii ){
	ofstream cout (ii+"-ans.txt");ifstream cin (ii+".txt");
	for(ll i = 0 ; i < MAXN ; i++){adj[i ].clear() ;}
	mp_in.clear() ;mp_out.clear() ;len.clear() ;

	ll D , I , S , V , F ;
	cin >> D >> I >> S >> V >> F ;

	for(ll i = 0 ; i < S ; i++){
		ll u , v , L ;
		string s ; 
		cin >> u >> v >> s >> L;
		adj[u].PB( MP( v , L ) ) ;
		mp_in[ s ] = u ; 
		mp_out[ s ] = v ;
		len[s] = L ;
	}
	vector<vector<string >> CARS( V ) ; 
	vector<ll> dist( V ) ;
	vector<ll> num_nodes( V ) ;
	map<string , ll > ans ; 
	map<ll, set<string> > income ;

	ll dia = diameter( 0LL) ;

	for(ll i = 0 ; i < V ; i++){
		ll X ; 
		cin >> X ;
		num_nodes[i] = X ;
		for(ll j = 0 ; j < X ; j++){
			string s ; 
			cin >> s ;
			CARS[i].PB( s ) ;
			dist[i] += len[ s ] ;
		}
	}

	vector<ll> srt(V) ;
	iota( ALL(srt ) , 0 ) ;
	sort( ALL(srt) , [&]( const ll xx , const ll yy){
		return dist[xx] > dist[yy] ;	
	} ) ;

	for(ll i = 0 ; i < V ; i++){
		ll idx = srt[i] ;

		if ( dist[idx] <= D ){
			for( string &x : CARS[idx] ){
				income[ mp_out[ x ] ].insert( x ) ;
				ans[ x ]++ ;
			}
		}
	}

	cout << income.size() << '\n' ;

	for(auto it : income){
		cout << it.F << '\n' << it.S.size()  << '\n' ;
		for( const auto  val : it.S ){
			cout << val << ' ' << ans[ val ] << '\n' ;
		}
	}
}

void check(){
	// Get-Content .\b.txt | .\a.exe > .\b-ans.txt
	for(char i = 'a' ; i <= 'f'; i++){
		string ii = "" ;
		ii += i ;
		check1( ii ) ;
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
