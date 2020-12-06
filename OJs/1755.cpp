#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
const int MOD = 1e9+7;

string check(string str) { 
 	unordered_map<char, int> hmap; 
  	for (int i = 0; i < str.length(); i++) hmap[str[i]]++; 
	int oddCount = 0; 
	char oddChar; 
	for (auto x : hmap) { 
		if (x.second % 2 != 0) { 
		  	oddCount++; 
		  	oddChar = x.first; 
		} 
	 } 
	  
	if (oddCount > 1 || oddCount == 1 && str.length() % 2 == 0) 
		return "NO SOLUTION";

	string firstHalf = "", secondHalf = ""; 
	for (auto x : hmap) { 
		string s(x.second / 2, x.first); 
		firstHalf = firstHalf + s; 
		secondHalf = s + secondHalf; 
  	}
  	return (oddCount == 1) ? (firstHalf + oddChar + secondHalf) : (firstHalf + secondHalf); 
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	cout << check(s);
	return 0;
}
