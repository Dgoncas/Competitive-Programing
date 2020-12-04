#include <bits/stdc++.h>

using namespace std;

int nums[(int)2e5];
long long reps[(int)2e5];

int main(){

	int n,q;
	cin>>n>>q;

	for(int i=0;i<n;i++){
		cin>>nums[i];
		reps[i]=0;
	}

	sort(nums,nums+n);

	while(q--){
		int a,b;
		cin>>a>>b;
		a--;b--;
		reps[a]++;
		if(b+1<n) reps[b+1]--;

	}


	int sum=0;
	for(int i=0;i<n;i++){
		sum+=reps[i];
		reps[i]=sum;
	}

	sort(reps,reps+n);

	long long res=0;
	for(int i=n-1;i>=0;i--){
		res+=((long long)reps[i])*nums[i];
	}

	cout<<res<<endl;
	return 0;

}