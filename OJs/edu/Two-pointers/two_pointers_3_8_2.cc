#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int

void solve(int a[], int b[], int n, int m, int s, int A, int B) {
    sort(a, a + n, greater<int>());
    sort(b, b + m, greater<int>());
    
    vector<ll> prefixSumB(m + 1, 0);
    for (int i = 0; i < m; i++) prefixSumB[i + 1] = prefixSumB[i] + b[i];
    
    ll currentWeightA = 0, currentCostA = 0, ans = 0;
    int j = 0;
    for (int i = 0; i < n + 1; i++) {
        ll remaining = s - currentWeightA;
        int index = min((ll)m, remaining / B);
        ans = max(ans, currentCostA + prefixSumB[index]);
        
        if (i == n) break;
        
        currentWeightA += A;
        currentCostA += a[i];
        if (currentWeightA > s) break;
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    // cin >> t;
    while (t--) {
        int n, m, s, A, B;
        cin >> n >> m >> s >> A >> B;
        
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int b[m];
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        solve(a, b, n, m, s, A, B);
    }
}



