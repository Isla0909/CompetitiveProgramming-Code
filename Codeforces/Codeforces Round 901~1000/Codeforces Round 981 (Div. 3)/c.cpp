#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#define ff first
#define se second
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

void tell(int w[], int n)
{
    for(int i = 1; i <= n; i ++)
        cout <<w[i] <<" \n"[i == n];
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        vector <int> a(n + 1, 0);
        for(int i = 1; i <= n; i ++) cin >>a[i];

        for(int i = 2; i <= n - 1; i ++)
        {
            int j = n - i + 1;
            if(a[i] == a[j]) continue;

            int c1 = 0, c2 = 0;
            if(a[i - 1] == a[i]) c1 ++;
            if(a[j] == a[j + 1]) c1 ++;
            
            swap(a[i], a[j]);
            if(a[i - 1] == a[i]) c2 ++;
            if(a[j] == a[j + 1]) c2 ++;
        

            if(c2 >= c1) swap(a[i], a[j]);
        }

        //tell(a, n);

        int ans = 0;
        for(int i = 1; i < n; i ++)
            if(a[i] == a[i + 1])
                ans ++;
        cout <<ans <<endl;
    }
    return 0;
}