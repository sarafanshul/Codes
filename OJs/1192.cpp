#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;
const int MOD = 1e9+7;
int n ,m;
bool grid[1005][1005];

int dirs[4][2] = {{1 ,0} ,{0 ,1} ,{-1 ,0} ,{0 ,-1}};

bool is_valid(int i ,int j){
	if (i >= 0 && j >= 0 && i < n && j < m ) return true;
	return false;
}

void dfs(int i ,int j){
	if (grid[i][j]) return;
	grid[i][j] = 1;
	for(auto u : dirs){
		int x = u[0];int y = u[1];
		if (is_valid(i+x ,j+y)){
			dfs(i+x ,j+y);
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int count = 0;
	string s;
	for(int i = 0; i < n; i++){
	    cin >> s;
		for(int j = 0; j < m ; j++){
			if (s[j] == '#') grid[i][j] = 1;
			else grid[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m ; j++){
			if (!grid[i][j]){
				dfs(i ,j);
				count++;
			}
		}
	}
    cout << count;
	return 0;
}
