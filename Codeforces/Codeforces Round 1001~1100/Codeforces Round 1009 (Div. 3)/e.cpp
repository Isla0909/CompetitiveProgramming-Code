#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#define ff first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
bool f = 0;

int ask(int i, int j, int k) 
{
    cout <<"? " <<i <<" " <<j <<" " <<k <<endl;
    fflush(stdout);
    int res; cin >>res;
    return res;
}

void find(int a, int b, int c) 
{
	if(f) return ;
    int i1 = ask(a, b, c);
    if (i1 == 0) 
    {
    	f = 1;
        cout <<"! " <<a <<" " <<b <<" " <<c <<endl;
        fflush(stdout);
        return;
    }
    int i2 = ask(a, b, i1), i3 = ask(a, c, i1);
    if(i2 == 0)
    {
    	f = 1;
    	cout <<"! " <<a <<" " <<b <<" " <<i1 <<endl;
    	fflush(stdout);
        return;
    }
    if(i3 == 0)
    {
    	f = 1;
    	cout <<"! " <<a <<" " <<c <<" " <<i1 <<endl;
    	fflush(stdout);
        return;
    }
    find(i1, i2, i3);
}

signed main() 
{
    int T; cin >>T;
    while (T --) 
    {
        int n; cin >>n;
        if(n == 3)
        {
        	cout <<"! 1 2 3" <<endl;
        	fflush(stdout);
        	continue;
        }
        f = 0;
        find(1, 2, 3);
    }
    return 0;
}