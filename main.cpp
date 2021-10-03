#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int stare[10], stfin[10], nrstari, nsf, nrlitere, nrtranz, i, initial ;
char litere[10];
int mat[10][10][10], ok=0, k,ntrdfa,nrstdfa,nsfdfa,stfindfa;
map < pair<int, char>, int> delta ;
map <int,int> etichetare;
queue < pair<int,int> > coada;


ifstream f("date.in");

void citire()
{
    int x,y;
    char c;
    f>>nrstari;
  //  cout<<"nr de stari este:"<<nrstari<<endl;

    for ( i = 1; i <= nrstari; i++ )
        {f>>stare[i];
       //  cout<<stare[i]<<" ";}
  //  cout<<endl;


    f>>nrlitere;
   // cout<<"nr de litere este: "<<nrlitere<<endl;
    // cout<<"literele sunt: "<<endl;

    for( i = 1; i <= nrlitere; i++ )
       {
           f>>litere[i];
         //  cout<<litere[i]<<" ";
       }

   // cout<<endl;
    f>>initial;
  //  cout<<"starea initiala este: "<<initial<<endl;
    f>>nsf;
  //  cout<<"starile finale sunt: "<<endl;
    for(i=0;i<nsf;i++)  //in vector retin toate starile finale
        {f>>stfin[i];
      //   cout<<stfin[i]<<" ";}
    // cout<<endl;

    f>>nrtranz;
   // cout<<"nr de tranzitii este: "<<nrtranz<<endl;
   // cout<<"tranzitiile sunt: "<<endl;
    int nr=nrtranz;
    while ( nr!= 0 )
    {
       f>>x>>c>>y;
      // cout<<x<<" "<<c<<" "<<y<<endl;

       mat[x][c][y]=1;


       nr--;
    }
   for(i=1; i<=nrstari; i++)
    for ( int k=1; k<=nrstari; k++)
     for(int j=1; j<=nrlitere; j++)
         if (mat[i][litere[j]][k]==1)
             mat[i][litere[j]][0]++;


f.close();

}


void creare_dfa()
{
    coada.push(initial);
    set <int> viz;
    int front;
    int i = 0;
    while (!coada.empty())
    {
        front = coada.front();
        viz.insert(front);
        for(int j=1; j<=nrlitere; j++)
           {for(int k=1; k<=9; k++)
              if(mat[front][litera[j]][k]==1)
                  {nr=nr*10 + k;
                   for(int p=1; p<=nsf; p++)
                      if(k == stfin[p])
                           ok++
                  }
             if (ok!=0)
               {stfindfa[nsfdfa]=nr;
                 nsfdfa++;}
             delta[front][litera[j]]=nr;
             if(viz.find(nr)==viz.end())
               {coada.push(nr);
                viz.insert(nr);
                i++;}
             }
        coada.pop();
    }
    int a=1;
    set<int> :: iterator itt;

    for(itt=viz.begin();itt!=viz.end();itt++)
    {
       int b=itt;

        etichetare[b]=a;
        a++;
    }
  ntrdfa=a;
  nrstdfa=i;
}

void afisare()
{
  cout<<"nr de stari dfa este: "<<nrstdfa<<endl;
   cout<<"starile sunt: "<<endl;
   for(i=1; i<=nrstdfa; i++)
       cout<<etichetare[i]<<" ";
   cout<<endl;
   cout<<"nr litere e: "<<nrlitere<<endl;
   cout<<"literele sunt: "<<endl;
   for(int w=1; w<=nrlitere; w++)
       cout<<litere[w]<<" ";
   cout<<endl;
   cout<<initial;
   cout<<"nr de stari finale este: "<<nsfdfa;
   cout<<"starile finale sunt: "<<endl;
   for(int r=1; r<=nsfdfa; r++)
        cout<<stfindfa[r]<<" ";
   cout<<endl;
   cout<<"nr tranzitiilor este: "<<ntrdfa<<endl;
   cout<<"tranzitiile sunt: "<<endl;
   map<pair< int,char>int > iterator it;
   for ( it = delta.begin(); it != delta.end(); it++)
   {pair<int,char> key=it->first;
   int value = it->second;
   cout<<etichetare[key.first]<<" "<<key.second<<" "<<key.second<<" "<<etichetare[value];}




}



int main()
{
    citire();
    creare_dfa();
    afisare();

  return 0;
}
