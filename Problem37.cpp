#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<long long int> Prefix(n);
    sort(arr.begin(), arr.end(),greater<long long int>());
    for (long long int i = 0; i < n; i++)
    {
        Prefix[i] = arr[i];
        if(i>0)Prefix[i] += Prefix[i - 1];
    }
    long long int mx = 1, pos = arr[0];
    // for(auto it:Prefix)cout<<it<<" ";
    // cout<<endl;
    for (long long int i = 0; i < n; i++)
    {

        long long int low=1,high=n-i;
        while(low<=high)
        {
            long long int mid=(low+high)>>1;
            long long int val=(mid*arr[i])-Prefix[i+mid-1];
            if(i>0)val+=Prefix[i-1];
            // cout<<arr[i]<<" "<<mid<<" "<<val<<endl;
            if(val<=k)
            {
                //  cout<<mx<<" "<<pos<<endl;
                if(mid>=mx)
                {
                     
                   
                    mx=mid;
                    pos=arr[i];
                    
                }
                low=mid+1;
            }
            else high=mid-1;

        }
    }
    cout << mx << " " << pos << endl;
    return 0;
}