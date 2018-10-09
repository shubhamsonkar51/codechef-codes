#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MAXN 50001

int main(){
    lli p,s;
    vector< pair <lli,lli> > ans;
    cin>>p>>s;
    for(lli c=0;c<p;c++){
        lli sc[s],ns[s];
        vector< pair <lli,lli> > vec;
        for(lli i=0;i<s;i++){
            cin>>sc[i];
        }
        for(lli i=0;i<s;i++){
            cin>>ns[i];
        }
        for(lli i=0;i<s;i++)
        	vec.push_back(make_pair(sc[i], ns[i] ));
        sort(vec.begin(),vec.end());
        //for(int i=0;i<s;i++)
        //	cout<<vec[i].second<<" ";
        //cout<<endl;
        lli n=0;
        for(lli i=0;i<s-1;i++){
            if(vec[i].second>vec[i+1].second)
                n++;
            
        }
        //cout<<n<<endl;
        ans.push_back(make_pair(n,c+1));
    }
    sort(ans.begin(), ans.end());
    for(lli c=0;c<p;c++){
        cout<<ans[c].second<<endl;
    }
}  
