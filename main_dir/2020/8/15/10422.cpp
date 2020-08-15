#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
typedef vector<string> vs;

int dx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1,  1,  2};
vs target({"11111", "01111", "00 11", "00001", "00000"});

int h(vs& p)
{
    int s = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (p[i][j] != target[i][j])
                ++s;

    return max(0, s - 1);
}

bool check(vs& p)
{
    bool res = true;
    for (int i = 0; i < 5; ++i)
        res &= p[i] == target[i];
        
    return res;
}

bool f(queue<std::pair<vs, int> >& Q, vs& p, int d)
{
    if (check(p))
        return true;    
    
    if (d + h(p) > 10)
        return false;
    
    int ex, ey;
    for (int i = 0; i < 5; ++i)
    {
        int j = p[i].find(" ");
        if (j != string::npos)
            ex = i, ey = j;
    }
    
    for (int i = 0; i < 8; ++i)
    {
        vs pos(p);
        if (ex + dx[i] >= 0 && ex + dx[i] < 5 && ey + dy[i] >= 0 && ey + dy[i] < 5)
        {
            pos[ex][ey] = pos[ex + dx[i]][ey + dy[i]];
            pos[ex + dx[i]][ey + dy[i]] = ' ';
            Q.emplace(pos, d + 1);
        }
    }
    
    
    return false;
    
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    while (N--)
    {
        vs start(5);
        set<vs> S;
        for (int i = 0; i < 5; ++i)
            getline(cin, start[i]), start[i].resize(5);
        
        queue<std::pair<vs, int> > Q;
        Q.emplace(start, 0);
        int res = -1;
        while (!Q.empty())
        {
            vs p; int d;
            tie(p, d) = Q.front(); Q.pop();
            auto it = S.find(p);
            
            if(it == S.end() && f(Q, p, d))
                res = d;

            S.insert(p);
        }
        
        if (res != -1)
            cout << "Solvable in " << res << " move(s).\n";
        else
            cout << "Unsolvable in less than 11 move(s).\n";
            
    }
}
