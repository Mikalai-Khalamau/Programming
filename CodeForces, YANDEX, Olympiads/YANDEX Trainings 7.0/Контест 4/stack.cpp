#include <bits/stdc++.h>
using namespace std;

int main()
{
    string command;
    stack<int> not_my_stack;
    while (true)
    {
        std::cin>>command;

        if (command=="push") {
            int n;
            std::cin>>n;
            not_my_stack.push(n);
            std::cout<<"ok\n";
        }

        if (command=="pop") {
            if (not_my_stack.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_stack.top()<<"\n";
                not_my_stack.pop();
            }
        }

        if (command=="back") {
            if (not_my_stack.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_stack.top()<<"\n";
            }
        }

        if (command=="size") {
            std::cout<<not_my_stack.size()<<std::endl;
        }

        if (command=="clear") {
            while (!not_my_stack.empty()) {
                not_my_stack.pop();
            }
            std::cout<<"ok\n";
        }

        if (command=="exit") {
            std::cout<<"bye"<<endl;
            return 0;
        }
    }


}