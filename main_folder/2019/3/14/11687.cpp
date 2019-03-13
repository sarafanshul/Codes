#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (cin >> s, s != "END")
	{		
		if (s == "1")
			cout << "1\n";
		else if (s.size() < 2)
			cout << "2\n";
		else if (s.size() < 10)
			cout << "3\n";
		else
			cout << "4\n";		
	}	
}
