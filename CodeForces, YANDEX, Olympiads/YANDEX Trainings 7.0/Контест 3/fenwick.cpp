#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
long long Tree[MAX];
int n, k;
long long i, j, l, r, x;
char cm;

long long sum(long long i)
{
    long long result = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        result += Tree[i];
    return result;
}

void in(long long i, long long wq)
{
    for (; i <= n; i = (i | (i+1)))
        Tree[i] += wq;
}

int main ()
{
    cin>>n>>k;
    for(j = 0; j < k; j++)
    {
        cin>>cm;
        if (cm == 'A')
        {
            cin>>i>>x;
            x = x - sum(i) + sum(i-1);
            in(i,x);
        }
        else
        {
           cin >> l>> r;
            cout << sum(r) - sum(l-1);
        }
    }
    return 0;
}

