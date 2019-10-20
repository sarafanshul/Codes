#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
int T[5] = {1, 5, 10, 25, 50};
ll memo[5][30001];

ll ways(int type, int val)
{
    if (val == 0)
        return 1;
    if (type == 5 || val < 0)
        return 0;
    if (memo[type][val] != -1)
        return memo[type][val];

    return memo[type][val] = ways(type, val - T[type]) + ways(type + 1, val);
}

int main()
{
    int n; ll tmp;
    memset(memo, -1, sizeof(memo));
    while (cin >> n)
    {
        if (tmp = ways(0, n), tmp > 1)
            cout << "There are " << tmp << " ways to produce " << n << " cents change.\n";
        else
            cout << "There is only 1 way to produce " << n << " cents change.\n";
    }
}
