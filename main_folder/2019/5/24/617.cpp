#include <iostream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, c = 1;
	while (cin >> n, n != -1)
	{
		bitset<31> BS;
		
		double l;
		int g, y, r;
		for (int i = 0; i < n; ++i)
		{
			cin >> l >> g >> y >> r;
			for (int x = 30; x <= 60; ++x)
				if (!BS[x - 30])
				{
					double time = fmod(3600 * l / x, r + g + y);					
					BS.set(x - 30,  time > g + y && time < r + g + y);					
				}					
		}
		
		//Output the results
		cout << "Case " << c++ << ": ";
		string s = BS.to_string();
		reverse(s.begin(), s.end());
		
		if (s != string(31, '1'))
		{
			int start = s.find_first_of('0');
			int end = s.find_first_of('1', start);
			
			while (start != string::npos)
			{
				if (end != string::npos)
					cout << (end - start > 1 ? to_string(start + 30) + "-" + to_string(end + 29) : to_string(start + 30));
				else
					cout << (31 - start > 1 ? to_string(start + 30) + "-" + to_string(60) : to_string(60));
				
				start = s.find_first_of('0', end);
				end = s.find_first_of('1', start);
				cout << (start == string::npos ? "" : ", ");
			}
			cout << "\n";
		}
		else
			cout << "No acceptable speeds.\n";
	}
}
