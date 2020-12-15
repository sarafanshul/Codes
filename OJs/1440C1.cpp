 #ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 1e2 +7;

int grid[MAXN][MAXN] , new_grid[MAXN][MAXN];

vector<pair<int ,int>> operations;

void flip(int row, int col) {
	grid[row][col] = !grid[row][col];
	operations.emplace_back(row, col);
}
 
void ensure() {
	assert((int) operations.size() % 3 == 0);
}

void check(){
	operations.clear();
	int h, w;
	scanf("%d%d", &h, &w);
	for(int row = 0; row < h; ++row) {
		static char s[MAXN];
		scanf("%s", s);
		for(int col = 0; col < w; ++col) {
			grid[row][col] = (s[col] == '1');
		}
	}
	bool flag = false;
	if(h < w) {
		for(int row = 0; row < h; ++row) {
			for(int col = 0; col < w; ++col) {
				new_grid[col][row] = grid[row][col];
			}
		}
		swap(h, w);
		flag = true;
		for(int row = 0; row < h; ++row) {
			for(int col = 0; col < w; ++col) {
				grid[row][col] = new_grid[row][col];
			}
		}
	}
	for(int row = 0; row <= h - 2; ++row) {
		for(int col = 0; col <= w - 2; ++col) {
			if(grid[row][col] || grid[row][col+1]) {
				if(!(grid[row][col] && grid[row][col+1])) {
					flip(row + 1, col);
					flip(row + 1, col + 1);
				}
				else {
					if(grid[row+1][col]) flip(row + 1, col);
					else flip(row + 1, col + 1);
				}
				if(grid[row][col]) flip(row, col);
				if(grid[row][col+1]) flip(row, col + 1);
				ensure();
			}
		}
	}
	for(int row = 0; row < h - 1; ++row) {
		for(int col = 0; col < w; ++col) {
			assert(!grid[row][col]);
		}
	}
	for(int col = 0; col <= w - 2; ++col) {
		if(col == w - 2 && grid[h-1][col] && grid[h-1][col+1]) {
			flip(h-2,w-2);
			flip(h-2,w-1);
			flip(h-1,w-1);
			ensure();
			flip(h-2,w-2);
			flip(h-2,w-1);
			flip(h-1,w-2);
			ensure();
			assert(!grid[h-1][w-1] && !grid[h-1][w-2]);
		}
		if(col == w - 2 && grid[h-1][col] && !grid[h-1][col+1]) {
			flip(h-2,w-2);
			flip(h-2,w-1);
			flip(h-1,w-2);
			ensure();
			flip(h-2,w-2);
			flip(h-1,w-2);
			flip(h-1,w-1);
			ensure();
			flip(h-1,w-2);
			flip(h-1,w-1);
			flip(h-2,w-1);
			ensure();
		}
		if(grid[h-1][col]) {
			flip(h-2, col);
			flip(h-2, col+1);
			flip(h-1, col);
			ensure();
			flip(h-2, col);
			flip(h-2, col+1);
			flip(h-1, col + 1);
			ensure();
		}
	}
	if(grid[h-1][w-1]) {
		flip(h-2,w-2);
		flip(h-2,w-1);
		flip(h-1,w-1);
		ensure();
		flip(h-2,w-2);
		flip(h-1,w-1);
		flip(h-1,w-2);
		ensure();
		flip(h-1,w-1);
		flip(h-1,w-2);
		flip(h-2,w-1);
		ensure();
	}

	assert((int) operations.size() <= 3 * h * w);
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w; ++col) {
			assert(!grid[row][col]);
		}
	}
	printf("%d\n", (int) operations.size() / 3);
	for(int i = 0; i < (int) operations.size(); ) {
		for(int j = 0; j < 3; ++j) {
			// if(j) assert(operations[i] != operations[i-1]);
			if(flag) {
				swap(operations[i].first, operations[i].second);
			}
			printf("%d %d ", operations[i].first + 1, operations[i].second + 1);
			i++;
		}
		puts("");
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	// ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
