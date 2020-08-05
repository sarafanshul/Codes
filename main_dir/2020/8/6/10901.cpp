#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
#define MP make_pair

int main()
{
	int c, load, time, nr_cars, ctime, tmp;
	cin >> c;
	while (c--)
	{
		cin >> load >> time >> nr_cars;
		string start, str;
		deque<ii> D[2];
		string LR[2] = {"left", "right"};
		vector<int> res(nr_cars);
		
		for (int i = 0; i < nr_cars; ++i)
		{
			cin >> tmp >> str;
			D[str == "right"].push_back(MP(i, tmp));
		}
		
		//Determine the start
		if (!D[0].empty() && !D[1].empty())
			start = D[1].front().second < D[0].front().second ? "right" : "left";
		else if (!D[0].empty())
			start = "left";
		else if(!D[1].empty())
			start = "right";
			
		ctime = (start == "left") ? D[0].front().second : D[1].front().second + time;
		
		while (!D[0].empty() || !D[1].empty())
		{
			bool flag = false; //Did the ferry load sth?
			for (int d = 0; d < 2; ++d)
				if (start == LR[d])
				{
					for (int i = 0; i < load && !D[d].empty() && D[d].front().second <= ctime; ++i)
					{
						res[D[d].front().first] = ctime + time;
						D[d].pop_front();
						flag = true;
						
					}
					if (flag)
					{	
						ctime += time;
						start = LR[!d];
						break;
					}
					else
					{
						if (!D[0].empty() && !D[1].empty())
						{
							ctime = D[d].front().second <= D[!d].front().second ? D[d].front().second : max(D[!d].front().second + time, ctime + time);
							start = D[d].front().second <= D[!d].front().second ? LR[d] : LR[!d];
						}
						else if (!D[d].empty())
						{
							ctime = D[d].front().second;
							start = LR[d];
						}
						else
						{
							ctime = max(D[!d].front().second + time, ctime + time);
							start = LR[!d];
						}
						break;
					}
				}
			
		}
		for (int elem : res)
			cout << elem << '\n';
		if (c > 0)
			cout << '\n';
	}
}
