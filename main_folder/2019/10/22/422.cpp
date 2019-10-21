#include <iostream>
#include <string>
using namespace std;

int l;
int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

inline bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < l && y < l;
}

int main()
{
    cin >> l;
    string A[100], w;
    for (int i = 0; i < l; ++i)
        cin >> A[i];
    
    while (cin >> w, w != "0")
    {
        if (!w.size())
            cout << "Not found\n";

        bool flag = true;
        for (int i = 0; i < l && flag; ++i)
            for (int j = 0; j < l && flag; ++j)
                if (A[i][j] == w[0])
                    for (int k = 0; k < 8 && flag; ++k)
                    {
                        int d1 = i, d2 = j, num = 0;
                        
                        while (valid(d1, d2) && A[d1][d2] == w[num])
                        {
                            if (++num == w.size())
                                flag = false, cout << i + 1 << ',' << j + 1 << ' ' << d1 + 1 << ',' << d2 + 1 << '\n';
                            d1 += dx[k]; d2 += dy[k];
                        }
                    }
        if (flag)
            cout << "Not found\n";
    }
}
