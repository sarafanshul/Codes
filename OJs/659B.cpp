/*
Editorial 

Let's define positions i such that (1≤i≤n) and di+k≤l as safe positions, also positions 0 and n+1 are safe too (ie. the shore and the island respectively). Remaining positions are unsafe.

Koa can wait indefinitely on safe positions without drowning, so she can reach the island (ie. position n+1) if and only if she can reach each safe position from the previous one.

Suppose Koa is at some safe position i and wants to reach the next safe position j (0≤i<j≤n+1):

A solution strategy for Koa is the following:

	-> If Koa is at an unsafe position x at time t0, she must swim to x+1 as soon as she can, that is, at the first moment of time t≥t0 such that dx+1+p[(t+1)mod2k]≤l (to not drown).
	-> If Koa is at a safe position x at time t0, she must wait to some moment of time t1 such that tide is exactly at k units. After that she must follow the unsafe positions strategy until the next safe position.

So a way to go from i to j would be, apply point 2 on i, and apply point 1 to reach each position p such that (i<p≤j).

This works because:

	-> If there exists some position with dp greater than l she would drown with any tide so let's assume that all positions are less or equal to l.
	-> Suppose Koa drowns at some position p, she can leave i with some value of tide because di+1≤l and as long as the tide is decreasing whether she chooses to wait or not she would be safe. So she must have drown with the tide increasing.
	-> If she leaves i with other tide (different from k): suppose she would be able to reach position p, then the tide will have increased and it will be higher and therefore she would drown too, this is true because the tide never can be k and start decreasing again between i and j because these positions are unsafe ones.

Time complexity: O(n) per test case

*/
#include <bits/stdc++.h>
using namespace std;

void check(){
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> d(n+1), safe = { 0 };
	for (int i = 1; i <= n; ++i){
			cin >> d[i];
			if (d[i] + k <= l)
				safe.push_back(i);
	}

	safe.push_back(n+1);
	bool ok = true;
	for (size_t i = 1; i < safe.size() && ok; ++i){
		int tide = k; bool down = true;
		for (int j = safe[i-1] + 1; j < safe[i]; ++j) {
			tide += down ? -1 : +1;
			if (down) tide -= max(0, d[j] + tide - l);
			if (tide < 0 || d[j] + tide > l) { ok = false; break; }
			if (tide == 0) down = false;
			}
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		check();
	}
	return 0;
}