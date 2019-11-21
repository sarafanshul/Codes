#include <algorithm> 
#include <iostream>
#include <map>
#include <string>
#include <tuple>
using namespace std;
typedef pair<string, int> si;

int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        map<string, int> M;
        for (int i = 0; i <= s.size() - n; ++i)
            M[s.substr(i, n)]++;

        cout << max_element(M.begin(), M.end(), [](si i, si j){return i.second < j.second;})->first << '\n';
    }
}
