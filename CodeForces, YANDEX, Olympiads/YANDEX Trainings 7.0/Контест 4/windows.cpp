#include <bits/stdc++.h>
using namespace std;
int main() {
int n;
    cin >> n;
cin.ignore();
deque<string> apps;
    int pos_now=0;
    for (int i = 1; i <= n; i++) {

string s;
        getline(cin, s);
        if (s[0]=='A') {
            //считаем табы
            int tabs=(s.length()-3)/4;

            pos_now=(tabs)%apps.size();
            string d=apps[pos_now];
            std::cout<<d<<"\n";
            //удаляет из дека и вставляем в начало
            apps.erase(apps.begin()+pos_now);
            apps.push_front(d);
        }

            else
                {
                string new_app;
                if (s.size()<=4) {
                     new_app=" ";
                }
                else {
                     new_app=s.substr(4);
                }

                apps.push_front(new_app);

cout<<new_app<<"\n";
                }
            }
  return 0;
  }