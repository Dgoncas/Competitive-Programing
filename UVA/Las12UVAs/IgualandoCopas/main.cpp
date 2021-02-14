#include <bits/stdc++.h>
#define lli long long int


using namespace std;

int main(){

	lli n;
	while(true){
		cin>>n;
		if(n == 0)
			break;

		lli sum = 0, m = 0, r;
		for(lli i = 0; i<n ; i++){
			cin>>r;
			sum += r;
			m = max(m,r);
		}

		cout<< n*m - sum<<endl;

	}

	return 0;
}
