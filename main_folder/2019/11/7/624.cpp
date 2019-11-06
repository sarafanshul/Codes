#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi tracks, res;
int best, N, T;

void f(int iter, int sum, vi picked)
{
    if (sum > N)
        return;

    if (sum > best)
    {
        best = sum;
        res = picked;
    }
    
    for (int i = iter; i < tracks.size(); ++i)
    {
        vi r(picked);
        r.push_back(i);
        f(i + 1, sum + tracks[i], r);
    }
}

int main()
{
    while (cin >> N >> T)
    {
        best = 0;
        tracks.resize(T);
        for (int i = 0; i < T; ++i)
            cin >> tracks[i];

        f(0, 0, vi());
        for (int r : res)
            cout << tracks[r] << " ";

        cout << "sum:" << best << "\n";
        
    }
}
