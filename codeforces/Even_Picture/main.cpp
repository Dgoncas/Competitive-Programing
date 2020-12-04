#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin>>n;
	n++;

	cout<<(n)*3+1<<endl;

	int x=0,y=0;
	int c=0;
	for(int i=0;i<n;i++){
		cout<<x<<" "<<y<<endl;
		cout<<x<<" "<<y+1<<endl;
		cout<<x+1<<" "<<y<<endl;
		x++;
		y++;
	}
	cout<<x<<" "<<y<<endl;

	return 0;

}