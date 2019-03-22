#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int T, cnt = 1;
	string cmd;
	cin >> T;
	while (T--)
	{
		cin >> cmd;
		unsigned char M[100];
		memset(M, 0, 100 * sizeof(unsigned char));
		int ptr = 0;
		for (char c : cmd)
		{
			if (c == '>')
				ptr = (ptr + 1) % 100;
			else if (c == '<')
				ptr = (ptr + 99) % 100;
			else if (c == '+')
				M[ptr] += 1;
			else if (c == '-')
				M[ptr] -= 1;
		}
		cout << "Case " << dec << cnt++ << ":";
		cout << hex << uppercase;
		for (unsigned char j : M)
			cout << " " << (j < 16 ? "0" : "") << int(j);
		cout << "\n";		
	}	
}
