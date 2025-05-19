#include <bits/stdc++.h>
using namespace std;
int main()
    {
int n;
cin>>n;


pair<int,int> p[n];
  for(int i=0;i<n;i++) {
    int x;
    cin>>x;
    p[i].first=x;
    p[i].second=i;

  }
long long sum=0;
sort (p,p+n);
  vector <int> indexex;
  for (int i=0;i<n;i++) {
    int cur_ind=p[i].second;
    auto it =lower_bound(indexex.begin(),indexex.end(),cur_ind);
    sum+=it-indexex.begin();
    indexex.insert(it,cur_ind);
  }
  cout<<sum<<endl;
  /*


  long long sum=0;

  for(int i=0;i<n;i++) {
    sum+=n-i-1;
    for (int j=i+1;j<n;j++) {
      if (p[j].second>p[i].second || p[j].first==p[i].first) {
        sum--;
      }
    }
  }

cout<<sum;

  // плохое решение за квадрат
  /*
    *vector<int> v(n);
  for(int i=0;i<n;i++)
    {
    cin>>v[i];
    }
  long long sum=0;
  for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < n; j++)
      {
      if (i<j && v[i]<v[j])
        {
        sum++;
        }
      }
      }
cout<<sum<<endl;
*/

  return 0;
  }
