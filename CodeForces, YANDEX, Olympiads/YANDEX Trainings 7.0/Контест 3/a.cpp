#include <bits/stdc++.h>
using namespace std;
int main()
    {
  long long int n;
  cin>>n;
  long long int answer=0;
  while(n!=0){
    if(n%2!=0){
      answer++;
    }
    n=n/2;
    }

cout<<answer<<endl;
  return 0;
  }
