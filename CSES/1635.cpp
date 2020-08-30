#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long

using namespace std;

const uint32_t MOD = 1e9+7;
const uint32_t MAXN = 101;
const uint32_t MAXM = 1e6+7;
int n ,m;

int dp[MAXM];
int c[MAXN];

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

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> c[i];
	dp[0] = 1;
	for(int x = 1; x <= m ;x++){
		for(int _c = 0; _c < n;_c++){if(x-c[_c] >= 0) {dp[x] = (dp[x]+dp[x-c[_c]] >= MOD)?(dp[x]+dp[x-c[_c]]-MOD):(dp[x]+dp[x-c[_c]]); }}
	}
	cout << dp[m];
	return 0;
}