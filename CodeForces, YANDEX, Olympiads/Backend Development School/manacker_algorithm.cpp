#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    vector<char> s2(s.size() * 2 + 1, '#');
    //создаем псевдостроку с границами в виде символа '#'
    for(int i = 0; i != s.size(); ++i){
        s2[i*2 + 1] = s[i];
    }

    int p[s2.size()];
    int r, c, index, i_mir;
    int maxLen = 1;
    i_mir = index = r = c = 0;

    for(int i = 1; i != s2.size() - 1; ++i){
        i_mir = 2*c-i;

        // Если мы попадаем в пределы радиуса прошлого результата,
        // то начальное значение текущего радиуса можно взять из зеркального результата
        p[i] = r > i ? min(p[i_mir], r-i) : 0;

        while(i > p[i] && (i + p[i] + 1) < s2.size() && s2[i - p[i] - 1] == s2[i + p[i] + 1])
            ++p[i];

        if(p[i] + i > r){
            c = i;
            r = i + p[i];
        }

        if(maxLen < p[i]){
            maxLen = p[i];
            index = i;
        }
    }

    // Отображаем найденные позиции на оригинальную строку
    cout<< s.substr((index-maxLen)/2, maxLen);
}