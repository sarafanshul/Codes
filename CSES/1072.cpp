/*
Note that when we have two knights threatening each other, 
 it actually forms either a 2×3 or 3×2 board. 
 And for each of 2×3 and 3×2 boards, 
 there are 2 ways of placing two knights so that they threaten each other. 
 So, what we should do is to count how many 2×3 and 3×2 squares on n×n board. 
 For general n, the answer is
				=> (n−1)(n−2)+(n−2)(n−1) = 2(n−1)(n−2)

And for each 2×3 and 3×2 board, 
 there are 2 ways of placing the knights so that they 
 threaten each other. Therefore, in total there are
				=> 2⋅2(n−1)(n−2)=4(n−1)(n−2)

	ways of placing two knights so that they threaten each other. 
 So what you are looking for is
				=> n^2(n^2−1)/2 − 4(n−1)(n−2) 

It is also worth mentioning that we are not over-counting because whenever 
we place two knights so that they threaten each other, 
either a 2×3 or 3×2 board must contain both of the knights.

*/

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
	ll n ;
	ll sm_b ,sm_k;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		sm_b = (i*i)*((i*i) - 1)/2;
		sm_k = 4*(i-1)*(i-2);
		cout << sm_b - sm_k << "\n";
	}

	return 0;
}
