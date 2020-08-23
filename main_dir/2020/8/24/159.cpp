#include <iostream>
#include <string>
#include <tuple>
#include <iomanip> 
using namespace std;

typedef pair<int, int> ii;

ii match(string& a, string& b)
{
    for (int f, i = 0; i < a.size(); ++i)
        if (f = b.find(a[i]), f != string::npos)
            return make_pair(i, f);

    return make_pair(-1, -1);
}

int main()
{
    string a, b, c, d;
    int flag = 0;
    while (cin >> a >> b >> c >> d, a != "#")
    {
        if (flag++)
            cout << '\n';
        
        int h1, h2, v1, v2;
        tie(h1, v1) = match(a, b);
        tie(h2, v2) = match(c, d);

        if (h1 < 0 || h2 < 0)
        {
            cout << "Unable to make two crosses\n";
            continue;
        }

        for (int i = max(v1, v2); i > 0; --i)
        {
            cout << setw(h1 + 1) << (v1 >= i ? b[v1 - i] : ' ');
            if (v2 >= i)
                cout << setw(a.size() - h1 + 3 + h2) << d[v2 - i];
            cout << '\n';
        }

        cout << a << "   " << c << '\n';

        int v1_tail = b.size() - v1 - 1, v2_tail = d.size() - v2 - 1;
        for (int i = 1; i <= max(v1_tail, v2_tail); ++i)
        {
            cout << setw(h1 + 1) << (v1_tail >= i ? b[v1 + i] : ' ');
            if (v2_tail >= i)
                cout << setw(a.size() - h1 + 3 + h2) << d[v2 + i];
            cout << '\n';
        }
    }
}
