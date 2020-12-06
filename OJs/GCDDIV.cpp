#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    while (a != 0) {
        b %= a;
        int t = b;
        b = a;
        a = t;
    }
    return b;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    while (cases--) {
        int n, k;
        cin >> n >> k;
        int G = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            G = gcd(G, x);
        }
        string ans = "YES";
        for (int i = 2; i * i <= G; ++i) {
            if (G % i == 0) {
                if (i > k) {
                    ans = "NO";
                    break;
                }
                while (G % i == 0) {
                    G /= i;
                }
            }
        }
        if (G > k) {
            ans = "NO";
        }
        cout << ans << endl;
    }
    return 0;
}
