
/*if we have several consecutive -x, they must be in an ascending order 
(otherwise we say NO and stop instantly)
if we have + and a -x after it, we can collapse them 
(it's not hard to understand that if the answer is YES, 
 we can act this way, just a simple mindfulness exercise)
Bingo! We've just solved this problem in O(n) using stack 
(going in the reversed order, putting goods on a stack and 
 then taking them from the top of the stack and putting on the showcase). 
The only tricky moment left: 
  you must pay attention to the amount of shurikens to avoid the lack of them 
  (e.g. example 2 from the problem).*/
/*
we can create an array like this [-1,-1,2,-1,3,-1,1,4] 
where -1 indicates that the element was inserted(+ sign). 
Now maintain a min-heap. Iterate backward on this array, 
we will keep on inserting the elements. We will first insert 4 and 1. 
Now whenever we land on -1, it means at this point, 
some shuriken must have been added on the showcase) which can only be either 4 or 1
(Since they are sold at the last). 
So, we can safely remove the minimum element from the heap and add it to the answer. 
If the heap is found empty at -1 or if we find one of the element in the heap is less 
than the element to be insert then the array is inconsistent. 
Also, we can check if number of +'s is equal to n.
If it is not equal then the answer is "NO"
*/
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

void check(){
	ll n;
    cin >> n;
    vector<ll> arr(2 * n, -1);
    ll c = 0;
    for (ll i = 0;i < 2 * n;i++){
        char ch;
        cin >> ch;
        if (ch == '+'){ c++; continue; }
        ll x;
        cin >> x;
        arr[i] = x; 
    }
    if (c != n) { cout << "NO" << '\n'; return; }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> ans(n); 
    ll x = n - 1; 
    for (ll i = 2 * n - 1; i >= 0; i--){
        if (arr[i] == -1) {
            if (pq.empty()) { cout << "NO" << '\n'; return; }
            ans[x--] = pq.top();
            pq.pop();
            continue;
        } else {
            if (!pq.empty() && arr[i]>pq.top()) { cout << "NO" << '\n'; return; }
            pq.push(arr[i]);
        }
    }
    cout << "YES" << '\n'; 
    for (auto x : ans) cout << x << " ";
    cout << '\n'; 
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
