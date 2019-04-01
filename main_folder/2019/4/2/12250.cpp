#include <iostream>
using namespace std;

int main()
{
	int cnt = 1;
	string s; 
	string G[7] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE", ""};
	string L[7] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN", "UNKNOWN"};
	
	while (cin >> G[6], G[6] != "#")
	{
		for (int i = 0; i < 7; ++i)
			if (G[6] == G[i])
			{
				cout << "Case " << cnt++ << ": " << L[i] << "\n";
				break;
			}		
	}
}
