#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		lli n,k;
		cin>>n>>k;

		lli r; cin>>r;
		lli sum = r;

		lli ans=0;

		for(int i=0;i<n-1;i++){
			cin>>r;

			lli add = (100ll*r - sum*k + k - 1)/k;
			ans = max(ans,add);

			sum+=r;

		}

		cout<<ans<<endl;

	}

	return 0;
}
