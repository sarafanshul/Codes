#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	string c;
	cin >> N;
	
	while (N--)
	{
		cin >> c;
		if (c == "78" || c == "4" || c == "1")
			cout << "+\n";
		else if (c[0] == '9' && c[c.size() - 1] == '4')
			cout << "*\n";
		else if (c.substr(c.size() - 2, string::npos) == "35")
			cout << "-\n";
		else
			cout << "?\n";
	}
	
	return 0;
}
