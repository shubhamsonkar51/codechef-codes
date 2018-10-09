#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define lli long long int
#define MAXN 50001
class a{
	private:
		static int x;
	public:
		int* gett(){
			return &x;
		}
};
int a::x=0;
int main(){
	a aa;
	cout<<aa.gett();
}  
