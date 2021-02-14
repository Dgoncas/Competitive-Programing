#include <bits/stdc++.h>
#define lli long long int


using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		int a,b;
		cin>>a>>b;

		if(b<a)
			b =(int) (ceil(a/(b+0.0))*b);

		int ans = b/a;

		if(b%a!=0){
			ans++;
		}

		cout<<ans<<endl;

	}

	return 0;
}
