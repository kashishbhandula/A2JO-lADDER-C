
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
    ios_base::sync_with_stdio(false);
    string str;
    cin >> str;
    stack<int> st;

    int n = str.size();
    for (int i = 0; i < n; i++)
    {

        if (str[i] == 'l')
        {
            st.push(i + 1);
        }
        else
        {
            cout << i + 1 << endl;
        }
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    //  cout<<endl;
}