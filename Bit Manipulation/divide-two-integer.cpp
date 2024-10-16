#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;

    bool sign = true; // +ve

    if (dividend >= 0 && divisor < 0) sign = false;
    if (dividend < 0 && divisor >= 0) sign = false;

    long n = abs(dividend), d = abs(divisor);
    long ans = 0;

    while (n >= d) {
        int cnt = 0;
        while (n >= (d << (cnt + 1))) {
            cnt++;
        }
        ans += (1 << cnt);
        n -= (d << cnt);
    }
    if (ans == (1L << 31) && sign) return INT_MAX;
    if (ans == (1L << 31) && !sign) return INT_MIN;

    return sign ? ans : -ans;
}

int main() {
    int dividend = 10;
    int divisor = 3;
    cout << "Result of " << dividend << " / " << divisor << " = " << divide(dividend, divisor) << endl;

    dividend = 7;
    divisor = -3;
    cout << "Result of " << dividend << " / " << divisor << " = " << divide(dividend, divisor) << endl;

    return 0;
}

/*
Output:
Result of 10 / 3 = 3
Result of 7 / -3 = -2
*/
