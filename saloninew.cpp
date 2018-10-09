#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        long int motu=0,tomu=0;
        cin>>n>>k;
        vector <int> A(n);
        vector <int> m;
        vector <int> t;
        for (int j=0;j<n;j++){
            cin>>A[j];
            if (j%2==0){
                motu+=A[j];
                m.push_back(A[j]);
            }
            else{
                tomu+=A[j];
                t.push_back(A[j]);
            }
        }
        sort(t.begin(),t.end());
        sort(m.begin(),m.end(),greater <int> ());
        for(int i=1,j=0;i<=k&&j<m.size()&&j<t.size();i++){
			if(tomu>motu)
				break;
			else{
				motu=motu-m[j]+t[j];
				tomu=tomu-t[j]+m[j];
				j++;
			}
		}
		if(tomu>motu)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
    }
    return 0;
}
 
