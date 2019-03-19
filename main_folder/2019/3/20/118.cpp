#include <iostream>
#include <string>
using namespace std;

int main()
{
	int dx[] = {0, 1,  0, -1};
	int dy[] = {1, 0, -1,  0};
	int row, col, x, y, xx, yy;
	char d;
	string S[51](string(51, '0')), com, NESW = "NESW";
	cin >> col >> row;
	
	while (cin >> x >> y >> d >> com)
	{
		bool lost = false;
		int dir = NESW.find(d);
		for (char c : com)
		{
			if (c == 'L')
				dir = (dir + 3) % 4;
			else if (c == 'R')
				dir = (dir + 1) % 4;
			else
			{
				xx = x + dx[dir];
				yy = y + dy[dir];			
				if (xx >= 0 && yy >= 0 && xx <= col && yy <= row)
					x = xx, y = yy;
				else if (S[x][y] == '0')
				{
					S[x][y] = '1';
					lost = true;
					break;
				}
			}		
		}		
		cout << x << ' ' << y << ' ' << string(1, NESW[dir]) << (lost ? " LOST\n" : "\n");
	}	
}
