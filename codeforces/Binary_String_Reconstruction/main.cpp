#include <bits/stdc++.h>

using namespace std;


string s="";

bool dfs(int c00,int c01,int c11){
	
	if(c00==0 && c01==0 && c11==0) return true;
	else if(c00<0 || c01<0 || c11<0) return false;

	char last=s[s.length()-1];
	if(s.length()==0){
		s="00";
		if(dfs(c00-1,c01,c11)){return true;}
		s="01";
		if(dfs(c00,c01-1,c11)){return true;}
		s="10";
		if(dfs(c00,c01-1,c11)){return true;}
		s="11";
		if(dfs(c00,c01,c11-1)){return true;}
		s="";
	}else{
		if(last=='0'){
			s+="0";
			if(dfs(c00-1,c01,c11)){return true;}
			s=s.substr(0,s.length()-1);
			s+="1";
			if(dfs(c00,c01-1,c11)){return true;}
			s=s.substr(0,s.length()-1);
		}else{
			s+="0";
			if(dfs(c00,c01-1,c11)){return true;}
			s=s.substr(0,s.length()-1);
			s+="1";
			if(dfs(c00,c01,c11-1)){return true;}
			s=s.substr(0,s.length()-1);
		}
	}

	return false;

}

int main(){

	int t;
	cin>>t;

	while(t--){
		s="";
		int n1,n2,n3;
		cin>>n1>>n2>>n3;
		if(dfs(n1,n2,n3)) cout<<s<<endl;
		else cout<<"NOPE"<<endl;
	}

	return 0;

}