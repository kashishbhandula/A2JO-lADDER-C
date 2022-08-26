#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<long long int> Fact(1000002);
void Build()
{
    Fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        Fact[i] = i * Fact[i - 1];
        Fact[i] %= mod;
    }
}
long long int Pow(long long int base, long long int n)
{
    if (n == 0)
        return 1;

    long long int value = Pow(base, n / 2) % mod;
    value = ((value * value) % mod);
    if (n & 1)
    {
        value = (value * base) % mod;
    }

    return value;
}
long long int Inverse(long long int n)
{
    return Pow(n, mod - 2);
}
bool check(long long int n, long long int a, long long int b)
{
    while (n)
    {
        long long int rem = n % 10;
        if (rem != a && rem != b)
            return false;
        n /= 10;
    }
    return true;
}
long long int nCr(long long int n, long long int r)
{
    long long int num = Fact[n];
    long long int den = Fact[r] * Fact[n - r];
    den%=mod;
    num = (num * Inverse(den)) % mod;
    return num;
}
int main()
{
    long long int a, b, n;
    cin >> a >> b >> n;
    Build();
    long long int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        long long int val1 = i * a;
        long long int val2 = (n - i) * b;
        val1 += val2;
        if (check(val1, a, b))
        {
            ans += nCr(n, i);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}