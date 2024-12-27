#include<iostream>
#include<map>

using namespace std;

int main(){
	
	map<string,int> m;
	
	m["Apple"]=50;
	m.insert({"Banana",50});
	m.insert({"date",80});
	
	for(auto it:m){
		cout<<it.first<<"->"<<it.second<<endl;
	}
	
	m.erase("Banana");
	
	for(auto i:m){
		cout<<i.first<<"->"<<i.second<<endl;
	}
	
	return 0;
}