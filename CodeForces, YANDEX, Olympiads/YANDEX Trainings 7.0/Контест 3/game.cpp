#include <bits/stdc++.h>
using namespace std;
int main()
    {
  int n;
  cin>>n;

  string s="";
  while (n>0)
    {
    s+=to_string(n%2);
n=n/2;
}
reverse(s.begin(),s.end());

    int max=0;
    int l=s.length();
for(int i=0;i<l;i++) {
    int w=0;
    for (int j=0;j<s.size();j++) {
        if (s[j]=='1') {
            w+=pow(2,s.size()-1-j);
        }
    }
    max=std::max(max,w);
    string h="";
     h+=s[l-1];
    for (int y=0;y<l-1;y++) {
        h+=s[y];
    }
    s=h;

}
cout<<max;
  return 0;
  }