#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;
 
const int N = 2e6+6;
const int T = 1e6+6;

ll arr[N];

void solve(){
    ll cntodd = 0;
    ll n ,k;
    cin >> n>>k;
    for(int i = 0; i<n; ++i){
        cin >> arr[i];
        cntodd += arr[i]%2;
    }
    if (cntodd < k || cntodd%2 != k%2){
        cout << "NO" << "\n";
        return;
    }
    cout << "YES" << "\n";
    // when you find one odd element, you end one segment
    for (int i = 0; i<n; ++i){
        if (k == 1) {
            cout << n << " ";
            break;
        }
        if (arr[i]%2){
            cout << i+1 << " ";
            --k;
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i <n; ++i){
        solve();
    }
    return 0;
}