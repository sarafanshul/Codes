#include <iostream>
#include <string>
using namespace std;

string E[8] = {"........", "........", "........", "........",
			   "........", "........", "........", "........"};
int cnt = 1;
bool call_it_a_day = false;

bool cmp(string (&a)[8], string (&b)[8])
{
	for (int i = 0; i < 8; ++i)
		if (a[i] != b[i])
			return false;
	
	return true;
}

bool is_legal(int a, int b)
{
	return (a >= 0 && a <= 7 && b >= 0 && b <= 7);
}

void msg(string a)
{
	cout << "Game #" << cnt++ << ": " << a << " king is in check.\n";
}

void do_case()
{
	string B[8];
	for (int i = 0; i < 8; ++i)
		cin >> B[7 - i];
	
	if (cmp(B,E))
	{
		call_it_a_day = true;
		return;
	}
		
	//Finding king coordinates
	unsigned k[2], K[2];
	for (int i = 0; i < 8; ++i)
	{
		long unsigned F[2] = {B[i].find('k'), B[i].find('K')};
		if (F[0] != string::npos)
		{
			k[0] = i;
			k[1] = F[0];
		}
		if (F[1] != string::npos)
		{
			K[0] = i;
			K[1] = F[1];
		}
	}
	
	//Find the checking piece(s).
	//		If any nonchecking piece is on the way => break!
	int Dir[2][8] = {{1, 1, 1, 0, 0, -1, -1, -1},
					{-1, 0, 1, -1, 1, -1, 0, 1}};
	string Ch[2][8] = {{"bq", "rq", "bq", "rq", "rq", "bq", "rq", "bq"},
					   {"BQ", "RQ", "BQ", "RQ", "RQ", "BQ", "RQ", "BQ"}};
					   
	for (int i = 0; i < 8; ++i)
	{
		unsigned it1[2] = {K[0] + Dir[0][i], K[1] + Dir[1][i]};
		unsigned it2[2] = {k[0] + Dir[0][i], k[1] + Dir[1][i]};		
		
		while (is_legal(it1[0], it1[1]))
		{
			if (Ch[0][i].find(B[it1[0]][it1[1]]) != string::npos)
				return msg("white");
			if (B[it1[0]][it1[1]] != '.')
				break;
			it1[0] += Dir[0][i];
			it1[1] += Dir[1][i];
		}
		while (is_legal(it2[0], it2[1]))
		{
			if (Ch[1][i].find(B[it2[0]][it2[1]]) != string::npos)
				return msg("black");
			if (B[it2[0]][it2[1]] != '.')
				break;
			it2[0] += Dir[0][i];
			it2[1] += Dir[1][i];
		}
	}	
	
	//Check if N is giving check:
	int NDir [2][8]	= {{1, 2, 2, 1, -1, -2, -2, -1},
					  {-2, -1, 1, 2, -2, -1, 1, 2}};
	for (int i = 0; i < 8; ++i)
	{
		if (is_legal(K[0] + NDir[0][i], K[1] + NDir[1][i])
			&& B[K[0] + NDir[0][i]][K[1] + NDir[1][i]] == 'n')
			return msg("white");
		if (is_legal(k[0] + NDir[0][i], k[1] + NDir[1][i])
			&& B[k[0] + NDir[0][i]][k[1] + NDir[1][i]] == 'N')
			return msg("black");
	}
	
	//Check if p is giving check:
	for (int i = -1; i < 2; i += 2)
	{
		if (is_legal(K[0] + 1, K[1] + i)
			&& B[K[0] + 1][K[1] + i] == 'p')
			return msg("white");
		if (is_legal(k[0] - 1, k[1] + i)
			&& B[k[0] -1][k[1] + i] == 'P')
			return msg("black");
	}
	
	return msg("no");
}


int main()
{	
	while (!call_it_a_day)
		do_case();	
}
