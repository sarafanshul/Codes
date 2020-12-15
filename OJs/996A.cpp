#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;
 
const int N = 1e6+6;
const int T = 1e6+6;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    ll bills = 0;
    if (n >= 100){
        bills += n/100;
        n %= 100;
    }
    if (n >= 20){
        bills += n / 20;
        n %= 20;
    }
    if (n >= 10){
        bills += n / 10;
        n %= 10;
    }
    if (n >= 5){
        bills += n / 5;
        n %= 5;
    }
    bills += n;
    cout << bills <<"\n";
    return 0;
}