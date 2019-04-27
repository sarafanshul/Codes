#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, a2[2] = {"``","''"};
	bool flag = false;
	while (getline(cin,a))
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] == '\"')
			{
				cout << a2[flag];
				flag = !flag;
			}
			else
				cout << a[i];			
		}
		cout << "\n";
	}
}
