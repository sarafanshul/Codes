/*
If you look at the described process backwards, it resembles the Euclidean algorithm a lot. Indeed, if you rewinded a recording of Bajtek's actions, he always takes the larger out of two numbers (say

Unable to parse markup [type=CF_TEX]

) and replaces them by a - b, b. Since we know one of the final numbers ( r) we can simply check all numbers between 1 and r and run a faster version of Euclid's algorithm (one that replaces a, b by ) for all possibilities for a total runtime of . This was one of the expected solutions.
However, with some insight, it can be seen that this optimization is in fact not neccessary — we can simply simulate the reverse process as described (replacing a, b by a - b, b) for all candidates between 1 and r and the total runtime of our algorithm will remain . The proof of this fact is left to the reader.


N modify operations of a particular operation, and the smallest number of output modified sequence lexicographically most minimum.

If you can not reach r output IMPOSIBLE0

Ideas:

Two vertically disposed number t, b

Set the current sequence of operations performed is 'T', then t = t + b, t> b;

Operation sequence is currently executing 'B', then b = t + b, b> t

We use backstepping, if the current state is (t, b), t> b, illustrated as T come performed;

b> t, illustrated as B come performed;

That is the only state backstepping, the final-like body (1,1)

We know the last event types to 2 * r, (r, i), (i, r) 1 <= i <= r

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
int n ,m;
vector<int> adj[200001];
bool visited[200001];
int deg[200001];
vector<int> comp;

void dfs(int v){
	visited[v] = true;
	comp.PB(v);
	for (int u : adj[v]){
		if (!visited[u])
			dfs(u);
	}
}

int bfs(int x ,int y){
	queue<int> q ,p;
	q.push(x);
	visited[x] = 1;
	p.push(0);

	while(!q.empty()){
		int num = q.front();
		int ceng = p.front();
		q.pop();
		p.pop();
		if (num == y ) return ceng;
		if (num*2 <= 10000 && !visited[num*2]){
			q.push(num*2);
			visited[num*2] = 1;
			p.push(ceng+1);
		}
		if (num - 1 > 0 && !visited[num-1]){
			q.push(num-1);
			visited[num-1] = 1;
			p.push(ceng+1);
		}
	}
}

int r;
int res;
char str[1000005];
char s[1000005];
void check(int t,int b){
	int len=0;
	while(t!=b && t>=0 && b>=0){
		if(t>b){
			s[len++]='T';
			t-=b;
		}
		else{
			s[len++]='B';
			b-=t;
		}
	}
	if(len!=n-1 || t!=1) return ;
 
	s [len] = 'T'; // must be the beginning of the T
	int k=0;
	for(int i=0;i<len;++i)
		if(s[i]==s[i+1])
			k++;
	if(k<res){
		res=k;
		for(int i=0;i<=len;++i)
			str[i]=s[len-i];
		str[len+1]='\0';
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(visited ,0 ,sizeof(visited));
	cin>>n>>r;
    res=INT_MAX;
    for(int i=1;i<=r;++i) {
        check(i,r);
        check(r,i);
    }
    if(res==INT_MAX)
        cout<<"IMPOSSIBLE"<<"\n";
    else
        cout<<res<<"\n"<<str<<"\n";

	return 0;
}