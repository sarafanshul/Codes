#include<bits/stdc++.h>
 
using namespace std;
 
bool visited[2001] = {false};
vector<int>v[2001];
int c=1;
 
void dfs(int x ,int d){
    c = max(c,d);
    for(int i = 0; i < v[x].size(); i++){
            dfs( v[x][i] ,d+1);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    int n ,x;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        if(x==-1)continue;
        v[x].push_back(i);
    }
 
    for(int i=1;i<=n;i++) {
        dfs(i,1);
    }
 
    cout<< c <<"\n";
    
}