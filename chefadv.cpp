#include<iostream>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    string s;
    while(t--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        if(n==1&&m==1)
        {
            s="Chefirnemo";
        }
        else if(n==1)
        {
            if((m-1)%y==0)
                s="Chefirnemo";
            else
                s="Pofik";
        }
        else if(m==1)
        {
            if((n-1)%x==0)
                s="Chefirnemo";
            else
                s="Pofik";
        }
        else if((n-1)%x==0&&(m-1)%y==0)
        {
            s="Chefirnemo";
        }
        else if((n-2)%x==0&&(m-2)%y==0)
        {
            s="Chefirnemo";
        }
        else
            s="Pofik";
        
        cout<<s<<endl;
    }
}
