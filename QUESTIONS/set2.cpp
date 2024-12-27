#include<iostream>
#include<set>
using namespace std;

int main(){
	
	string name="Aditya Pratap Singh";
	set<char> my_name(name.begin(),name.end());
	
	for(auto i:my_name){
		cout<<i<<endl;
	}
	
	
	
	
	
	return 0;
}