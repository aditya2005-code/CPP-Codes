#include<iostream>
#include<set>
using namespace std;

int main(){
	
	set<int> s;
	
	s.insert(3);
	s.insert(5);
	s.insert(7);
	
	for(int i:s){
		cout<<i<<"";
	}
	cout<<endl;
	
	s.erase(5);
	
	if(s.find(5)!=s.end()){    
		cout<<"Element found"<<endl;
	}
	else{
		cout<<"Element not ffound"<<endl;
	}
	cout<<"Size of the set is:"<<s.size();
	return 0;
	
}