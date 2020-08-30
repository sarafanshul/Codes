#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define MOD 10000007
using namespace std;

void primeFactors(int n ,int k) {  
    int count = 0;
    long eodcnt = 0; 
    while (n % 2 == 0)  {  
        count++;
        n = n/2;
        eodcnt++; }  
    bool flag;
    for (int i = 3; i <= sqrt(n); i = i + 2) {   
        flag = true;
        while (n % i == 0) {  
            if (flag) {
                flag = false;
                eodcnt--; }
            count++; 
            n = n/i; }  }  
    if (n > 2) count++;
    if (count < k) cout << 0 << "\n";
    else cout << 1 << "\n";
}

void solve(){
    int x, k;
    cin>>x>>k;
    if (k == 1 && x > 1) cout << 1 << "\n";
    else if(x<=k || k>=30 || (1<<k)>x) cout<<"0"<<"\n";
    else primeFactors(x ,k);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}