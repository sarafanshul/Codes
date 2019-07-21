#include <iostream>
using namespace std;

int main()
{
    int n, A[1000];
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        bool flag = false;
        for (int i = 0; i < n; ++i)
            if (A[i])
                cout << (flag ? " " : "") << A[i], flag = true;
        if (!flag)
            cout << "0";
            
        cout << "\n";
    }
}
