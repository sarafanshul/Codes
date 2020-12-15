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
 
const int N = 1e6+6;
const int T = 1e6+6;
 
int a[N];
int t[T], d;
 
 
int rmq(int i, int j){
    int r = i;
    for(i+=d,j+=d; i<=j; ++i>>=1,--j>>=1){
        if(i&1) r=a[r]>a[t[i]]?t[i]:r;
        if(~j&1) r=a[r]>a[t[j]]?t[j]:r;
    }
    return r;
}
 
int calc(int l, int r, int h){
    if(l>r) return 0;
    
    int m = rmq(l,r);
    int mn = a[m];
    
    int res = min(r-l+1, calc(l,m-1,mn)+calc(m+1,r,mn)+mn-h);
    
    return res;
}
 
int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    
    a[n] = 2e9;
    for(d=1;d<n;d<<=1);
    for(int i=0;i<n;++i) t[i+d]=i;
    for(int i=n+d;i<d+d;++i) t[i]=n;
    for(int i=d-1;i;--i) t[i]=a[t[i*2]]<a[t[i*2+1]]?t[i*2]:t[i*2+1];
    
    printf("%d\n",calc(0,n-1,0));
    
    return 0;
}