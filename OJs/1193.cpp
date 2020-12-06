/*
The idea is inspired from Lee algorithm and uses BFS.

=> We start from the source cell and calls BFS procedure.
=> We maintain a queue to store the coordinates 
	of the matrix and initialize it with the source cell.
=> We also maintain a Boolean array visited of same size as 
	our input matrix and initialize all its elements to false.
	=> We LOOP till queue is not empty
	=> Dequeue front cell from the queue
	=> Return if the destination coordinates have reached.
	=> For each of its four adjacent cells, 
		if the value is 1 and they are not visited yet, 
		we enqueue it in the queue and also mark them as visited.
Note that BFS works here because it doesn’t consider a single 
path at once. It considers all the paths starting from the source and moves 
ahead one unit in all those paths at the same time which makes 
sure that the first time when the destination is visited, it is the shortest path.
*/


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
int grid[1005][1005];

int dirs[4][2] = {{1 ,0} ,{0 ,1} ,{-1 ,0} ,{0 ,-1}};

bool ok = false;
string ans = ""; 
bool is_valid(int i ,int j){
	if (i >= 0 && j >= 0 && i < n && j < m ) return true;
	return false;
}
int32_t _mn = INT_MAX;
void dfs(int i ,int j ,string path){
	if (grid[i][j] == 1) return;
	if (grid[i][j] == 3) {ok = true;
		// cout << path << "\n";
		if (_mn > path.size()){
			ans = path; _mn = path.size();}
		return;}
	grid[i][j] = 1;
	int32_t p = 0;
	for(auto u : dirs){
		int x = u[0];int y = u[1];
		if (is_valid(i+x ,j+y)){
			if (p == 0)
				dfs(i+x ,j+y ,path+'D');
			if (p == 1)
				dfs(i+x ,j+y ,path+'R');
			if (p == 2)
				dfs(i+x ,j+y ,path+'U');
			if (p == 3)
				dfs(i+x ,j+y ,path+'L');
		}
		p++;
	}
	// grid[i][j] = 0;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

  	int n, m;
  	cin >> n >> m;
	vector<vector<char>> a(n);
	vector<vector<int>> b(n);
    int ai, aj, bi, bj;
    for (int i = 0; i < n; i++) {
		a[i] = vector<char>(m);
		b[i] = vector<int>(m, -1);

		for (int j = 0; j < m; j++) {
	  		cin >> a[i][j];
	  		if (a[i][j] == 'A') {
				ai = i; aj = j;
	  		} else if (a[i][j] == 'B') {
				bi = i; bj = j;
	  		}
		}
  	}
  	queue<tuple<int ,int ,int>> q;
  	q.push(make_tuple(ai, aj, 0));
  	while (!q.empty()) {
		int i, j, k;
		tie(i, j, k) = q.front();
		q.pop();
		if (b[i][j] != -1) continue;
		b[i][j] = k;
		if (i == bi && j == bj) {
		  	cout << "YES\n" << b[i][j] << "\n";
		  	string p;
		  	while (i != ai || j != aj) {
				if (i > 0 && b[i - 1][j] == k - 1) {
			  		p.push_back('D');
			  		i--;
				} else if (i < n - 1 && b[i + 1][j] == k - 1) {
				  	p.push_back('U');
				  	i++;
				} else if (j > 0 && b[i][j - 1] == k - 1) {
				  	p.push_back('R');
				  	j--;
				} else {
				  	p.push_back('L');
				  	j++;
				}
			k--;
		  	}
		  	reverse(p.begin(), p.end());
		  	cout << p << endl;
		  	return 0;
		}
		if (i > 0 && a[i - 1][j] != '#' && b[i - 1][j] == -1)
	  		q.push(make_tuple(i - 1, j, k + 1));
		if (i < n - 1 && a[i + 1][j] != '#' && b[i + 1][j] == -1)
	  		q.push(make_tuple(i + 1, j, k + 1));
		if (j > 0 && a[i][j - 1] != '#' && b[i][j - 1] == -1)
	 		q.push(make_tuple(i, j - 1, k + 1));
		if (j < m - 1 && a[i][j + 1] != '#' && b[i][j + 1] == -1)
	  		q.push(make_tuple(i, j + 1, k + 1));
  	}
  	cout << "NO\n";
}