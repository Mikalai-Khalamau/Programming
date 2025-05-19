#include <bits/stdc++.h>
using namespace std;
int main(){
string input;
    cin>>input;
    int n=input.length();

stack<char> operators;
 string postfix="";

    for (int i=0;i<n;i++) {
//переводим строку в постфиксную запись
char c=input[i];

        if (isspace(c)) {
            continue;
        }

        else if (isdigit(c)) {
            while (isdigit(c)) {
                postfix += c;
                i++;
                if (i < input.length()) c = input[i];
                else break;
            }
            postfix += ',';
            i--;

        }

        else if (c=='(') {
            operators.push(c);
        }






    }


  return 0;
  }