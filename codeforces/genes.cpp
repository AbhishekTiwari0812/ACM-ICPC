#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	ios_base::sync_with_stdio(false);
	int a[(int)1e5+1];
	int b[(int)1e5+1];
	int t;
	bool flag[(int)1e5+2];
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a[i];
			flag[i]=false;
		}
		for(int i=0;i<n;++i){
			cin>>b[i];
		}
		int count = 0;
		for(int i=0;i<n;++i){
			if(!count){
				cout<<(i+1)<<'-';
			}
			if(a[i]!=b[i]){
				if(flag[a[i]]){
					flag[a[i]]=0;
					count--;
				}
				else{
					flag[a[i]]=1;
					count++;
				}

				if(flag[b[i]]){
					flag[b[i]]=0;
					count--;
				}
				else{
					flag[b[i]]=1;
					count++;
				}
			}
			if(!count){
				cout<<(i+1)<<' ';
			}
		}
	}
	return 0;
}
