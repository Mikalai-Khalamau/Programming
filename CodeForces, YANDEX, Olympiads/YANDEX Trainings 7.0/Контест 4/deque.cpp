#include <bits/stdc++.h>
using namespace std;

int main()
{
    string command;
    deque<int> not_my_deque;
    while (true)
    {
        std::cin>>command;

        if (command=="push_front") {
            int n;
            std::cin>>n;
            not_my_deque.push_front(n);
            std::cout<<"ok\n";
        }

        if (command=="push_back") {
            int n;
            std::cin>>n;
            not_my_deque.push_back(n);
            std::cout<<"ok\n";
        }


        if (command=="pop_front") {
            if (not_my_deque.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_deque.front()<<"\n";
                not_my_deque.pop_front();
            }
        }

        if (command=="pop_back") {
            if (not_my_deque.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_deque.back()<<"\n";
                not_my_deque.pop_back();
            }
        }


        if (command=="front") {
            if (not_my_deque.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_deque.front()<<"\n";
            }
        }
        if (command=="back") {
            if (not_my_deque.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_deque.back()<<"\n";
            }
        }

        if (command=="size") {
            std::cout<<not_my_deque.size()<<std::endl;
        }

        if (command=="clear") {
            while (!not_my_deque.empty()) {
                not_my_deque.pop_back();
            }
            std::cout<<"ok\n";
        }

        if (command=="exit") {
            std::cout<<"bye"<<endl;
            return 0;
        }
    }


}
