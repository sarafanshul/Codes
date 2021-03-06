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

const size_t MAXN = 2*(1e5 +7);

struct node{
    int l,r,sum;
}bitree[MAXN*4];

vector<ll> adj[MAXN];
ll n ,m ,_time = 1;
ll lef[MAXN] ,rig[MAXN] ,lazy[MAXN*4];
bool is_on[MAXN] = {0};

void pushdown(int nod){
    if(!lazy[nod] || bitree[nod].l == bitree[nod].r)
        return ;
    lazy[nod] ^= 1;
    int l = bitree[nod].l;
    int r = bitree[nod].r;
    int mid = (bitree[nod].l + bitree[nod].r )/2;
    bitree[nod<<1].sum = mid-l+1-bitree[nod<<1].sum;
    bitree[nod<<1|1].sum = r-mid-bitree[nod<<1|1].sum;
    lazy[nod<<1] ^= 1;
    lazy[nod<<1|1] ^= 1;
    bitree[nod].sum = bitree[nod<<1].sum + bitree[nod<<1|1].sum;
}

int get_ans(int nod,int l,int r,int L,int R){
    pushdown(nod);
    int mid = (L+R)/2;
    if(L>=l && R<=r)
        return bitree[nod].sum;
    else if(mid < l)
        return get_ans(nod<<1|1,l,r,mid+1,R);
    else if(mid >= r)
        return get_ans(nod<<1,l,r,L,mid);
    else
        return get_ans(nod<<1,l,mid,L,mid) + get_ans(nod<<1|1,mid+1,r,mid+1,R);
}

void init_bitree(int nod,int L,int R){
    bitree[nod].l = L;
    bitree[nod].r = R;

    if(L == R){
        if(is_on[L])
            bitree[nod].sum = 1;
        return ;
    }
    int mid = (L + R) / 2;
    init_bitree(nod<<1|1,mid+1,R);
    init_bitree(nod<<1,L,mid);
    bitree[nod].sum = bitree[nod<<1].sum + bitree[nod<<1|1].sum;
}

void make_lazy(int nod,int l,int r,int L,int R){
    pushdown(nod);
    if(L>=l && R<=r){
        lazy[nod] ^=1;
        bitree[nod].sum = r - l + 1 - bitree[nod].sum;
        return ;
    }
    int mid = (L + R) / 2;
    if(mid >= r)
        make_lazy(nod<<1,l,r,L,mid);
    else if(mid < l)
        make_lazy(nod<<1|1,l,r,mid+1,R);
    else{
        make_lazy(nod<<1,l,mid,L,mid);
        make_lazy(nod<<1|1,mid+1,r,mid+1,R);
    }
    bitree[nod].sum = bitree[nod<<1].sum + bitree[nod<<1|1].sum;
}

void dfs(int v){
	lef[v] = _time;
	for(int u : adj[v]){
		_time++;
		dfs(u);
	}
	rig[v] = _time;
}

void check(){
	ll u;
	cin >> n;
	for(int i = 2 ;i <= n; i++){
		cin >> u;
		adj[u].PB(i);
	}
	dfs(1);
	for(int i = 1 ;i <= n ;i++){
		cin >> u;
		if(u) is_on[lef[i]] = 1;
	}
	init_bitree(1 ,1 ,n);
	ll q ,ans= 0;
	char s[100];
	cin >> q;
	while(q--){
		cin >> s >> u;
		ans = 0;
		if(s[0] == 'p'){
			make_lazy(1 ,lef[u] ,rig[u] ,1 ,n);
		} else {
			ans = get_ans(1 ,lef[u] ,rig[u] ,1 ,n);
			cout << ans << "\n";
		}
	}

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
