#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> s(n);
for (int i = 0; i < n; i++) {
    cin>>s[i];
}

    if (n==1)
    {

        cout<< 0;
    }
    else {
      int max=-1;

        for (int i=0;i<n;i++)
        {
            //для палиндромов четной длины
            int l=i-1;
            int r=i;

int now=0;

            while (l>=0 && r<n && s[l]==s[r])
            {
                now+=2;
                r++;
                l--;

            }
            if (max<now) {
                max=now;
            }
        }
        for (int i=0;i<n;i++)
        {
            //для палиндромов нечетной длины
            int l=i-1;
            int r=i+1;
            int now=1;

            while (l>=0 && r<n && s[l]==s[r])
            {
                now+=2;
                r++;
                l--;

            }
            if (max<now) {
                max=now;
            }
        }
if (max==1) {
    cout<<0;
}
        else {
            cout<<max;
        }

    }

}