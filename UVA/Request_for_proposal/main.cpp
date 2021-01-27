#include <bits/stdc++.h>

using namespace std;


string readline(){
	string res="";
	char *c;
	cin.read(c,1);
	while(c[0]!='\n'){
		res+=c[0];
		cin.read(c,1);
	}
	return res;
}

int main(){
	int n,p;
	int t=1;

	while(cin>>n){
		cin>>p;

		map<string,bool> requierements;
		vector<tuple<int,double,string>> proposals;
		string r;
		while(n--){
			r=readline();
			requierements[r] = true;
			cout<<r<<endl;
		}

		string name;
		double price;
		int pr;
		while(p--){
			int pr_count=0;
			cin>>name>>price>>pr;
			string prs;
			cout<<name<<" "<<price<<" "<<pr<<endl;
			while(pr--){
				prs=readline();
				pr_count+=requierements[prs];
			}
		
			proposals.push_back({pr_count,price,name});
		}

		sort(proposals.begin(),proposals.end());

		int prf = get<0>(proposals[proposals.size()-1]);
		tuple<int,double,string> ans;
		for(int i=proposals.size()-1;i>=0;i--){
			if(get<0>(proposals[i])!=prf)
				break;
			ans = proposals[i];
		}

		cout<<"RFP #"<<t<<endl;
		cout<<get<2>(ans)<<endl;
		cout<<endl;
		t++;

	}

}
