#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> ans,adj[200007];
bool vis[200007];
int inputorder[200007],relorder[200007];	
bool cmp(int a,int b){
	return relorder[a]<relorder[b];
}

int main() {	
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,x,a,b,i,j;
	cin>>n;
	for(i=0;i<n-1;i++){	
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(i=0;i<n;i++){
		cin>>inputorder[i];
		relorder[inputorder[i]]=i;
	}	
	for(i=1;i<=n;i++)
		sort(all(adj[i]),cmp);
	queue<int> q;		
	q.push(1);	
	memset(vis,false,sizeof(vis));
	while(!(q.empty())){
		queue<int> temp;
		while(!(q.empty())){
			int x= q.front();
			q.pop();
			ans.push_back(x);
			vis[x]=true;
			for(j=0;j<adj[x].size();j++)
				if(vis[adj[x][j]]==false)
					temp.push(adj[x][j]);
			}
		q=temp;			
	}
	for(i=0;i<n;i++)
		if(inputorder[i]!=ans[i]){
			cout<<"No"; 
			return 0;
		}
	cout<<"Yes";
    return 0;
}
