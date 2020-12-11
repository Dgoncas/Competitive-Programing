#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	int balls[n];

	for(int i=0;i<n;i++)
		cin>>balls[i];

	sort(balls,balls+n);

	int index=0,l=0,r=n-1;
	int ans[n];
	while(l<=r){
		ans[index]=balls[r];
		if(l==r) break;
		index++;r--;
		ans[index]=balls[l];
		index++;l++;
	}

	int cuant=0;
	for(int i=1;i<n-1;i+=2){
		if(ans[i-1]> ans[i] && ans[i+1]>ans[i])
			cuant++;
	}

	cout<<cuant<<endl;
	for(int n:ans)
		cout<<n<<" ";
	cout<<endl;

}