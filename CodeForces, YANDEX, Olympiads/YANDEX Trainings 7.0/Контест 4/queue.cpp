#include <bits/stdc++.h>
using namespace std;

int main()
{
    string command;
    queue<int> not_my_queue;
    while (true)
    {
        std::cin>>command;

        if (command=="push") {
            int n;
            std::cin>>n;
            not_my_queue.push(n);
            std::cout<<"ok\n";
        }

        if (command=="pop") {
            if (not_my_queue.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_queue.front()<<"\n";
                not_my_queue.pop();
            }
        }

        if (command=="front") {
            if (not_my_queue.empty()) {
                std::cout<<"error\n";
            }
            else {
                std::cout<<not_my_queue.front()<<"\n";
            }
        }

        if (command=="size") {
            std::cout<<not_my_queue.size()<<std::endl;
        }

        if (command=="clear") {
            while (!not_my_queue.empty()) {
                not_my_queue.pop();
            }
            std::cout<<"ok\n";
        }

        if (command=="exit") {
            std::cout<<"bye"<<endl;
            return 0;
        }
    }


}