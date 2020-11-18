/* For any given position i (1<=i<=n), 
    it is only affected by the most recent update r such that r >= i. 
    Firstly, the integers towards the end of the array 
    which are not affected by any updates stay as they are. 
    Store the elements at all positions affected atleast 
    once by some update
upd[i] stores the most recent update made such that the 'r' of the update is i. 
    So, for all j such that 1 <= j <= i, j has been affected by that update. 
    Alternatively you can say that the last update which affects a position i is the 
    most recent of the updates among positions j, i <= j <= n.
*/
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
 
ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
 
int n, max_affected, arr[200005], r[200005], t[200005], upd[200005];
 
 
int main() {
 
    int m;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        scanf("%d", &arr[i]);
 
    for(int i=1;i<=m;i++){
        scanf("%d%d", &t[i], &r[i]);
        upd[r[i]] = max(upd[r[i]], i);
        max_affected = max(max_affected, r[i]);
    }
    multiset<int> ele;
    for(int i=1;i<=max_affected;i++)
        ele.insert(arr[i]);
 
    int latest_update = 0;
    for(int i=n;i>=1;i--){
        latest_update = max(latest_update, upd[i]);
        if(latest_update == 0)  continue;
        if(t[latest_update] == 1){
            multiset<int>::iterator it = ele.end();
            it--;
            arr[i] = (*it);
            ele.erase(it);
        }
        else{
            arr[i] = (*ele.begin());
            ele.erase(ele.begin());
        }
    }
 
    for(int i=1;i<=n;i++)
        printf("%d ", arr[i]);
    return 0;
}
