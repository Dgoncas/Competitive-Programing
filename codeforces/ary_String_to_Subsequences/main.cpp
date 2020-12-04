#include <bits/stdc++.h>

using namespace std;

int main(){


	int t;
	cin>>t;

	while(t--){

		int num=0;
		queue<int> ones;
		queue<int> ceros;
		queue<int> ans;

		int n;
		char c;
		cin>>n;


		while(n--){
			cin>>c;
			if(c=='0'){
				if(ceros.size()==0){
					num++;
					ones.push(num);
					ans.push(num);
				}else{
					ones.push(ceros.front());
					ans.push(ceros.front());
					ceros.pop();
				}
			}else{
				if(ones.size()==0){
					num++;
					ceros.push(num);
					ans.push(num);
				}else{
					ceros.push(ones.front());
					ans.push(ones.front());
					ones.pop();
				}
			}
		}

		cout<<num<<endl;

		while(!ans.empty()){
			cout<<ans.front()<<" ";
			ans.pop();
		} 
		cout<<endl;

	}
	return 0;

}