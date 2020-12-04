#include <bits/stdc++.h>

using namespace std;
string s;

int chose(char c, int a , int b){

	int c1=0;
	int ct=0;

	if(a==b){
		if(s[a]==c) return 0;
		return 1;	
	}
	
	for(int i=a;i<=b;i++){
			if(s[i]==c){
			ct++;
			if(i<=((a+b)/2)){
				c1++;
			}
		}
	}

	int tc=(b-a)/2+1;
	return min(tc-c1 + chose(c+1,(a+b)/2+1,b),tc-(ct-c1) + chose(c+1,a,(a+b)/2));

	return 0;

}

int main(){

	int t;
	cin>>t;

	while(t--){
		int l;
		cin>>l>>s;
		cout<<chose('a',0,s.length()-1)<<endl;
	}

	return 0;
}