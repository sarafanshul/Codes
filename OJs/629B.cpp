/*
If you notice carefully here k <= n-i-1 is really k <= (n-1)-i. And this (n-1)-i indicates the available position for right most 'b'.

Now lets try to find a pattern from the given example in problem statement.

when the left most 'b''s position is 3 we have 1 available space for rightmost 'b'

when the left most 'b''s position is 2 we have 2 available space for rightmost 'b'

when the left most 'b''s position is 1 we have 3 available space for rightmost 'b'

when the left most 'b''s position is 0 we have 4 available space for rightmost 'b'

K   STRING  POS.
1   aaabb    1
2   aabab    2
3   aabba    2
4   abaab    3
5   ababa    3
6   abbaa    3
7   baaab    4 
8   baaba    4
9   babaa    4
10  bbaaa    4
Notice if k > available position for 2nd 'b' that means we have 
to increase the available position and to increase it we have to 
shift our 1st 'b' 1 position left. 
And if we shift our 1st 'b' 1 position left that means we have 
already considered all the position for 2nd 'b' for the available position. 
So we simply just subtract available position from k
*/

#include <bits/stdc++.h>
using namespace std;

int check(){
	int n, k;
	cin >> n >> k;
	string s(n, 'a');
	
    for (int i = n - 2; i >= 0; i--) {
        if (k <= (n - i - 1)) {
            s[i] = 'b';
            s[n - k] = 'b';
            cout << s << "\n";
            break;
        }
        k -= (n - i - 1);
    }
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		check();
	}
	return 0;
}
