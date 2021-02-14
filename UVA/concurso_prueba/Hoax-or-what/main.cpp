#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){

	int days = 0;

	while(true){
		cin>>days;
		if(days == 0)
			break;

		multiset<int> values;
		lli ans = 0;

		while(days--){
			int bills = 0;
			cin>>bills;

			int r;
			while(bills--){
				cin>>r;
				values.insert(r);
			}

			if(values.size()!=0){
				ans += *(prev(values.end())) - *(values.begin());
				values.erase(values.begin());
				values.erase(prev(values.end()));
			}

		}

		cout<<ans<<endl;

	}

	return 0;
}
