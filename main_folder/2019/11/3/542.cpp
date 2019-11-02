#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

double A[16][16], R[16][4];

double sum(int curr, int a, int rd)
{
    int len = 2 * rd + (rd == 3 ? 2 : 0);
    double r = 0;
    for (int i = 0; i < len; ++i)
        r += R[a + i][rd - 1] * A[curr][a + i];

    return r;
}

int main()
{
    cout << fixed << setprecision(2);
    string C[16];
    for (int i = 0; i < 16; ++i)
        cin >> C[i];

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j)
            cin >> A[i][j], A[i][j] /= 100.0;

    for (int i = 0; i < 16; ++i)
        R[i][0] = A[i][i % 2 ? i - 1 : i + 1];
    
    for (int rd = 1; rd < 4; ++rd)
        for (int i = 0; i < 16; ++i)
        {
            int k = rd + (rd > 2 ? 1 : 0);
            R[i][rd] = R[i][rd - 1] * sum(i, 4 * k * (i / (4 * k)) + (i % (4 * k) < 2 * k ? 2 * k : 0), rd);
        }

    for (int i = 0; i < 16; ++i)
        cout << C[i] << string(10 - C[i].size(), ' ') << " p=" << R[i][3] * 100 << "%\n";
}
