#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,a,b,c;
	cin>>n;

	while(n--){

		cin>>a>>b>>c;

		long long horas = b*c;

		if(horas>a)
			cout<<"HORAS"<<endl;
		else if(horas<a)
			cout<<"ENCENDIDOS"<<endl;
		else
			cout<<"AMBAS"<<endl;

	}

}
