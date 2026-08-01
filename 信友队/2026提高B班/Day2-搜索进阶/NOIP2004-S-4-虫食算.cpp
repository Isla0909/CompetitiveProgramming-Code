#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

constexpr int N = 20;

int n;

// 三个字符串，反转后第 0 位是个位
string s[3];

// val[i]：字母 i 代表的数字
// -1 表示还没有确定
int val[N];

// used[d]：数字 d 是否已经被某个字母使用
bool used[N];

/*
    检查所有“字母都已经确定”的列，
    看它们是否至少存在一种可能的进位。
*/
bool check()
{
    for(int pos = 0; pos < n; pos++)
    {
        int x = s[0][pos] - 'A';
        int y = s[1][pos] - 'A';
        int z = s[2][pos] - 'A';

        // 这一列还有字母没确定，暂时无法判断
        if(val[x] == -1 || val[y] == -1 || val[z] == -1)
            continue;

        bool ok = false;

        /*
            个位的传入进位一定是 0。

            其他位置的传入进位暂时可能是 0 或 1。
        */
        int l = 0;
        int r = (pos == 0 ? 0 : 1);

        for(int carry = l; carry <= r; carry++)
        {
            int sum = val[x] + val[y] + carry;

            if(sum % n != val[z])
                continue;

            /*
                最高位不能再向外产生进位，
                因为结果也只有 n 位。
            */
            if(pos == n - 1 && sum >= n)
                continue;

            ok = true;
        }

        if(!ok)
            return false;
    }

    return true;
}

/*
    pos：当前处理的列
    carry：低位传来的进位
    stage：
        0：处理第一个加数
        1：处理第二个加数
        2：计算结果字母
*/
bool dfs(int pos, int carry, int stage)
{
    /*
        所有 n 列都处理完成。

        最高位不能再产生进位，
        所以 carry 必须是 0。
    */
    if(pos == n) return carry == 0;

    int x = s[0][pos] - 'A';
    int y = s[1][pos] - 'A';
    int z = s[2][pos] - 'A';

    /*
        先分别确定两个加数的字母。
    */
    if(stage < 2)
    {
        int ch;

        if(stage == 0)
            ch = x;
        else
            ch = y;

        /*
            该字母以前已经确定，
            直接处理下一个字母。
        */
        if(val[ch] != -1)
            return dfs(pos, carry, stage + 1);

        /*
            给这个字母枚举一个尚未使用的数字。

            倒序或正序都可以，因为题目保证答案唯一。
            通常倒序搜索在这道题中表现较好。
        */
        for(int d = n - 1; d >= 0; d--)
        {
            if(used[d])
                continue;

            val[ch] = d;
            used[d] = true;

            /*
                当前赋值没有让其他列产生明显矛盾，
                才继续搜索。
            */
            if(check() && dfs(pos, carry, stage + 1))
                return true;

            val[ch] = -1;
            used[d] = false;
        }

        return false;
    }

    /*
        两个加数的值都已经确定。

        结果数字和下一位进位可以直接算出来。
    */
    int sum = val[x] + val[y] + carry;

    int result = sum % n;
    int nextCarry = sum / n;

    /*
        最高位不能再产生进位。
    */
    if(pos == n - 1 && nextCarry != 0)
        return false;

    /*
        结果字母已经有值，检查是否相等。
    */
    if(val[z] != -1)
    {
        if(val[z] != result)
            return false;

        return dfs(pos + 1, nextCarry, 0);
    }

    /*
        结果字母没有值，但算出的数字已经被其他字母使用。
    */
    if(used[result])
        return false;

    /*
        结果字母的值是被当前列强制确定的。
    */
    val[z] = result;
    used[result] = true;

    if(check() && dfs(pos + 1, nextCarry, 0))
        return true;

    val[z] = -1;
    used[result] = false;

    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    cin >> s[0] >> s[1] >> s[2];

    /*
        反转字符串，让第 0 位成为个位，
        方便从低位向高位搜索。
    */
    reverse(s[0].begin(), s[0].end());
    reverse(s[1].begin(), s[1].end());
    reverse(s[2].begin(), s[2].end());

    memset(val, -1, sizeof val);

    dfs(0, 0, 0);

    for(int i = 0; i < n; i ++)
        cout <<val[i] <<" \n"[i == n - 1];
    return 0;
}