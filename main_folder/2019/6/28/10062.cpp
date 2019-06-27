#include <algorithm> 
#include <iostream>
#include <string>
#include <tuple>
#include <vector> 
using namespace std;
typedef pair<int, char> ic;

int main()
{
    string s;
    int cnt = 0;
    while (getline(cin, s))
    {
        if (cnt++)
            cout << '\n';
        vector<ic> A(128);
        for (int i = 0; i < 128; ++i)
            A[i].second = char(i);
        
        for (char c : s)
            A[c].first++;

        sort(A.begin(), A.end(), [](ic i, ic j){return i.first < j.first || (i.first == j.first && i.second > j.second);});
        for (ic a : A)
            if (a.first)
                cout << int(a.second) << ' ' << a.first << '\n';
    }
}
