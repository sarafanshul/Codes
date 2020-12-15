/*
HOW

EDITORIAL:->

Key Idea:
 We can block all empty neighbouring cells of bad people and 
 then check if all good people can escape and no bad people are able to escape.

Solution:

 Consider all the neighbouring cells of bad people. 
 There shouldn't be any path from these cells to the cell (n,m). 
 If there is a path from any such cell, 
 the bad person adjacent to that cell can also then reach the cell (n,m). 
 So, if any good and bad people are in adjacent cells, 
 the answer is "No".


Based on this idea, we can block any empty cell neighbouring a bad person. 
 Suppose there is another solution in which a cell (i,j) 
 neighbouring a bad person does not need to be blocked. 
 There still won't be any path from (i,j) to (n,m) in that solution. 
 So we can block (i,j) in that solution too without affecting the solution itself.


It is sufficient to block only the empty neighbouring cells of 
 bad people and check the required conditions, which can be done using a bfs on the grid.

Proof:

We will assume there are no adjacent good and bad people since in that case, 
 the answer is "No". There are three cases:

 -> A bad person is adjacent to the cell (n,m). 
     In this case, the cell (n,m) must be blocked. 
     Now no one will be able to escape. 
     If there is at least one good person present, 
     the answer is "No".
-> If after blocking the neighbouring cells of bad people, 
     there is some good person who is not able to escape, 
     then the answer is again "No".
-> Otherwise, the answer is always "Yes". 
     Suppose there is some path from a bad person at cell 
     (i,j) to the cell (n,m). One of the neighbours of this person 
     must be another bad person since the only other case is an adjacent 
     good person (which is already covered above). 
     Extending this, all the cells on the path from (i,j) to (n,m) must 
     have bad people. This is not possible since in this case, there must be a 
     bad person adjacent to (n,m) and this case is already covered above.

Time complexity: O(n⋅m)
https://codeforces.com/blog/entry/78504
*/

#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;

const ll N = 55LL;

ll n ,m;
char arr[N][N];
ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool valid(ll i ,ll j) {return i >= 1 && i <= n && j >= 1 && j <= m; }


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll t;
	cin >> t;
	
	while(t--){
		cin >> n >> m;
		for (ll i = 1; i <= n; i++){
			cin >> (arr[i] + 1);
		}

		for (ll i = 1 ;i <= n ; ++i){
			for (ll j = 1 ; j <= m ; ++j){
				if (arr[i][j] == 'B'){
					for(ll k = 0; k < 4 ; k++){
						ll ni = i + dir[k][0];
						ll nj = j + dir[k][1];
						if (valid(ni ,nj) && arr[ni][nj] == '.')
							arr[ni][nj] = '#';
					}
				}
			}
		}

		queue<pair<ll ,ll>> que;
		bool visited[n + 5][m + 5];
		memset(visited ,false  ,sizeof(visited));

		if (arr[n][m] == '.'){
			que.push({n ,m});
			visited[n][m] = true;
		}
		while(!que.empty()){
			pair curr = que.front();
			que.pop();
			for (ll k = 0 ;k < 4 ;++k){
				ll ni = curr.F + dir[k][0];
				ll nj = curr.S + dir[k][1];
				if (valid(ni ,nj) && !visited[ni][nj] && arr[ni][nj] != '#'){
					que.push({ni ,nj});
					visited[ni][nj] = true;
				}
			}
		}

		bool good = true;
		for (ll i = 1; i <= n; i++){
			for (ll j = 1 ; j <= m; j++){
				if ((arr[i][j] == 'G' && !visited[i][j]) || 
					(arr[i][j] == 'B' && visited[i][j])){
					good = false;
					break;
				}
			}
		}
		cout << (good ? "YES" : "NO") <<"\n";
	}
	
	return 0;
}