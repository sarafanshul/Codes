
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
// #define int long long
using namespace std;

inline bool possible(int m, int s){return (s >= 0) && (s <= 9 * m);}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int m,s,i,j,n,k=0,sum;
    cin>>m>>s;
    sum = s;
    string _min(""), _max("");
    if((s <= 0 && m > 1) || (s > 9 * m)){cout << "-1 -1"; return 0;}

    for(int pos = 0; pos < m; pos++){
        for(int digit = 0; digit <= 9; digit++){
            if((pos > 0 || digit > 0 || (m == 1 && digit == 0)) && possible(m - pos - 1, sum - digit)){
                _min += ('0' + digit);
                sum -= digit;
                break;
            }
        }
    }

    sum = s;
    for(int pos = 0; pos < m; pos++){
        for(int digit = 9; digit >= 0; digit--){
            if(possible(m - pos - 1, sum - digit)){
                _max += ('0' + digit);
                sum -= digit;
                break;
            }
        }
    }

    cout << _min << " " << _max << endl;
	return 0;
}