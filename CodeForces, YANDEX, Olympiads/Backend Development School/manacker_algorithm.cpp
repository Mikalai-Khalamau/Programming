#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
            int n=s.length();
            if (n==1)
            {
                string w="";
                w+=s[0];
                cout<< w;
            }
            else {
                string max="";

                for (int i=0;i<n;i++)
                {
                    //для палиндромов четной длины
                    int l=i-1;
                    int r=i;
                    string str_now="";


                    while (l>=0 && r<n && s[l]==s[r])
                    {
                        str_now=s[l]+str_now+s[r];
                        r++;
                        l--;

                    }
                    if (max.length()<str_now.length()) {
                        max=str_now;
                    }
                }
                for (int i=0;i<n;i++)
                {
                    //для палиндромов нечетной длины
                    int l=i-1;
                    int r=i+1;
                    string str_now="";
                    str_now+=s[i];

                    while (l>=0 && r<n && s[l]==s[r])
                    {
                        str_now=s[l]+str_now+s[r];
                        r++;
                        l--;

                    }
                    if (max.length()<str_now.length()) {
                        max=str_now;
                    }
                }

                cout<< max;
            }

    return 0;
}