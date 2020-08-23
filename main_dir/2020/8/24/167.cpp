#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
vvi G(8, vi(8));
int best;

bool legal(int a)
{
    return a >= 0 && a < 8;
}

int f(int iter, int sum, vi Q)
{
    if (iter == 8)
        return sum;

    vi possible(8, 1);
    for (int t = 0; t < Q.size(); ++t)
    {
        possible[Q[t]] = 0;
        if (legal(Q[t] + iter - t))
            possible[Q[t] + iter - t] = 0;
        if (legal(Q[t] - iter + t))
            possible[Q[t] - iter + t] = 0;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (possible[i])
        {
            vi R(Q);
            R.push_back(i);
            int tmp = f(iter + 1, sum + G[i][iter], R);
            if (tmp > best)
                best = tmp;
        }
    }

    return 0;
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> G[i][j];
        
        best = 0;
        f(0, 0, vi());
        cout << setw(5) << best << endl;
    }
}
