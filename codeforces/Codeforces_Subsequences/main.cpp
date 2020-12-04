#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n;
	cin>>n;

	string codeforces="codeforces";

	long long reps[10];

	for(int i=0;i<10;i++)
		reps[i]=0;

	long long mult=0;
	int p=0;
	while(mult<n){
		reps[9-p]++;
		long long tempMult=1;
		for(auto p:reps)
			tempMult*=p;
		mult=tempMult;
		p++;
		p%=10;
	}

	for(int i=0;i<10;i++){
		for(int j=0;j<reps[i];j++){
			cout<<codeforces[i];
		}
	}

	cout<<endl;

	return 0;
}
