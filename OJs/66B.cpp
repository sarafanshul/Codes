// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
// header(s)
#include <bits/stdc++.h>
 
// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
 
// namespaces
using namespace std;
 
// global declerations
const size_t MAXN = 1e5 +7;
 
 
void check(){
	int n;
	cin >> n;
	int cnt = 0;
	int a[n+1];
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	int left[n+1] ,right[n+1];
	// min then right 
// 	right[0] = 0;  
	for(int i = 0 ; i < n; i++){
	    int j = i+1;
	    int k = i;
	    while((j<n)&&( a[k] >= a[j])) j++ ,k++;
	    right[i] = j-i-1;
	}
	// for min left
// 	left[n-1] = 0;
	for(int i = n-1; i >= 0 ;i--){
	    int j = i-1 ,k = i;
	    while((j>=0) && (a[k] >= a[j])) j-- ,k--;
	    left[i] = i-j-1;
	}
// 	for(int i = 0; i < n; i++) cout << right[i] << " ";
// 	cout << "\n";
// 	for(int i = 0; i < n; i++) cout << left[i] << " ";
// 	cout << "\n";
	int ans = 0;
	for(int i=0 ; i < n ;i++){
	    ans = max(ans ,right[i]+left[i]+1);
	}
	cout << ans;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
// 	cin.exceptions(cin.failbit);
 
	int t = 1;
// 	cin >> t;
 
	while(t--){
		check();
	}
 
	return 0;
}
