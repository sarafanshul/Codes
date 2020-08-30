#include <iostream>
using namespace std;
  
long long n, q, t, a, b, u, bit[200005];
  
void update(int x, int d){
    while (x <= n){
        bit[x] += d;
        x += x & (-x);
    }
}
long long query(int x){
    long long ret = 0;
    while (x){
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}
  
int main() {
    cin >> n >> q;
    long long pre = 0;
    for (int i = 1; i <= n; i++){
        cin >> a;
        update(i, a-pre);
        pre = a;
    }
    for (int i = 0; i < q; i++){
        cin >> t;
        if (t == 1){
            cin >> a >> b >> u;
            update(a, u);
            update(b+1, -u);
        }
        else{
            cin >> a;
            cout << query(a) << "\n";
        }
    }
}
