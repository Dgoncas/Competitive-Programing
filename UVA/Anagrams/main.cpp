#include <bits/stdc++.h>

using namespace std;

int main(){

	vector<tuple<string,string,int>> words;
	string word;
	string ordered_word;

	vector<string> ans;

	int index=0;
	while(true){
		cin>>word;
		ordered_word = word;
		for_each(ordered_word.begin(),ordered_word.end(),[](char &c){c = tolower(c);});
		sort(ordered_word.begin(),ordered_word.end());
		if(word=="#") break;
		words.push_back({ordered_word,word,index});
		index++;
	}

	sort(words.begin(),words.end());

	string before = "",after = "";
	for(int i=0;i<words.size()-1;i++){
		if(get<0>(words[i])!=before && get<0>(words[i])!=get<0>(words[i+1])){
			ans.push_back(get<1>(words[i]));
		}
		before = get<0>(words[i]);
	}

	if(get<1>(words[words.size()-1])!= get<1>(words[words.size()-2])) ans.push_back(get<1>(words[words.size()-1]));

	sort(ans.begin(),ans.end());

	for(auto c : ans)
		cout<<c<<endl;
}
