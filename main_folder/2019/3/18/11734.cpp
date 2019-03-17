#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int c = 1; c <= n; c++)
    {
        string team, judge, team_trim, s;
        getline(cin, team);
        istringstream iss(team);
        while (iss >> s)
            team_trim += s;
        
        getline(cin, judge);
        
        cout << "Case " << c << ": ";
        if (team == judge)
            cout << "Yes\n";
        else if (team_trim == judge)
            cout << "Output Format Error\n";
        else
            cout << "Wrong Answer\n";
    }
}
