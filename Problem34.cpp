#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    cin >> len;

    vector<int> square(len);
    for (int i = 0; i < len; i++)
        cin >> square[i];

    vector<int> leftPrefix(len), rightPrefix(len);
    for (int i = 0; i < len; i++)
    {
        leftPrefix[i] += square[i];
        if (i > 0)
            leftPrefix[i] += leftPrefix[i - 1];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        rightPrefix[i] += square[i];
        if (i + 1 < len)
            rightPrefix[i] += rightPrefix[i + 1];
    }

    int ans = 0;

    for (int i = 0; i < len - 1; i++)
    {
        if (leftPrefix[i] == rightPrefix[i + 1])
            ans++;
    }
    cout << ans << endl;

    return 0;
}