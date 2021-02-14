#include <bits/stdc++.h>

using namespace std;

int main(){

	int a,b,n,t;
	cin>>n;

	while(n--){
		cin>>a>>b;
		t = a + b;
		a = a - t/2;
		t = a + b;
		cout<<((((a+0.0)/t)*100))<<endl;
	}
	return 0;
}
