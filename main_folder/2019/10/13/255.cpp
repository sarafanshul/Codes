#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main()
{
	int P[3];
	while (cin >> P[0] >> P[1] >> P[2])	 //K; Q_source; Q_target
	{
		if (P[0] == P[1])
		{
			cout << "Illegal state\n";
			continue;
		}
		
		int Qmove = abs(P[2] - P[1]);		
		int diff = Qmove < 8 ? 1 : 8;		
		int Qmax = max(P[1], P[2]), Qmin = min(P[1], P[2]);
		
		//Check if the queen move is legal
		if (diff == 1 && P[1] / 8 != P[2] / 8
		 || diff == 8 && P[1] % 8 != P[2] % 8
		 || P[1] == P[2] || P[2] == P[0])
		{
			cout << "Illegal move\n";
			continue;
		}
		
		//Squares the Q will cross
		vi Path;
		while ((Qmin += diff) < Qmax)
			Path.push_back(Qmin);
		
		//K and Q_target adjacent squares
		int Adj[2][4];
		
		for (int i = 0; i < 3; i += 2)
		{
			auto init = { (P[i] % 8 != 0 ? P[i] - 1 : -1),
						  (P[i] % 8 != 7 ? P[i] + 1 : -1),
						  (P[i] >= 8     ? P[i] - 8 : -1),
						  (P[i] <= 55    ? P[i] + 8 : -1) };
			copy(init.begin(), init.end(), Adj[i/2]);
		}
		
		bool flag = false;
		//Check if King is on Queen's path		
		for (int square : Path)
			if (P[0] == square)
			{
				cout << "Illegal move\n";
				flag = true;
			}
		if (flag)
			continue;
				
		//Check if Q_target is in K's adjacency
		for (int i = 0; i < 4; ++i)
			if (P[2] == Adj[0][i])
			{
				cout << "Move not allowed\n";
				flag = true;
				break;
			}
		
		if (flag)
			continue;
		
		//Check whether king has allowed moves
		for (int i = 0; i < 4; ++i)
		{
			if (Adj[0][i] >= 0)		//-1 is illegal square
			{
				flag = true;
				for (int j = 0; j < 4; ++j)
					if (Adj[0][i] == Adj[1][j])
						flag = false;
				if (flag)
				{
					cout << "Continue\n";
					break;
				}
			}
		}
		if (!flag)
			cout << "Stop\n";
	}	
}
