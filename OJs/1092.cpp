// #include <bits/stdc++.h>

// #define ALL(x) x.begin(),x.end()
// #define PB push_back
// #define EB emplace_back
// #define F first
// #define S second
// #define ll long long

// using namespace std;
// const int MOD = 1e9+7;

// int main(){
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
// 	int n ;
// 	cin >> n;
// 	// int _sm = n*(n+1)/2;
// 	// if (_sm&1){
// 	// 	cout << "NO";
// 	// }
// 	// else{
// 	// 	cout << "YES\n";
// 	// 	if (n == 4){
// 	// 		cout << "2\n4 1\n 2\n3 2";
// 	// 	}
// 	// 	// vector<bool>a(n+1 ,1);
// 	// 	bitset<32> a((1LL<<32)-1);
// 	// 	int _md = _sm/2;
// 	// 	int cnt = 0;
// 	// 	for(int i = n ; i > 0 && _md != 0 ;--i){
// 	// 	  //  cout << _md<<"\n";
// 	// 		if(_md < 10 && a[_md]){
// 	// 			a[_md] = 0;
// 	// 			_md = 0;
// 	// 			cnt++;
// 	// 		}
// 	// 		else if(a[i]){
// 	// 			a[i] = 0;
// 	// 			_md -= i;
// 	// 			cnt++;
// 	// 		}
// 	// 	}
// 	// 	cout << cnt<<"\n";
// 	// 	for(int i = 1 ; i<= n ;i++){
// 	// 		if (!a[i]) cout << i<<" ";
// 	// 	}
// 	// 	cout<<"\n" << n-cnt << "\n";
// 	// 	for(int i = 1 ; i<= n ;i++){
// 	// 		if (a[i]) cout << i<<" ";
// 	// 	}
// 	// }

// 	return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  ll t = n * (n + 1) / 2;
  if (t % 2) cout << "NO\n";
  else {
    t /= 2;
    vector<int> a;
    ll s = 0;
    ll e = 0;
    ll i = n;
    while (true) {
      a.push_back(i);
      s += i--;
      e = t - s;
      if (!e) break;
      if (e <= i) {
        a.push_back(e);
        break;
      }
    }
    cout << "YES\n" << a.size() << endl;
    for (int j = 0; j < a.size(); j++) {
      cout << a[j];
      if (j < a.size() - 1) cout << " ";
    }
    cout << endl;
    cout << n - a.size() << endl;
    for (ll j = i; j > 0; j--) {
      if (j == e) continue;
      cout << j;
      if ((e != 1 && j > 1) || (e == 1 && j > 2)) cout << " ";
    }
    cout << endl;
  }
}