// heirholzera impl for 508D -1
 
// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
// header(s)
#include <bits/stdc++.h>
 
#define gc getchar_unlocked
#define pc putchar_unlocked
#define PI (3.14159265)
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define INF (100000005)
#define SIZE (2)
#define TREESIZE (302144)
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n+1)
#define epsilon 1e-8 //add to double before casting to integer
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
 
 
int value(char ch){
	if(ch>='a' && ch<='z')	return ch-'a';
	if(ch>='A' && ch<='Z')	return ch-'A'+26;
	return ch-'0'+52;
}
 
int n, indeg[3900], outdeg[3900];
vector<int> undirected[3900], adj[3900];
bool vis[3900];
 
 
void dfs1(int pos){
	for (int i = 0; i < undirected[pos].size(); ++i){
		if(!vis[undirected[pos][i]]){
			vis[undirected[pos][i]] = true;
			dfs1(undirected[pos][i]);
		}
	}
}
 
bool is_connected(){
	for (int i = 0; i < 3900; ++i){
		if(!undirected[i].empty()){
			vis[i]=true;
			dfs1(i);
			for (int j = 0; j < 3900; ++j){
				if(!undirected[j].empty() && !vis[j])
					return false;
			}
			return true;
		}
	}
}
 
 
int temp_path[400002], final_path[400005], tsz, fsz;
 
void euler_dfs(int v){
	temp_path[tsz++] = v;
	while(!adj[v].empty()){
		int vv = adj[v].back();
		adj[v].pop_back();
		euler_dfs(vv);
	}
	final_path[fsz++] = temp_path[--tsz];
}
 
char schar(int val){
	int t = val % 62;
	if(t < 26)	return t+'a';
	t -= 26;
	if(t < 26)	return t+'A';
	t -= 26;
	return t+'0';
}
 
char fchar(int val){
	return schar(val/62);
}
 
int main(){
 
    //Hierholzer algorithm to find eulerian path
    scanf("%d", &n);
    char str[5];
    int src = -1;
    while(n--){
    	scanf("%s", str);
    	int a = value(str[0])*62+value(str[1]);
    	int b = value(str[1])*62+value(str[2]);
    	undirected[a].pb(b);
    	undirected[b].pb(a);
    	outdeg[a]++;indeg[b]++;
    	adj[a].pb(b);
    	src = a;
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i=0;i<62*62;i++){
    	if(indeg[i] == 0 && outdeg[i] == 0)	continue;
    	if(indeg[i] > outdeg[i]+1 || outdeg[i] > indeg[i]+1){
    		printf("NO");
    		return 0;
    	}
    	if(indeg[i] > outdeg[i])cnt1++;
    	if(indeg[i] < outdeg[i]){
    		cnt2++;
    		src = i;
    	}
    }
 
    if((cnt1==cnt2 && cnt1==0) || (cnt1==cnt2 && cnt1==1)){
    	if(!is_connected()){
    		printf("NO");
    		return 0;
    	}
    	printf("YES\n");
    	euler_dfs(src);
    	reverse(final_path, final_path+fsz);
    	printf("%c", fchar(final_path[0]));
    	for(int i=0;i<fsz;i++) printf("%c", schar(final_path[i]));
    	return 0;
    }
 
    printf("NO");
    return 0;
}
