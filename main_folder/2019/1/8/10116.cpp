#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef vector<string> vs;

int main()
{
	map<char, int> Dir;
	Dir['N'] = 0; Dir['E'] = 1; Dir['S'] = 2; Dir['W'] = 3;
	int dx[] = { 0,  1,  0, -1};
	int dy[] = {-1,  0,  1,  0};
	int r, c, s;
	
	while (cin >> r >> c >> s, s-- || c || r)	
	{
		int x = s, y = 0, r1 = 0, r2 = 0;
		vs G(r), A(r, string(c, '0'));
		for (int i = 0; i < r; ++i)
			cin >> G[i];
		
		A[y][x] = 1;
		int xx = x + dx[Dir[G[y][x]]];
		int yy = y + dy[Dir[G[y][x]]];
		while (r1 = A[y][x], xx >= 0 && yy >= 0 && xx < c && yy < r)
		{			
			if (A[yy][xx] == '0')
				A[yy][xx] = A[y][x] + 1;
			else
			{
				r2 = A[yy][xx];
				break;
			}
			
			x = xx; y = yy;
			xx += dx[Dir[G[y][x]]];
			yy += dy[Dir[G[y][x]]];			
		} 
		
		if (r2)
			cout << r2 - 1 << " step(s) before a loop of " << r1 - r2 + 1 << " step(s)\n";
		else
			cout << r1 << " step(s) to exit\n";
	}
}
