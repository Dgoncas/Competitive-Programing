#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	if(n<=2){
		cout<<n<<endl;
		exit(0);
	}

	int sol=2 ,l=2,a1,a2,a3; cin>>a1>>a2;
	n-=2;
	while(n--){
		cin>>a3;
		if(a3==(a1+a2))
			l++;
		else
			l=2;
		sol = max(sol,l);
		a1=a2;
		a2=a3;
	}
	
	cout<<sol<<endl;
	exit(0);

}