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

map <int, int> mp;

signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T; cin >>T;
    while(T --)
    {
        mp.clear();

        int n; cin >>n;
        
        int a[n];
        for(int i = 0; i < n; i ++) cin >>a[i];
        
        vector <int> v; int f = 0; int m;
        for(int i = 0; i < n; i ++)
        {
            int x = a[i];
            mp[x] ++;
            if(mp[x] == 2)
            {
                f = 3;
                v.push_back(x);
            }
            if(v.size() >= 2)
            {
                f = 1;
                break;
            }
            if(mp[x] >= 4)
            {
                f = 2; m = x;
                break;
            }
        }
        if(f == 0)
        {
            cout <<-1 <<endl;
            continue;
        }
        if(f == 1)
        {
            cout <<v[0] <<" " << v[0] <<" " <<v[1] <<" " <<v[1] <<endl;
            continue;
        }
        else if(f == 2)
        {
            for(int i = 0; i < 4; i ++) cout <<m <<" ";
            cout <<endl;
            continue;
        }
        else
        {
            int cnt = 2; int x = v[0];
            vector <int> b;
            for(int i = 0; i < n; i ++)
            {
                if(cnt == 0)
                {
                     b.push_back(a[i]);
                     continue;
                }
                if(a[i] == x)
                {
                    cnt --;
                }
                else b.push_back(a[i]);
            }
            sort(b.begin(), b.end());
            int r = 0x3f3f3f3f; bool ss = 0;
            for(int i = 0; i < b.size() - 1; i ++)
            {
                int s = b[i + 1] - b[i];
                if(s < 2 * x)
                {
                    cout <<x <<" " <<x <<" " <<b[i] <<" " <<b[i + 1] <<endl;
                    ss = 1;
                    break;
                }
            }
            if(!ss) cout <<-1 <<endl;
        }
    }
    
    return 0;
}