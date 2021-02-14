#include <bits/stdc++.h>

using namespace std;

int main(){

	long long int n,m1,m2;

	long long int max = ((long long int) 1)<<62;

	while(true){
		cin>>n;
		if(n==0)
			break;

		m1 = 1;
		m2 = max;
		while(!(m2 & n))
			m2 = m2>>1;
		while(!(m1 & n))
			m1 = m1<<1;

		bool ans = true;
		while(m1<=max && m2>=1 && m1 <= m2){
			bool b1 = (m1 & n), b2 = (m2 & n);
			if(b1 != b2){
				ans=false;
				break;
			}
			m2 = m2>>1;
			m1 = m1<<1;
		}

		if(ans)
			cout<<"SI"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
