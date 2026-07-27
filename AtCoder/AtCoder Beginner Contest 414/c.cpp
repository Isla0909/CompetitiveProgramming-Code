#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long pow10(int n) 
{
    if (n < 0) return 0;
    long long res = 1;
    for (int i = 0; i < n; i++)
        res *= 10;
    return res;
}

bool isPalindromeInBase(long long num, int base) {
    string s = "";
    long long x = num;
    while (x) {
        int r = x % base;
        x = x / base;
        s += ('0' + r);
    }
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i])
            return false;
    }
    return true;
}

int main() {
    int A;
    long long N;
    cin >> A >> N;

    long long totalSum = 0;

    for (long long i = 1; i <= 9; i++) {
        if (i > N) 
            break;
        if (isPalindromeInBase(i, A)) {
            totalSum += i;
        }
    }

    if (N < 10) {
        cout << totalSum << endl;
        return 0;
    }

    string N_str = to_string(N);
    int max_len = N_str.size();

    for (int len = 2; len <= max_len; len++) 
    {
        long long start, end;
        if (len % 2 == 0) 
        {
            int half = len / 2;
            start = pow10(half - 1);
            end = pow10(half) - 1;
        } 
        else 
        {
            int half = (len - 1) / 2;
            start = pow10(half);
            end = pow10(half + 1) - 1;
        }

        for (long long left = start; left <= end; left++) {
            string s_left = to_string(left);
            string s_right;
            if (len % 2 == 0) {
                s_right = s_left;
                reverse(s_right.begin(), s_right.end());
            } else {
                s_right = s_left.substr(0, s_left.size() - 1);
                reverse(s_right.begin(), s_right.end());
            }
            string s_total = s_left + s_right;
            long long num = stoll(s_total);
            if (num > N) 
                break;
            if (isPalindromeInBase(num, A)) {
                totalSum += num;
            }
        }
    }

    cout << totalSum << endl;

    return 0;
}