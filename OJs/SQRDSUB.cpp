#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #define MOD 10000007
using namespace std;

int a[100005];

long long find_seq_rng(int n){
    int prev = -1, prev_prev = -1;
    long long sum = 0ll ,tot = 0ll;
    int t_f = 0 ,t_t = 0 ,m_t;

    for (int j = 0; j < n; j++) {
        if (a[j] % 4 == 0){
            sum += j + 1;
            prev_prev = prev;
            prev = j; 
            t_f++;}

        else if (a[j] % 2 == 0){
            if (prev != -1) sum += j - (j - prev - 1); 
            prev_prev = prev;
            prev = j; 
            t_t++;}

        else {
            if (prev != -1 && prev_prev != -1) {
                if (a[prev] % 4 == 0) sum += (j + 1);
                else sum += (j + 1) - (prev - prev_prev); 
                m_t = min(t_t ,t_f); }
            else if (prev != -1 && prev_prev == -1) {
                if (a[prev] % 4 == 0) sum += j + 1;
                else sum += (j - prev);
                m_t = max(t_t+t_f ,sum); }
            else sum += j + 1;
        }
    }
    tot = max(m_t ,sum);
    return sum;
}

void solve(){
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) cin >> a[j];
    cout << find_seq_rng(n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}