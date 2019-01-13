#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A[26] = {"", "1", "2", "3", "", "1", "2", "", "", "2", "2", "4", "5",
					"5", "", "1", "2","6", "2", "3", "", "1", "", "2", "", "2"};
	
	string word;
	while (cin >> word)
	{
		string res;
		char prev = '?';
		for (char c : word)
			if (A[c - 'A'] != A[prev - 'A'])
			{
				res.append(A[c - 'A']);
				prev = c;
			}
		cout << res + "\n";				
	}
}
