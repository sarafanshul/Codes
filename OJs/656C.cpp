
/*
Consider the maximum element amx of the good array a of length k. 
Then we can notice that the array a looks like [a1≤a2≤⋯≤amx≥⋯≥ak−1≥ak]. 
And this is pretty obvious that if the array doesn't have this structure, 
 then it isn't good (you can see it yourself). So we need to find the longest
 such suffix. It's pretty easy doable with pointer: initially, 
 the pointer pos is at the last element. Then, while pos>1 and apos−1≥apos, 
 decrease pos by one. If we're done with the previous step, we do the same, 
 but while pos>1 and apos−1≤apos. 
The answer is pos−1.
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;

void check(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0 ; i  <n ; ++i) cin >> a[i];
	int pos = n - 1;
	while (pos > 0 && a[pos - 1] >= a[pos]) --pos;
	while (pos > 0 && a[pos - 1] <= a[pos]) --pos;
	cout << pos << "\n";
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		check();
	}
}
