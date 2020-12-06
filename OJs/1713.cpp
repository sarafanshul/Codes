
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int unsigned long long

using namespace std;

const unsigned MOD = 1e9+7;
const unsigned MAXN = 1000007;
const unsigned MAXM = 1e6+7;

inline void fasterLLDivMod(unsigned long long x, unsigned y, unsigned &out_d, unsigned &out_m) {
    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
    #ifdef __GNUC__
    asm(
        "divl %4 \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (y)
    );
    #else
    __asm {
        mov edx, dword ptr[xh];
        mov eax, dword ptr[xl];
        div dword ptr[y];
        mov dword ptr[d], eax;
        mov dword ptr[m], edx;
    };
    #endif
    out_d = d; out_m = m;
}
inline unsigned mod(unsigned long long x, unsigned y = MOD) {
    unsigned dummy, r;
    fasterLLDivMod(x, y, dummy, r);
    return r;
}
inline unsigned mod1(unsigned long long x, unsigned y = MOD-1) {
    unsigned dummy, r;
    fasterLLDivMod(x, y, dummy, r);
    return r;
}

int power(int x ,int y) {  
    if(x == 0 && y == 0 )return 1;
    int res = 1;
    x = mod(x);
    if (x == 0) return 0;
    while (y > 0) {  
        if (y & 1) res = mod(res*x);  
        y = y>>1;
        x = mod(x*x);  
    }
    return mod(res);  
}  

int power1(int x ,int y) {  
    if(x == 0 && y == 0 )return 1;
    int res = 1;
    x = mod1(x);
    if (x == 0) return 0;
    while (y > 0) {  
        if (y & 1) res = mod1(res*x);  
        y = y>>1;
        x = mod1(x*x);  
    }
    return mod1(res);  
}


int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> d(MAXN + 1);
    for (int i = 1; i <= MAXN; i++)
        for (int j = i; j <= MAXN; j += i)
            d[j]++;
    int n, x;
    cin >> n;
    while(n--)
        cin >> x, cout << d[x] << "\n";
    return 0;
}