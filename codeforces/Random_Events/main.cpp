#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
	int t,n,m,r;
	float p;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int arr[n];
		int arr2[n];
		pair<int,float> exp[m];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			arr2[i]=arr[i];
		}

		sort(arr2,arr2+n);

		int last_unsorted=0;
		for(int i=0;i<n;i++){
			if(arr[i]!=arr2[i])
				last_unsorted=i+1;
		}

		for(int i=0;i<m;i++){
			cin>>r>>p;
			exp[i]={r,p};
		}

		reverse(exp,exp+m);

		if(last_unsorted==0){
			cout<<1.0<<endl;
			continue;	
		}

		long double ans=0.0;
		for(auto e:exp){
			if(e.first>=last_unsorted)
				ans=e.second+(1-e.second)*ans;
		}

		cout<<setprecision(6);
		cout<<ans<<endl;
	}
}