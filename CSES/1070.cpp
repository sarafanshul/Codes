#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
  	cin >> n;
  	if (n == 1) cout << "1\n";
  	else if (n < 4) cout << "NO SOLUTION\n";
  	else if (n == 4) cout << "3 1 4 2\n";
  	else {
    	for (int i = 1; i <= n; i += 2) cout << i << " ";
    	for (int i = 2; i <= n; i += 2) {
      	cout << i;
      	if (i < n - 1) cout << " ";
    	}
  	}

	return 0;
}
