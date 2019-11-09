#include <iostream>
using namespace std;

int main()
{
    int A[5], B[5];
    while (cin >> A[0])
    {
        for (int i = 1; i < 5; ++i)
            cin >> A[i];
        for (int i = 0; i < 5; ++i)
            cin >> B[i];
        
        bool r = true;
        for (int i = 0; i < 5; ++i)
            r = r && (A[i] != B[i]);

        cout << (r ? "Y\n" : "N\n");
    }
}
