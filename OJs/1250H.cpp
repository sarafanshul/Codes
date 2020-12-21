#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int a[11];
int main()
{
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i ++)
    {
        for (int j = 0 ; j < 10 ; j ++)
            cin>>a[j];
        int flag = 0;
        for(int k = 0 ; k < 1000005;k ++)
        {
            if(a[0] == k-1)
            {
                cout<<1;
                for(int j = 0 ; j < k ; j ++)
                    cout<<0;
                cout<<endl;
                break;
            }
            for(int j = 1 ; j < 10 ; j ++)
            {
                if(a[j] == k)
                {
                    for(int l = 0 ; l <= k ; l ++)
                        cout<<j;
                    cout<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }

    }
}
