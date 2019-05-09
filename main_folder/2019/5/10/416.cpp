#include <iostream>
#include <vector>
#include <string> 
using namespace std;

typedef vector<int> vi;
// Binary representation of 0..9 in int("abcdefg") form
int full[] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};

int to_num(string& s)
{
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[s.size() - i - 1] == 'Y')
            res |= 1 << i;

    return res;
}

int match(int a, int b)
{
    for (int i = 0; i < 7; ++i)
        if ((!((1 << i) & b)) && ((1 << i) & a))
            return -1;

    return a;
}

bool f(vi& A, int curr, int to_zero, int work)
{
    if (to_zero < 0)
        return true;
    
    int m = match(A[to_zero], full[curr]);
    if (m == -1)
        return false;

    // If LED should be working, is not working, but did work before
    for (int i = 0; i < 7; ++i)
        if (((1 << i) & full[curr]) &&
            (!((1 << i) & m)) &&
            ((1 << i) & work))
            return false;
    
    work |= m;
    return f(A, curr + 1, to_zero - 1, work);
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        vi A;
        string str;
        for (int i = 0; i < n; ++i)
        {
            cin >> str;
            A.push_back(to_num(str));
        }


        bool flag = false;
        for (int i = 0; i <= 10 - A.size(); ++i)
            if(f(A, i, A.size() - 1, 0))
            {
                flag = true;
                break;
            }

        cout << (flag ? "MATCH\n" : "MISMATCH\n");
    }
}
