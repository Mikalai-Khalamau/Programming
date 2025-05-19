#include <bits/stdc++.h>
using namespace std;
int main()
    {
  int n;
  cin>>n;
 vector<vector<int>> v(n, vector<int>(n));
  for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
      {
      cin>>v[i][j];
      }
      }
  vector<string> ans(n);
for (int i=0;i<n;i++) {
  ans[i]="00000000";
}

for (int i=0;i<n;i++) {
  for (int j=i+1;j<n;j++) {
int c=v[i][j];
    if (c==1) {
      ans[i][7]='1';
      ans[j][7]='1';
    }
    if (c==2) {
      ans[i][6]='1';
      ans[j][6]='1';
    }
    if (c==3) {
      ans[i][7]='1';
      ans[j][7]='1';
      ans[i][6]='1';
      ans[j][6]='1';
    }
    if (c==4) {
      ans[i][5]='1';
      ans[j][5]='1';
    }
    if (c==5) {
      ans[i][5]='1';
      ans[j][5]='1';
      ans[i][7]='1';
      ans[j][7]='1';
    }
    if (c==6) {
      ans[i][5]='1';
      ans[j][5]='1';
      ans[i][6]='1';
      ans[j][6]='1';
    }
    if (c==7) {
      ans[i][5]='1';
      ans[j][5]='1';
      ans[i][6]='1';
      ans[j][6]='1';
      ans[i][7]='1';
      ans[j][7]='1';
    }
    if (c==8) {
      ans[i][4]='1';
      ans[j][4]='1';
    }
    if (c==9) {
      ans[i][4]='1';
      ans[j][4]='1';
      ans[i][7]='1';
      ans[j][7]='1';
    }
  }
}

for (int i=0;i<n;i++) {
  string s=ans[i];
  int w=0;
  for (int j=0;j<s.size();j++) {
    if (s[j]=='1') {
      w+=pow(2,7-j);
    }
  }
  cout<<w<<" ";
}



  return 0;
  }