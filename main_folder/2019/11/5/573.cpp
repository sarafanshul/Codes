#include <iostream>
using namespace std;

int main()
{
	int h, d;
	float u, f;
	while (cin >> h >> u >> d >> f, h || u || d || f)
	{
		float pos = 0;
		int day = 0;
		f = f / 100.0 * u; //Decreasing rate
		while (pos >= 0 && pos < h && ++day)
		{
			pos += u;
			if (pos > h)
				break;
			
			pos -= d;
			if (pos < 0)
				break;
				
			u -= (u - f >= 0 ? f : u);
		}
		if (pos > 0)
			cout << "success on day " << day << "\n";
		else
			cout << "failure on day " << day << "\n";
	}
	
	
	return 0;
}
