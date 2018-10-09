#include <bits/stdc++.h>
#define lli long long int
using namespace std;
 
void SieveOfEratosthenes(lli n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (lli p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (lli i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    lli n = 2080175;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    cout<<"done";
    return 0;
}

