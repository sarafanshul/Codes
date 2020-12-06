// #include <iostream>
// #include <vector>
// #include <math.h>
// #include <string.h>
// #include <algorithm>
// #include <unordered_map>
#include<bits/stdc++.h>

using namespace std;

long MOD = 998244353;
const long MAX = 100001;
const long MAXQ = 10001;
long facts[MAX] ,times[MAX], num[MAX], cnt[MAX], all ,belong[MAX] ,nums[MAX], comb[MAXQ][MAXQ];
bool vis[MAX];

struct Instruct {
    long l, r; 
    long id;
    friend bool operator < (const Instruct& a, const Instruct& b) {
        if(belong[a.l]==belong[b.l]) return a.r < b.r;
        return belong[a.l] < belong[b.l];
    }
} instruct[MAX];

void fact_init() {
    facts[0] = 1;
    for(int i=1;i<MAX;i++) facts[i] = (facts[i-1]*i)%MOD;
}

void combinations(long _size){
    for(int i=0;i<_size;i++) {
        comb[0][i] = 0; comb[i][0] = 1;
    }
    for(int i=1;i<_size;i++) for(int j=1;j<=i;j++) {
        comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%MOD;
    }
}

long gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
 }

void eucl_gcd(long a,long b,long &x,long &y) {
    if(!b) {
        x = 1, y=0;
        return;
    }
    eucl_gcd(b,a%b,x,y);
    long l=x;
    x=y;
    y=l-a/b*y;
}

void _add(long x) {
    ++num[++cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]-1];
}

void _del(long x) {
    ++num[--cnt[x]];
    times[++all]=cnt[x];
    --num[cnt[x]+1];
}

long select_ish(long MOD, long n,long m) {
    if(n<MAXQ) return comb[n][m];
    if(m==1 || m==n-1) return n;
    if(m>n) return 0;
    if(n==m) return 1;
    long nn=facts[n], mm=(facts[m]*facts[n-m])%MOD;
    long d=gcd(nn,mm);
    nn/=d, mm/=d;
    long x,y;
    eucl_gcd(mm,MOD,x,y);
    x=(x+MOD)%MOD;
    return (x*nn)%MOD;
}

long get_valof() {
	int _ret;
    long k = 0;
    long sum = 0;
    long out = 0; 
    long ans, _tmp;
    vector<long> vec;
    for(long j=1;j <= all;j++) if(!vis[times[j]]&&num[times[j]]>0) {
        vec.push_back(times[j]);
        times[++k]=times[j];
        vis[times[j]]=true;
    }
    all=k;
    for(int j=1;j<=k;j++) vis[times[j]] = false;
    for(long i: vec) if(num[i]%2) sum ^= i;
    if(sum==0) return 0;
    for(long i: vec) if(num[i]>0) {
        ans = sum^i;
        if(ans > i) continue;
        _tmp = select_ish(MOD, i, i-ans);
        _tmp = (_tmp*num[i])%MOD;
        out = (out+_tmp)%MOD;
    }
    _ret = out - sum;
    return out;
}

void rescro(long m) {
    long L = 1, R = 0 ,M;
    vector<long> _val(m+1);
    vector<bool> size_of(m/2);
    for(int i=1;i<=m;i++) {
        for(;R<instruct[i].r;R++) _add(nums[R+1]);
        for(;L>instruct[i].l;L--) _add(nums[L-1]);
        for(;R>instruct[i].r;R--) _del(nums[R]);
        for(;L<instruct[i].l;L++) _del(nums[L]);
        _val[instruct[i].id] = get_valof();
    }
    for(int i=1;i<=m;i++) printf("%ld\n", _val[i]);
}

void solve(){
    long  n, q, l, r;
    long ret = -1;
    unordered_map<long, long> dict_ll;
    scanf("%ld", &n);
    long sq = sqrt(n);
    for(int i=1;i<=n;i++) {
        scanf("%ld", &nums[i]); 
        belong[i] = (i-1)/sq+1;
    }
    for(int i=1;i<=n;i++) {
        if(dict_ll.find(nums[i])==dict_ll.end()) dict_ll[nums[i]] = dict_ll.size();
        nums[i] = dict_ll[nums[i]];
    }
    scanf("%ld", &q);
    for(int i=1;i<=q;i++) {
        scanf("%ld%ld", &instruct[i].l, &instruct[i].r);
        instruct[i].id = i;
    }
    sort(instruct+1, instruct+q+1);
    rescro(q);
}

void _clear(int _a){
	memset(times, _a, sizeof(times));
    memset(num, _a, sizeof(num));
    memset(cnt, _a, sizeof(cnt));
    memset(vis, _a, sizeof(vis));
    all = _a;
}

void cases(){
	_clear(0);
    solve();
}

int main(){
    fact_init();
    combinations(MAXQ); // here
    int t; cin>>t;
    while(t--) cases();
    
}