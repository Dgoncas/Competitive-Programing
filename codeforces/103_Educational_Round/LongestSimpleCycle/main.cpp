#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){

	int t,n;
	cin>>t;

	while(t--){

		cin>>n;
		int l[n],a[n],b[n];

		for(int i=0;i<n;i++)
			cin>>l[i];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];

		lli sum = abs((lli) b[1]-a[1]);
		lli ans = 0;

		for(int i=1;i<n-1;i++){

			sum += 2;
			ans = max(ans,sum + l[i] - 1);

			if(a[i+1] != b[i+1]){
				sum += abs((lli) min(a[i+1],b[i+1]) - 1);
				sum += abs((lli) max(a[i+1],b[i+1]) - l[i]);
			}else{
				sum = 0;
			}
			
		}

		sum += 2;
		sum += l[n-1]-1;
		ans = max(ans,sum);

		cout<<ans<<endl;

	}

	return 0;
}
