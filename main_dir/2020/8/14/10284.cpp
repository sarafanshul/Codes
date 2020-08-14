#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

bool is_legal(int a, int b)
{
	return (a >= 0 && a <= 7 && b >= 0 && b <= 7);
}

int main()
{
	string FEN;
	while (cin >> FEN)
	{
		int res = 0;
		//Representation of FEN in char array
		char B[8][8];
		for (int i = 0; i < 8; ++i)
			memset(B[i], '.', 8 * sizeof(char));
		int i = 0, j = 0; // row, col from UL to DR
		for (char c : FEN)
		{	
			if (c == '/')
			{
				i++;
				j = 0;
			}
			else if (!isalpha(c))
			{			
				j += (c - '0');
				res += (c - '0');
			}
			else
			{
				B[i][j++] = (c != 'p' && c != 'P' ? tolower(c) : c);
			}
		}
		
		int Dir[2][16] = {{1, 1, 1, 0, 0, -1, -1, -1,/*N*/ 1, 2, 2, 1, -1, -2, -2, -1},
						 {-1, 0, 1, -1, 1, -1, 0, 1, /*N*/-2, -1, 1, 2, -2, -1, 1, 2}};
						 
		map<char, string> M; 
		//string[0] Piece range ... string[1+] = Index of allowed Dir
		M['p'] = "102";
		M['P'] = "157";
		M['r'] = "81346";
		M['b'] = "80257";
		M['q'] = "801234567";
		M['k'] = "101234567";
		M['.'] = "0";
		M['#'] = "0"; //# := symbol for visited square
		M['n'] = "189:;<=>?"; 
		
		//Iteracija kroz ploču
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				for (char c : M[B[i][j]].substr(1))
				{
					int it[2] = {i + Dir[0][c - '0'], j + Dir[1][c - '0']};
					for (int k = 0; k < (M[B[i][j]][0] - '0') && is_legal(it[0], it[1]); ++k)
					{
						if (B[it[0]][it[1]] == '#')
						{
							it[0] += Dir[0][c - '0'];
							it[1] += Dir[1][c - '0'];
							continue;							
						}
						if (B[it[0]][it[1]] == '.')
						{
							res--;
							B[it[0]][it[1]] = '#';
							it[0] += Dir[0][c - '0'];
							it[1] += Dir[1][c - '0'];
							continue;
						}						
						break;
					}
				}
			}
		}			
		cout << res << "\n";		
	}
}
