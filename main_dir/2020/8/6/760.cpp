#include <iostream>
#include <string>
#include <vector>
using namespace std;

string abc = "acgt";
vector<string> res;
int max_d;

struct node
{
    node() : c(), b() {}
    
    node* c[4];
    bool b;
};

void insert(node* n, string& s, int i)
{
    for (int j = i; j < s.size(); ++j)
    {
        int idx = abc.find(s[j]);
        if (!n->c[idx])
            n->c[idx] = new node;
        
        n = n->c[idx];
    }         
}

void update(node* n, string& t, int i)
{
    for (int j = i; j < t.size(); ++j)
    {
        int idx = abc.find(t[j]);
        if (!n->c[idx])
            return;

        n = n->c[idx];
        n->b = true;
    }
}

void dfs(node* r, int depth, string infix)
{
    if (depth == max_d)
        res.push_back(infix);
    else if (depth > max_d)
        res.assign(1, infix), max_d = depth;
    
    for (int i = 0; i < 4; ++i)
        if (r->c[i] && r->c[i]->b)
            dfs(r->c[i], depth + 1, infix + abc[i]);
}

int main()
{
    string s, t;
    int c = 0;
    while (cin >> s >> t)
    {
        if (c++)
            cout << '\n';
        
        node* r = new node;
        for (int i = 0; i < s.size(); ++i)
            insert(r, s, i);

        for (int i = 0; i < t.size(); ++i)
            update(r, t, i);

        res.clear(); max_d = 0;
        dfs(r, 0, "");

        if (res.front() == "")
            cout << "No common sequence.\n";
        else
            for (string& str : res)
                cout << str << '\n';
    }
}    
