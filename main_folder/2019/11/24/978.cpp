#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
#include <functional>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		multiset<int, greater<int> > MS[2];
		int bf, army[2], tmp;
		cin >> bf >> army[0] >> army[1];
		for (int j = 0; j < 2; ++j)
			for (int i = 0; i < army[j]; ++i)
			{
				cin >> tmp;
				MS[j].insert(tmp);
			}
			
		while (!MS[0].empty() && !MS[1].empty())
		{
			for (int i = std::min({bf, int(MS[0].size()), int(MS[1].size())}) - 1 ; i >= 0 ; --i)
			{
				multiset<int>::iterator it[2] = {MS[0].begin(), MS[1].begin()};				
				for (int k = 0; k < 2; ++k)
					advance(it[k], i);		
				
				if (*(it[0]) == *(it[1]))
					for (int k = 0; k < 2; ++k)
						MS[k].erase(it[k]);

				else if (*(it[0]) > *(it[1]))
				{
					MS[0].insert(*(it[0]) - *(it[1]));
					for (int k = 0; k < 2; ++k)
						MS[k].erase(it[k]);
				}
				else
				{
					MS[1].insert(*(it[1]) - *(it[0]));
					for (int k = 0; k < 2; ++k)
						MS[k].erase(it[k]);
				}
			}
		}
		if (MS[0].empty() && MS[1].empty())
			cout << "green and blue died\n";
		else if (!MS[0].empty())
		{
			cout << "green wins\n";
			for (int elem : MS[0])
				cout << elem << '\n';				
		}
		else
		{
			cout << "blue wins\n"; 
			for (int elem : MS[1])
					cout << elem << '\n';
		}
		if (N > 0)
			cout << '\n';
	}
}
