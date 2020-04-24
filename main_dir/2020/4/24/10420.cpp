#include <iostream>
#include <map>
#include <string> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    map<string, int> M;
    while (n--)
    {
        cin >> s;
        M[s] += 1;
        getline(cin, s);
    }

    for (auto& el : M)
        cout << el.first << ' ' << el.second << '\n';
}
