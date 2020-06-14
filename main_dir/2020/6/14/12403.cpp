#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, bal = 0;
	string s;
	cin >> N;
	while (N--)
	{
		cin >> s;
		if (s == "donate")
		{
			int don;
			cin >> don;
			bal += don;
		}
		else
			cout << bal << "\n";
	}
	
	return 0;
}
