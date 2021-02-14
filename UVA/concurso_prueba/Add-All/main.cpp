#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){

	int n,r;
	priority_queue<lli> list;

	while(true){
		cin>>n;
		if(n==0)
			break;

		for(int i=0;i<n;i++){
			cin>>r;
			list.push(-r);
		}

		lli res = 0;
		
		while(list.size()!=1){

			lli n1 = -list.top(); list.pop();
			lli n2 = -list.top(); list.pop();

			lli sum = n1+n2;

			res += sum;
			list.push(-sum);

		}
		list.pop();

		cout<<res<<endl;

	}

	return 0;
}
