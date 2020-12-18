#include <bits/stdc++.h>
using namespace std;

// Type aliases

using ll = long long;
using str = string; 
using vi = vector<int>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using si = set<int>;

// Vector Operations

#define sz (int)(x).size()
#define pb push_back
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define del(x, i) erase(begin(x)+i)
#define rem(x,i) erase(begin(x), begin(x)+i)

// Pairs

#define mp make_pair
#define sec second
#define fir first

// Sets and Maps

#define ins insert
#define ez erase
#define cnt count

// Math

#define MOD 1e9+7
#define MAX_INT 1e18*9

// Permutation

#define possibilities(x) while(next_permutation(all(x))

// Loops

#define Trav(a,x) for (auto& a: x)
#define For(i,a,b) for (int i = (a); i < (b); ++i)

// Input/Output - s is basically the file name without the ".in" and ".out"

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int main(){
    setIO("speeding"); 
    int N, M; cin >> N >> M;

    int start = 0;
    vi limit(100);
    For(i, 0, N){
        int length, speed; cin >> length >> speed;
        For(j, start, start+length){
            limit[j] = speed;
        }
        start += length;
    }

    start = 0;
    vi bessie(100);
    For(i, 0, M){
        int length, speed; cin >> length >> speed;
        For(j, start, start+length){
            bessie[j] = speed;
        }
        start += length;
    }

    int ans = 0;
    For(i, 0, 100){
        ans = max(ans, bessie[i]-limit[i]);
    }
    cout << ans << endl;
}