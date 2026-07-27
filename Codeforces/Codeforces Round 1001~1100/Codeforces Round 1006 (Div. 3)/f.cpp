#include <iostream>
#define int long long
using namespace std;


bool hhh(int n, int k) 
{
    return (n & k) == k;
}


void c(int n, int k) 
{
    for (int i = 0; i < n; i++) 
    {
        if (hhh(n - 1, i)) 
        {
            cout << k << " ";
        } 
        else 
        {
            cout << 0 << " ";
        }
    }
    cout << endl;
}

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) 
    {
        int n, k; cin >> n >> k;
        c(n, k);
    }
    return 0;
}