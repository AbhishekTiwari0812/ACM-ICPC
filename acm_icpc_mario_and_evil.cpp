#include <climits>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    vector<node *>nbd;
    vector<int> cost;
    bool visited;
    long long temp_cost;
    bool picked;
};
node **G;
long long n;
long long k;
long long COST_CURRENT;
void dfs_visit(node *current){
    for(long long i=0;i<current->nbd.size();i++){
      if(current->nbd[i]->visited!=true){
        current->nbd[i]->temp_cost=current->temp_cost+current->cost[i];
        current->nbd[i]->visited=true;
        dfs_visit(current->nbd[i]);
      }
    }
}
void print_graph(){
  for(long long i=0;i<n;i++)
    cout<<" node#"<<(i+1)<<" cost:"<<G[i]->temp_cost<<endl;
}
node *find_next(node *current){
    current->visited=true;
    current->temp_cost=0;
    dfs_visit(current);
    long long MAX_COST=INT_MIN;
    node *answer;
    for(long long i=0;i<n;i++){
      if(G[i]!=current){
        if(G[i]->temp_cost > MAX_COST && !G[i]->picked){
          MAX_COST=G[i]->temp_cost;
          answer=G[i];
        }
      }
    }
    answer->picked=true;
   // print_graph();
    for(long long i=0;i<n;i++){
      G[i]->visited=false;
      G[i]->temp_cost=-1;
    }
    COST_CURRENT=MAX_COST;
    //cout<<"returning:"<<COST_CURRENT<<endl;
    return answer;
}
int main() {
    long long t;
    cin>>t;
    long long count=1;
    while(t--){
      cin>>n>>k;
      G=new node*[n];
      for(long long i=0;i<n;i++){
          G[i]=new node;
          G[i]->visited=false;
          G[i]->temp_cost;
      }
      long long temp;
      long long cost;
      for(long long i=1;i<n;i++){
          cin>>temp>>cost;
          temp-=1;
          G[i]->nbd.push_back(G[temp]);
          G[i]->cost.push_back(cost);
          G[temp]->nbd.push_back(G[i]);
          G[temp]->cost.push_back(cost);
      }
      long final_cost;
      node *start=G[0];
      G[0]->picked=true;
      COST_CURRENT=0;
      final_cost=0;
      for(long long i=0;i<k;i++){
          start=find_next(start);
          //cout<<"adding::"<<COST_CURRENT<<endl;
          final_cost+=COST_CURRENT;
      }
      start->temp_cost=0;
      start->visited=true;
      dfs_visit(start);
      //cout<<"adding:"<<G[0]->temp_cost<<endl;
      final_cost+=G[0]->temp_cost;
      //cout<<final_cost<<endl;
      cout<<"Case "<<(count++)<<": "<<final_cost<<endl;

    }
    return 0;
}
