#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define ff first
#define se second
#define endl '\n'
using namespace std;

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        int a[n];
        for(int i = 0; i < n; i ++) cin >>a[i];

        int s1 = 0, s2 = 0;
        for(int i = 0; i < n; i ++)
        {
            if(a[i] % 2 != 0) s1 ++;
            else s2 ++;
        }
        if(s2) cout <<1 + s1 <<endl;
        else cout <<s1 - 1 <<endl;
    }
    
    return 0;
}