#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	int c = 0;
	while(t--){
		string s;
		cin>>s;
		c = 0;
		for(int i=0;i<s.length();++i){
			if(s[i] >= '0' && s[i] <= '9'){
				c += s[i]-'0';
			}
		}
		cout<<c<<endl;
	}
	return 0;
}