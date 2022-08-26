#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void solve()
{
      int n, p;
      cin >> n >> p;
      string str;
      cin >> str;
      int pos = -1;

      for (int i = n - 1; i >= 0; i--)
      {
            for (char ch = str[i] + 1; ch < 'a' + p; ch++)
            {
                //  cout<<ch<<endl;
                  if (i > 0 && ch == str[i - 1])
                        continue;
                  if (i > 1 && ch == str[i - 2])
                        continue;
                  str[i] = ch;
                //   cout<<i<<endl;
                  pos = i;

                  break;
            }
            if (pos != -1)
                  break;
      }
      if (pos == -1)
      {
            cout << "NO" << endl;
            return;
      }
      for (int i = pos + 1; i < n; i++)
      {
        //   cout<<pos<<endl;
            for (char ch = 'a'; ch < 'a' + p; ch++)
            {
                // cout<<ch<<endl;
                  if (i > 0 && ch == str[i - 1])
                        continue;
                        // cout<<ch<<endl;
                  if (i > 1 && ch == str[i - 2])
                        continue;
                //   cout<<ch<<endl;
                  str[i] = ch;
                  break;
            }
      }
      cout << str << endl;
}

int main()
{
      ios_base::sync_with_stdio(false);
      // Your code here
      ll test = 1;
      // cout<<(11^8)<<endl;

      // PreCompute();
    //   cin >> test;
      ll i = 1;
      while (i <= test)
      {
            // cout << "test"
            //      << " " << i << endl;

            solve();
            i++;
      }
      return 0;
}