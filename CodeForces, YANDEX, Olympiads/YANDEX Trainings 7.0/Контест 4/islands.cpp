#include <bits/stdc++.h>
using namespace std;
int main(){


  int m;int n;
  cin>>n>>m;
  if (n==1)
    {
    cout<<0<<endl;
    return 0;
    }
    vector<int> islands(n+1,0);

//сделали вектор цветов мостов.изначально все пустые
int current_bridge=0;
int color=1;//текущий цвет
int komponent_svyaz=0;
int painted=0;//число закрашенных островов
      //начинаем проходку по мостам до успеха.успех по условию гарантирован
      while (current_bridge<m)
        {
int from,to;
cin>>from>>to;

current_bridge++;
//игнорируем пустышки
if (from==to)
  {
  continue;
  }

    //два серых острова
     if (islands[to]==0 && islands[from]==0)
      {
islands[to]=color;
islands[from]=color;
color++;
painted+=2;
komponent_svyaz++;
      }
      else if (islands[to]==0)
{
        islands[to]=islands[from];
        painted++;
        }
      else if (islands[from]==0)
      {
          islands[from]=islands[to];
          painted++;
      }
        //моста разноцветные
else if (islands[from]!=islands[to]){
        int from_clr=islands[from];
        int to_clr=islands[to];
        for (int i=1;i<=n;i++)
          {
          if (islands[i]==to_clr)
            {
            islands[i]=from_clr;
            }
          }

      komponent_svyaz--;



        }

if (komponent_svyaz==1 && painted==n)
  {
  cout<<current_bridge<<endl;
  return 0;
  }

        }



  return 0;
  }