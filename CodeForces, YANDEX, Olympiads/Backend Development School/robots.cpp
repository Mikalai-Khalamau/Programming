#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<string,pair<int,int>> m;

  for (int i=0;i<n;i++){
string s1,s2;
int dom1,dom2;
cin>>s1>>dom1>>s2>>dom2;
string adres1=s1+" "+to_string(dom1);
string adress2=s2+" "+to_string(dom2);
    m[adres1].first++;
    m[adress2].second++;
  }

  string start="";
  string end="";
  int count=0;
  for (auto it=m.begin();it!=m.end();it++){
    if (it->second.first!=it->second.second){
      count++;
      if (it->second.first>it->second.second) {
        start=it->first;
      }
      else {
        end=it->first;
      }
    }
  }
if (count==0 || count%2!=0) {
  cout<<-1;
}
  else {
    cout<<start+" "+end;
  }

  return 0;
  }
