#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > one;

int main()  {

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<long long, long long> > flowers;
        vector<long long> a;
        
        for (int i = 0; i < m; i++){
            long long x, y;
            cin >> x >> y;
            flowers.push_back({x, y});
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        
        long long pre[m + 1];
        
        for (int i = m - 1; i >= 0; i--){
            if (i == m - 1) pre[i] = a[i];
            else pre[i] = pre[i + 1] + a[i];
        }

        long long sum = 0 ,ans = 0 ,count = 0;
        
        for (long long i = 0; i < m; i++) {
            sum = 0;
            long long pos = upper_bound(a.begin(), a.end(), flowers[i].second) - a.begin();
            count = m - pos;
            if (pos != m)
                sum = pre[pos];

            if (flowers[i].first <= flowers[i].second)	{
                sum += flowers[i].first;
                count++;
            }
            if(count >= n) ans = max(ans , pre[m - n]);
            else ans = max(ans, sum + (n - count) * flowers[i].second);
        }
        cout << ans << "\n";
	}
    return 0;
}