#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    vector<long long> keys(n+1);
    for(long long i=1;i<=n;i++)
    {

        cin>>keys[i];

    }

    vector<bool> connected(n+1,false);
    long long boom=0;
    for (long long i=1;i<=n;i++)
    {
        if (!connected[i]) {
            unordered_set<int> path;

            long long curr=i;
            while (!connected[curr])
            {
                path.insert(curr);
                connected[curr]=true;
                curr=keys[curr];


                if (path.count(curr))
                {
                    boom++;
                }

            }
        }


    }

    cout<<boom;
    return 0;
}