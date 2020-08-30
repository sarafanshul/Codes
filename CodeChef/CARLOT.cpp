#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

ll DP[300][300];
int cost[300][300];

int min(int x, int y, int z) { 
   if (x < y) 
      return (x < z)? x : z; 
   else
      return (y < z)? y : z; 
}

int minCost( int m, int n) { 
    int i, j; 

     // Instead of following line, we can use int tc[m+1][n+1] or  
     // dynamically allocate memory to save space. The following line is 
     // used to keep the program simple and make it working on all compilers. 
    int tc[300][300];
  
    tc[0][0] = cost[0][0]; 
  
     /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++) 
        tc[i][0] = tc[i-1][0] + cost[i][0]+1; 
  
     /* Initialize first row of tc array */
    for (j = 1; j <= n; j++) 
        tc[0][j] = tc[0][j-1] + cost[0][j]+1; 
  
     /* Construct rest of the tc array */
    for (i = 1; i <= m; i++){
        if ((i+1)%2){
            for (j = 1; j <= n; j++) 
                tc[i][j] = min(tc[i-1][j],tc[i][j-1]) + cost[i][j]+1;}
        else{
            tc[i][n] = tc[i-1][n]+cost[i][n]+1;
            for (j = n-1; j >= 1; j--) 
                tc[i][j] = min(tc[i-1][j],tc[i][j+1]) + cost[i][j]+1;}
        }
    for (int i = 0; i <=m ;++i){
        for (int j = 0; j <= n ;++j) cout << tc[i][j] << " ";
    cout << "\n";}
    return tc[m][n]; 
}

void solve(){
    ll N ,M;
    cin >> N >> M;
    string tp;
    int st[2] ,ed[2];
    bool flag = true;
    int cnt = 0;
    for(int i= 0; i<N ; ++i){
        for(int j = 0 ; j < M; ++j){
            cin >> tp;
            if (tp == "P"){
                cost[i][j] = 0;
                ed[0] = i;
                ed[1] = j;
                ++cnt;
                if (flag){
                    st[0] = i;
                    st[1] = j;
                    flag = false;}
            }
            else cost[i][j] = 1;
        } }

    // ll ans =minCost(ed[0] ,ed[1]) - minCost(st[0] ,st[1]);
    cout << minCost(N-1 ,M-1) << " \n ";// << minCost(st[0] ,st[1]);
    // cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}