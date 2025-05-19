#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    getline(cin, input);

    stack<char> operators;

    if (input[0]=='-' ) {
        input="0"+input;
    }
    string correct="";
    correct.reserve(input.size());
for (long long i = 0; i < input.length(); i++) {
    if (input[i]!=' ') {
        correct+=input[i];
    }
}

    input=correct;
    correct="";
for (long long i=0; i < input.length(); i++) {
    if (input[i]=='+' && (i==0 || input[i-1]=='(')) {
        continue;
    }
    else if (input[i]=='-') {
        if (i==0 || input[i-1]=='(') {
            correct+="0-";
            continue;
        }
        if (i+1<input.length() && input[i+1]=='-') {
            correct+="+";
            i++;
            continue;
        }
    }
    correct+=input[i];
}
    input=correct;
    if (input.size()==0) {
        cout<<0;
        return 0;
    }
    else {
        string postfix;
        postfix.reserve(input.size()*2);
        for (long long i = 0; i < input.length(); i++) {
            char c = input[i];
if (i<input.length()-1) {
    if  ((c=='+') &&(input[i+1]=='-')) {
        continue;
    }
}


            if (isdigit(c)) {
                while (isdigit(c)) {
                    postfix += c;
                    i++;
                    if (i < input.length()) c = input[i];
                    else break;
                }
                postfix += ',';
                i--;
            } else if (c == '(') {
                operators.push(c);
            } else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    postfix += ',';
                    operators.pop();
                }
                if (!operators.empty()) operators.pop();
            }

            else if (c == '+' || c == '-') {
                while (!operators.empty() && (operators.top() == '+' || operators.top() == '-')) {
                    postfix += operators.top();
                    postfix += ',';
                    operators.pop();
                }
                operators.push(c);
            }
        }

        while (!operators.empty()) {
            postfix += operators.top();
            postfix += ',';
            operators.pop();
        }

        stack<long long> st;
        long long number=0;
        bool z=false;
        for (char c: postfix) {
            if (isdigit(c)) {
                number=number*10+(c-'0');
                z=true;
            }
            else if (c==',') {
                if (z) {
                    st.push(number);
                    number=0;
                    z=false;
                }
            }
            else {
                long long temp=st.top();
                st.pop();
                long long temp1=st.top();
                st.pop();
                if (c=='+') {
                    long long h=temp1+temp;
                    st.push(h);
                }
                else if (c=='-') {
                    long long h=temp1-temp;
                    st.push(h);
                }
            }
        }
        cout << st.top() << "\n";
    }
    return 0;
}