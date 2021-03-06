#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
 
using namespace std;
	
const int maxn=2e5+10;
vector<int> ve[maxn];
map<int,int> mp;
int n,m,l[maxn],r[maxn],cnt;

void dfs(int u){
	l[u] = cnt++;
	mp[cnt-1] = u;
	for( int v : ve[u]) 
		dfs(v);
	r[u]=cnt;
}

int main(){
	int i,j;
	cin >> n >> m;
	int u,v;
	for(i=2;i<=n;i++){
		cin >> u;
		ve[u].push_back(i);
	}
	cnt=1;
	dfs(1);
	while(m--){
		cin >> u >>v ;
		if(r[u]-l[u]<v){
			cout << "-1\n";
		}
		else{
			int t=l[u]+v-1;
			cout << mp[t];
		}
	}
	return 0;
}