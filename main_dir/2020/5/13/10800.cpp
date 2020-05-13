#include <algorithm> 
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    for (int c_no = 1; c_no <= n; ++c_no)
    {
        cout << "Case #" << c_no << ":\n";
        cin >> s;
        int H[50], curr = 0;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == 'R')
                H[i] = curr++;
            else if (s[i] == 'F')
                H[i] = --curr;
            else
                H[i] = curr;

        auto mm = minmax_element(H, H + s.size());
        int y1 = *mm.first, y2 = *mm.second;

        for (int y = y2; y >= y1; --y)
        {
            string res(s.size(), ' ');
            for (int i = 0; i < s.size(); ++i)
                if (H[i] == y)
                    res[i] = s[i] == 'C' ? '_' : (s[i] == 'R' ? '/' : '\\');

            res.erase(res.find_last_of("\\_/") + 1);
            cout << "| " << res << '\n';
        }
        cout << "+" << string(s.size() + 2, '-') << "\n\n";
    }    
}
