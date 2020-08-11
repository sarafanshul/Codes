#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define MP make_pair

int n;
vii Pos;
vvi Mat;

void ret_stacked(int &a)
{
	//Return blocks stacked on a on their initial positions
	int a1, a2;
	tie(a1, a2) = Pos[a];
	
	for (int j = a2 + 1; j < Mat[a1].size(); ++j)
	{
		int elem = Mat[a1][j];
		Pos[elem] = MP(elem, 0);
		Mat[elem].resize(1);
		Mat[elem][0] = elem;		
	}
	Mat[a1].resize(a2 + 1);
	
}

void pile(int &a, int&b)
{
	//Piles a and all blocks above it onto the stack which contains b
	int a1, a2;
	tie(a1, a2) = Pos[a];
	int b1 = Pos[b].first;
	
	for (int j = a2; j < Mat[a1].size(); ++j)
	{
		int elem = Mat[a1][j];
		Mat[b1].push_back(elem);
		Pos[elem] = MP(b1, Mat[b1].size() - 1);
	}
	Mat[a1].resize(a2);
}

void printMat()
{
	for (int j = 0; j < Mat.size(); ++j)
	{	
		cout << j << ":";
		for (int i = 0; i < Mat[j].size(); ++i)
			cout << " " << Mat[j][i];
		cout << endl;
	}
}

int main()
{	
	cin >> n; // 0 < n < 25
	cin.ignore();
	
	Pos.resize(n);
	Mat.resize(n);
	for (int i = 0; i < n; ++i)
		Mat[i] = vi(1,i), Pos[i] = MP(i, 0);
	
	string str;
	while (getline(cin, str), str != "quit")
	{
		istringstream iss(str);
		string com1, com2;
		int a, b;
		iss >> com1 >> a >> com2 >> b;
		
		int a1, a2, b1, b2;
		tie(a1, a2) = Pos[a];
		tie(b1, b2) = Pos[b];
				
		if (a == b || a1 == b1) //Illegal moves
			continue;
		
		if (com1 == "move")
		{
			if (com2 == "onto")
			{
				ret_stacked(a);
				ret_stacked(b);
				Mat[a1].resize(a2);
				Mat[b1].push_back(a);
				Pos[a] = MP(b1, b2 + 1);
			}
			else
			{
				ret_stacked(a);
				Mat[a1].resize(a2);
				Mat[b1].push_back(a);
				Pos[a] = MP(b1, Mat[b1].size() - 1);
				
			}
		}
		if (com1 == "pile")
		{
			if (com2 == "onto")
			{
				ret_stacked(b);
				pile(a, b);
			}
			else
				pile(a,b);
		}
	}
	printMat();
}
