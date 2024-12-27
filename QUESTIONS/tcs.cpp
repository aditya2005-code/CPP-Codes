#include<iostream>
#include<vector>
#include<set>
using namespace std;

int findRosterdays(int n, int m ,  vector<pair<int,int>>& friendships, int k)
{
  vector<vector<int>> adj(n);
  
  for(auto& p: friendships){
    adj[p.first].push_back(p.second);
    adj[p.second].push_back(p.first);
  }
  
  vector<int> currentStatus(n,1);
  
  int totalRostervalues=0;
  int days=0;
  
  while( totalRostervalues < k){
    vector<int> nextStatus=currentStatus;
    int dailyRoster=0;
    for(int i=0 ; i<n ; i++){
      int friendsInOffice=0;
      for(int friendId : adj[i]){
        if(currentStatus[friendId] == 1){
          friendsInOffice++;
        }
      }
      if( currentStatus[i] == 1){
        if(friendsInOffice == 3){
          nextStatus[i]=1;
        } else{
          nextStatus[i]=0;
        }
      } else{
        if( friendsInOffice < 3) {
          nextStatus[i] = 1;
        } else{
          nextStatus[i] = 0;
        }
      }
    }
    
    dailyRoster=0;
    for(int i=0 ; i<n ; i++){
      if( nextStatus[i] == 1){
        dailyRoster++;
      }
    }
    
    totalRostervalues += dailyRoster;
    days++;
    currentStatus= nextStatus;
  }
  return days;
}

int main()
{
  int n, m ;
  cin>> n >>m;
  vector<pair<int,int>> friendships(m);
  for(int i=0 ; i<m ; i++){
    cin>>friendships[i].first>> friendships[i].second;
    cout<<endl;
  }
  
  int k;
  cin>>k;
  
  int result= findRosterdays(n , m , friendships , k);
  cout<< result << endl;
  
  return 0;
}
