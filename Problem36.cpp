#include <bits/stdc++.h>
using namespace std;

int main()
{
    int operations;
    cin >> operations;

    vector<int> store, next(100003);
    store.push_back(0);

    double sum = 0;
    while (operations--)
    {
        int num;
        cin >> num;
        if (num == 1)
        {
            int x, value;
            cin >> x >> value;
            next[x - 1] += value;
            sum += (x * value);
        }
        else if (num == 2)
        {
            int value;
            cin >> value;
            sum += value;
            store.push_back(value);
        }
        else
        {
            sum -= store[store.size() - 1];
            sum -= next[store.size() - 1];
            if (store.size() - 2 >= 0)
                next[store.size() - 2] += next[store.size() - 1];
            if (store.size() - 1 >= 0)
                next[store.size() - 1] = 0;
            store.pop_back();
        }
        cout << fixed << setprecision(10) << (sum / store.size()) << endl;
    }

    return 0;
}