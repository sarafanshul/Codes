#include <cmath>
#include <numeric>
#include <algorithm> 
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector> 
using namespace std;
typedef vector<int> vi;

float euclid(int x1, int y1, int x2, int y2)
{
    int d1 = x2 - x1, d2 = y2 - y1;
    return sqrt(d1 * d1 + d2 * d2);
}

int main()
{
    cout << fixed << setprecision(2);
    int n, X[10], Y[10], cnt = 1;
    float dist[10][10];
    while (cin >> n, n)
    {
        cout << "**********************************************************\nNetwork #" << cnt++ << '\n';
        
        for (int i = 0; i < n; ++i)
            cin >> X[i] >> Y[i];

        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                dist[i][j] = dist[j][i] = euclid(X[i], Y[i], X[j], Y[j]);

        vi A(n), B;
        iota(A.begin(), A.end(), 0);
        float best = 1e9;
        do
        {
            float cost = 0;
            for (int i = 0; i < A.size() - 1; ++i)
                cost += dist[A[i]][A[i + 1]];
            if (cost < best)
                best = cost, B = A;
        } while (next_permutation(A.begin(), A.end()));

        float sum = 0;
        
        for (int i = 0; i < B.size() - 1; ++i)
        {
            cout << "Cable requirement to connect (" << X[B[i]] << "," << Y[B[i]] << ") to ("
                 << X[B[i + 1]] << "," << Y[B[i + 1]] << ") is " << dist[B[i]][B[i + 1]] + 16 << " feet.\n";
            sum += dist[B[i]][B[i + 1]];
        }
        cout << "Number of feet of cable required is " << sum + (n - 1) * 16 << ".\n";
    }
}
