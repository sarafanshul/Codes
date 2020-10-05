#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
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

struct dijkstra {
  #define int ll
  #define s second
  #define f first
  int n;
  const ll inf = 4e18;
  vector<ll> dists; /* for a single run */
  vector<int> par;
  vector<bool> vis;
  vector<vector<pair<ll, int> > > edges; /* weight, to */
  
  void init(int s) {
    n = s;
    dists = vector<ll>(n);
	  vis = vector<bool>(n);
    par = vector<int>(n);
    edges = vector<vector<pair<ll, int> > >(n);
  }
 
  void edge(int a, int b, ll wt) {
    edges[a].push_back(make_pair(wt, b));
  }
 
  using ptype = pair<ll, int>;
  void run(int src) {
    fill(dists.begin(), dists.end(), inf);
	  fill(vis.begin(), vis.end(), false);
    fill(par.begin(), par.end(), -1);
 
    priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
    dists[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
      ptype foc = pq.top();
      pq.pop();
	  
	    if (vis[foc.s]) continue;
	    vis[foc.s] = 1;
	  
      dists[foc.s] = min(dists[foc.s], foc.f);
      for (ptype x: edges[foc.s]) {
        ll d = dists[foc.s] + x.f;
        if (d < dists[x.s]) {
          dists[x.s] = d;
          par[x.s] = foc.s;
          pq.push(make_pair(d, x.s));
        }
      }
    }
  }
};

pair<pair<ll, ll>, ll> p[100005];

dijkstra d;

void check(){
	ll n ,m ,sx ,sy ,fx ,fy;
	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;
	for(int i = 0 ;i < m ;i++){
		cin >> p[i].F;
		p[i].S = i;
	}
	d.init(m+2); // start -> m ;end -> m+1;
	d.edge(m ,m+1 ,abs(sx-fx) + abs(sy - fy)); // manhattan dist start->end
	for(ll i = 0 ;i < m ;i++){
		d.edge(m ,i ,abs(sx - p[i].F.F)); // latral dist from x&y; 
		d.edge(m ,i ,abs(sy - p[i].F.S));

		d.edge(i ,m+1 ,abs(fx - p[i].F.F) + abs(fy - p[i].F.S)); // manhattan dist form Mi->end;
	}
	sort(p ,p+m);
	// connecting portals on nearest(X);
	for(ll i = 0 ;i < m; i++){
		if(i > 0){
			d.edge(p[i].S ,p[i-1].S ,abs(p[i].F.F - p[i-1].F.F));		}
		if(i < m -1){
			d.edge(p[i].S ,p[i+1].S ,abs(p[i].F.F - p[i+1].F.F));
		}
	}
	// connecting portals on nearest(Y);
	for(ll i = 0 ;i < m ;i++) swap(p[i].F.F ,p[i].F.S);
	sort(p ,p+m);
	for(ll i = 0 ;i < m ;i++) swap(p[i].F.F ,p[i].F.S);
	for(ll i = 0 ;i < m ;i++){
		if(i > 0){
			d.edge(p[i].S ,p[i-1].S ,abs(p[i].F.S - p[i-1].F.S));
		}
		if(i < m -1){
			d.edge(p[i].S ,p[i+1].S ,abs(p[i].F.S - p[i+1].F.S));
		}
	}
	d.run(m);
	cout << d.dists[m+1];

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
