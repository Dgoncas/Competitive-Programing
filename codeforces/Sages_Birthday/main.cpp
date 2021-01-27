#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;

	int balls[n];
	int ans[n];

	for(int i=0;i<n;i++)
		cin>>balls[i];

	sort(balls,balls+n);
	reverse(balls,balls+n);

	int expensive = 0,cheap = ceil(n/2);

	int index=0;
	int valid=0;
	while(index<n){
		if(expensive<n){
			ans[index] = balls[expensive];
			index++;
		}
		if(cheap<n){
			ans[index] = balls[cheap];
			index++;
			valid++;
			if(index==n) valid--;
		}
		expensive++;
		cheap++;
	}

	cout<<valid<<endl;
	for(auto a:ans)
		cout<<a<<" ";
	cout<<endl;

}