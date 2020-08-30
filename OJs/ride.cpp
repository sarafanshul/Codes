/*
ID: dt_20021
TASK: ride
LANG: C++                 
*/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
inline T mod(T a ,T b){return (a*b >= 47)?((a*b)-47):(a*b);}

int ck(string s){
	int pr = 1;
	for(int i = 0; i<s.size(); i++){
		pr = mod(pr,(s[i] - '0'));
	}
	return pr;
}

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    string a,b;
    fin >> a >> b;
    if (ck(a) == ck(b)) fout << "GO";
    else fout << "STAY";
    return 0;
}