#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;


int check(int n) { 
	int count = 0; 
	for (int i = 5; n / i >= 1; i *= 5) count += n / i;
	return count; 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,m;
	cin >>n;
	cout << check(n);

	return 0;
}
