#include<bits/stdc++.h>

using namespace std;

int x[108],y[108],z[108];
int n,ans=0;

void dfs(int i){
    z[i]=1;
    for(int j=0;j<n;++j){
        if(z[j]!=1&&(x[i]==x[j]||y[i]==y[j]))
            dfs(j);
    }
}
int main(){
	ios::sync_with_stdio(false);
	
	cin>>n;
    for(int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    
    for(int i=0;i<n;++i){
        if(z[i]!=1){
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1;
	
}
