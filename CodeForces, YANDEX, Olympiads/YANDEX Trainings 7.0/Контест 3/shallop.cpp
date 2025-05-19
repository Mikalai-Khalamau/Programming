#include <bits/stdc++.h>
using namespace std;
const int N=1000;
const int BITS=64;

vector<bitset<N+1>> xy(N+1);
vector<bitset<N+1>> yz(N+1);
vector<bitset<N+1>> xz(N+1);

int main()
{
    int N,K;
    cin>>N>>K;

    for(int i=0;i<N;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        xy[x][y]=1;
        yz[y][z]=1;
        xz[x][z]=1;
    }
    for (int y=1;y<=N;y++) {
        for (int z=1;z<=N;z++) {
            if (!yz[y][z]) {
                for (int xb=1;xb<=N;xb+=BITS) {
                    bitset<BITS> block;
                    for (int x=xb;x<min(xb+BITS,N+1);x++) {
                        if (!xy[x][y] && !xz[x][z]) {
                            cout<<"NO\n"<<x<<" "<<y<<" "<<z<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<"YES\n"<<endl;
    return 0;
}