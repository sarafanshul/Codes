#include <iostream>
#include <iomanip> 
#include <cmath> 
#include <string>
#include <sstream> 
#include <vector> 
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void fill(vvi& A, vi& pt, char c)
{
    for (int i = 0; i < pt[2]; ++i)
        for (int j = 0; j  < pt[3]; ++j)
            A[pt[0] + i][pt[1] + j] = c;
}

void process(vvi& A, int a, int b, int row, int col, string& res)
{
    int ones = 0;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (A[a + i][b + j] == '1')
                ++ones;

    if (ones == row * col)
        res += "1";
    else if (ones == 0)
        res += "0";
    else
    {
        res += "D";
        int row2 = ceil(row / 2.0);
        int col2 = ceil(col / 2.0);
        process(A, a, b, row2, col2, res);
        if (col - col2)
            process(A, a, b + col2, row2, col - col2, res);
        if (row - row2)
            process(A, a + row2, b, row - row2, col2, res);
        if (col - col2 && row - row2)
            process(A, a + row2, b + col2, row - row2, col - col2, res);
    }
}

int main()
{
    char c;
    int row, col;
    string s, tmp;
    getline(cin, tmp);
    while (tmp[0] != '#')
    {
        istringstream iss(tmp);
        iss >> c >> row >> col;
        getline(cin, tmp);
        s = "";
        while (tmp.find_first_of(' ') == string::npos && tmp != "#")
        {
            s += tmp;
            getline(cin, tmp);
        }
        
        vvi A(row, vi(col));
        if (c == 'B')
        {
            for (int i = 0; i < row; ++i)
                for (int j = 0; j < col; ++j)
                    A[i][j] = s[i * col + j];

            cout << "D" << setw(4) << row << setw(4) <<col << "\n";
            string res;
            process(A, 0, 0, row, col, res);
            int end = ceil(res.size() / 50.0);
            for (int i = 0; i < end; ++i)
                cout << res.substr(50 * i, 50) << "\n";
        }
        else if (c == 'D')
        {
            vvi stk;
            stk.push_back(vi{0, 0, row, col});
            for (char ch : s)
            {
                vi last = stk.back();
                stk.pop_back();
                if (ch == 'D')
                {
                    int row2 = ceil(last[2] / 2.0);
                    int col2 = ceil(last[3] / 2.0);

                    if (last[2] - row2 && last[3] - col2)
                        stk.push_back(vi{last[0] + row2, last[1] + col2, last[2] - row2, last[3] - col2});
                    if (last[2] - row2)
                        stk.push_back(vi{last[0] + row2, last[1], last[2] - row2, col2});
                    if (last[3] - col2)
                        stk.push_back(vi{last[0], last[1] + col2, row2, last[3] - col2});
                    stk.push_back(vi{last[0], last[1], row2, col2});
                }
                else
                    fill(A, last, ch);
            }
            
            cout << "B" << setw(4) << row << setw(4) <<col << "\n";
            int cnt = 0;
            for (auto& v : A)
                for (int num : v)
                {
                    cout << char(num);
                    if (++cnt == 50)
                        cout << "\n", cnt = 0;
                }
            
            if (cnt)
                cout << "\n";
        }
    }
}
