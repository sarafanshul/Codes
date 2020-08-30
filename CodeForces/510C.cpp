// pragma
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// utils
#include <bits/stdc++.h>

// alias
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

// namespaces
using namespace std;

// globals
const int MAXN = 107;
int e[30][30];
string s[107];
bool visited[30] = {0};
int n;

inline int getID(char c){return (c == ' ')?0:(c-'a'+1);}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(e ,0 ,sizeof(e));
	for(int i = 1; i<= 26; i++) e[0][i] = true;

	cin >> n;
	for(int i = 1; i<= n ;i++){
		cin >> s[i]; s[i]+=" ";
	}

	int pos = 0;
	for(int i = 1; i < n ;i++){
		pos = 0;
		while(s[i][pos] == s[i+1][pos]) pos++;
		e[getID(s[i][pos])][getID(s[i+1][pos])] = 1;
	}
	for(int k = 0; k <= 26 ;k++){
		for(int i = 0; i<= 26 ;i++){
			for(int j = 0; j<= 26 ;j++) e[i][j] |= e[i][k] & e[k][j];
		}
	}
	bool haveCycle = 0;
	for(int i = 0; i<= 26 ;i++) haveCycle |= e[i][i];

	if(haveCycle){ cout << "Impossible";return 0;}
	
	for(int i = 0; i <= 26 ;i++){
		int now = 0;
		for(int j = 0; j <= 26 ;j++){
			bool valid = (!visited[j]);
			for(int k = 0 ;k<= 26 ;k++){
				if(!visited[k] && e[k][j]) valid = false;
			}
			if(valid){now = j;break;}
		}
		if (i > 0) cout << char('a'+now-1);
		visited[now] = 1;
	}

	return 0;
}