#include <iostream>
using namespace std;

int main()
{
    int r, n, c = 1;
    while (cin >> r >> n, r || n)
    {
        int cnt = -1;
        while (r > 0)
            r -= n, ++cnt;

        cout << "Case " << c++ << ": " << (cnt < 27 ? to_string(cnt) : "impossible") << '\n';
    }
}
