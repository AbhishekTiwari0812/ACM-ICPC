#include <bits/stdc++.h>
#define f(i,a,b) for(int i=(a),__=(b); i < __; ++i)
#define fr(i,b,a) for(int i=(b), __ = ( a ); i >= __; --i)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef set<string> ss;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int r,g,b,w;
	string s;
	while(t--){
		cin>>s;
		r=g=b=w=0;
		f(i,0,s.length()){
			switch(s[i]){
				case 'R':
					r++;
				break;
				case 'G':
					g++;
				break;
				case 'B':
					b++;
				break;
				case 'W':
					w++;
				break;
			}
		}
		if(r%2==0 && g%2==0 && b%2==0 &&w%2==0 )
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}