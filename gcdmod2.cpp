#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define k 1000000007
vector <pair <lli, lli> > vect;
vector <pair <lli, lli> > v;
vector <pair <lli, lli> > com;
void factorize(lli n)
{
    int count = 0;
   while (!(n % 2)) {
        n >>= 1;
        count++;
    }
    
    if(count)
        vect.push_back(make_pair(2,count));
    
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            vect.push_back((make_pair(i,count)));
        
    }
    if (n > 2)
        vect.push_back((make_pair(n,1)));
}
void factorize2(lli n)
{
    int count = 1;
    while (!(n % 2)) {
        n >>= 1;
        count++;
    }
    
    if (count)
        v.push_back(make_pair(2,count));
    
    for (long long i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while (n % i == 0) {
            count++;
            n = n / i;
        }
        if (count)
            v.push_back((make_pair(i,count)));
        
    }
    if (n > 2)
        v.push_back((make_pair(n,1)));
}
void powr(lli n){
    if(v[0].first==2)
        --v[0].second;
    for(int i=0;i<v.size();i++)
        v[i].second*=n;
    if(v[0].first==2)
        ++v[0].second;
}
lli power(lli x, lli y, lli p)
    {
        lli res = 1;    
        x = x%p; 
     
        while (y>0)
        {
            if((y%2)==1)
                res =(res%p * x%p)%p;
            y = y/2; 
            x = (x%p * x%p)%p; 
        }
        return res%p;
    }
lli min(lli a, lli b){
    if(a<=b)
        return a;
    return b;
}
int main(){
    lli t;
    cin>>t;
    while(t--){
        lli a,b,n;
        cin>>a>>b>>n;
        //cout<<l<<"\n";
        if(a-b==0){
            lli l=((power(a,n,k)%k)+(power(b,n,k)%k))%k;
            cout<<l<<endl;
        }
        else{
            lli l=1;
            //cout<<"fuck4"<<endl;
            factorize((a-b));
            /*for(int i=0;i<vect.size();i++)
            	cout<<vect[i].first<<" "<<vect[i].second<<" ";
            
            cout<<"fuck5"<<endl;*/
            factorize2(b);
           /* for(int i=0;i<v.size();i++)
            	cout<<v[i].first<<" "<<v[i].second<<" ";
            cout<<"fuck6"<<endl;*/
            powr(n);
            /*for(int i=0;i<com.size();i++)
            	cout<<com[i].first<<" "<<com[i].second<<" ";
            cout<<"fuck7"<<endl;*/
            //int x=0;
            //cout<<"fuck1"<<endl;
            for(int i=0;i<vect.size();i++){
                for(int j=0;j<v.size();j++){
                    if(v[j].first==vect[i].first){
                        com.push_back(make_pair(v[j].first,min(v[j].second,vect[i].second)));
                    }
                }
            }
            //cout<<"fuck2"<<endl;
            for(int i=0;i<com.size();i++){
                l=(l%k*power(com[i].first,com[i].second,k)%k)%k;
            }
            //cout<<"fuck3"<<endl;
            cout<<l<<endl;
            v.clear();
            vect.clear();
            com.clear();
        }
            
    }
}  
