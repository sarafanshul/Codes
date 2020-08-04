#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

typedef vector<string> vs;

long cnt(vs t)
{    
    if (t.empty())
        return 1;

    int it = 1, IF = 1, ELSE = 0;
    while (IF != ELSE)
    {
        IF += t[it] == "IF";
        ELSE += t[it] == "ELSE";
        ++it;
    }
    int mid = it - 1;
    
    IF = 1; ELSE = 0;
    while (IF != ELSE)
    {
        IF += t[it] == "IF";
        ELSE += t[it] == "END_IF";
        ++it;
    }

    long t1, t2, t3 = 1;
    
    t1 = cnt(vs(t.begin() + 1, t.begin() + mid));
    t2 = cnt(vs(t.begin() + mid + 1, t.begin() + it - 1));
    if (distance(t.begin() + it, t.end()) > 0)
         t3 = cnt(vs(t.begin() + it, t.end()));

    return (t1 + t2) * t3;
}

int main()
{
    int n;
    cin >> n;
    string s;
    vs t;
    while (cin >> s)
    {   
        if (s == "ENDPROGRAM")
        {
            cout << cnt(t) << '\n';
            t.clear();
            continue;
        }
        
        if (s != "S")
            t.push_back(s);
    }    
}
