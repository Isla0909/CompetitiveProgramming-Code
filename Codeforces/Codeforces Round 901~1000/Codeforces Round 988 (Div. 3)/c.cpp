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
#define st begin()
#define ed end()
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f;

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    int T; cin >>T;
    while(T --)
    {
        int n; cin >>n;
        if(n <= 4) cout <<-1 <<endl;
        else
        {
            for(int i = 1; i <= n; i += 2)
                if(i != 5) cout <<i <<" ";
            cout <<5 <<" " <<4 <<" ";
            for(int i = 2; i <= n; i += 2)
                if(i != 4) cout <<i <<" ";
            cout <<endl;
        }
    }
    return 0;
}