#include <iostream>
#include <string>
using namespace std;

char signum(int &a)
{
	if (a > 0)
		return '+';
	if (a < 0)
		return '-';
	return ' ';
}

int main()
{
	int l;
	while (cin >> l, l != 0)
	{
		int Dir[3] = {1, 0, 0};
		char L[3] = {'x', 'y', 'z'};
		while (--l)
		{
			string s;
			cin >> s;
			if (s == "+y")
			{
				if (!Dir[2] && Dir[0])
				{
					Dir[1] += Dir[0];
					Dir[0] = 0;
				}
				else if (!Dir[2] && Dir[1])
				{
					Dir[0] -= Dir[1];
					Dir[1] = 0;							
				}
			}
			else if (s == "-y")
			{			
				if (!Dir[2] && Dir[0])
				{
					Dir[1] -= Dir[0];
					Dir[0] = 0;
				}
				else if (!Dir[2] && Dir[1])
				{
					Dir[0] += Dir[1];
					Dir[1] = 0;							
				}
			}
			else if (s == "+z")
			{
				if (!Dir[1] && Dir[0])
				{
					Dir[2] += Dir[0];
					Dir[0] = 0;
				}
				else if (!Dir[1] && Dir[2])
				{
					Dir[0] -= Dir[2];
					Dir[2] = 0;							
				}
			}
			else if (s == "-z")
			{
				if (!Dir[1] && Dir[0])
				{
					Dir[2] -= Dir[0];
					Dir[0] = 0;
				}
				else if (!Dir[1] && Dir[2])
				{
					Dir[0] += Dir[2];
					Dir[2] = 0;						
				}
			}
		}

		for (int j = 0; j < 3; ++j)
				if (Dir[j])
					cout << signum(Dir[j]) << L[j] << '\n';		
	}
	
	return 0;
}
