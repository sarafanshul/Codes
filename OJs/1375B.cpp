
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;

int gr[301][301];

void check(){
	int n ,m ,e ,in;
	bool f = true;
	cin >> n >> m;
	for(int i = 0; i <n; i++){
		for (int j = 0 ; j < m ;j++){
			e = 4;
			if (i == 0 || i == n-1) e--;
			if (j == 0 || j == m-1) e--;
			cin >> in;
			if (in > e){
				cout << "NO\n";
				return;
			}
			if (in > 0) gr[i][j] = e;
			else gr[i][j] = 0;
		}
	}
	cout << "YES\n";
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		check();
	}
}

