#include <bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<b;++i)
#define fr(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
int MAX_SIZE=2001;

struct cost{
	int id;
	int weight;
};

struct node{
	int id;
	bool visited;
	cost table_entry[MAX_SIZE];
};
node g[MAX_SIZE];

bool cmp(cost a, cost b ){
	return a.weight < b.weight;
}

int main(){
	int n;
	cin>>n;
	int temp_cost;
	f(i,0,n){
		g[i].id=i;
		g[i].visited=false;
		f(j,0,n){
			cin>>temp_cost;
			g[i].table_entry[j].weight=temp_cost;
			g[i].table_entry[j].id=j;
		}
		sort(g[i].table_entry,g[i].table_entry+n,cmp);
	}
	DFS();
	return 0;
}