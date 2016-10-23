#include <bits/stdc++.h>
#define f(i,a,b) for( int i = ( a ), __ = ( b ); i < __; ++i )
#define fr(i,b,a) for( int i = ( b ), __ = ( a ); i >= __; --i )
#define pb push_back
#define mp make_pair
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef map<int,int> mii;
typedef map<int,string> mis;
typedef map<string,int> msi;
typedef map<ll,ll> mll;
typedef map<ll,string> mls;
typedef map<string,ll> msl;
typedef set<int> si;
typedef set<string> ss;
typedef set<ll> sll;
typedef set<ld> sld;
typedef pair<int,int> ii;

msi dp;
int k;

int solve(string s){
	if(s.length() == 0)
		return 0;
	if( dp.find(s) != dp.end())
		return dp[s];
	int a1 = INT_MAX;
	int a2 = INT_MAX;
	int a[26];
	f(i,0,26)
		a[i] = 0;
	int max_count = INT_MIN;
	int index;
	for(int i=0; i < s.length(); ++i){
		a[s[i]-'a']++;
		if(a[s[i]-'a'] > max_count){
			max_count = a[s[i]-'a'];
			index = i;
		}
	}
	char c = s[index];
	string help = "";
	int count = 0;
	f(i,0,s.length()){
		if(s[i] == c && count < k){
			count++;
		}
		else help += s[i];
	}

	a1 = solve(help);

	help = "";
    int min_diff = INT_MAX;
	f(i,0,26){
		int diff = k - a[i];
		if(a[i] < k && diff < min_diff && a[i] > 0){
			index = i;
			min_diff = diff;
		}
	}
	c = s[index];
	help = "";
	count = 0;
	f(i,0,s.length()){
		if(s[i] == c && count < k){
			count++;
		}
		else help += s[i];
	}
	a1 = min(solve(help),a1);

	help = "";
	count = 0;
	f(i,0,26){
		if(a[i] > 0){
			a[i]--;
			count++;
			if(count == k)
				break;
		}
	}
	f(i,0,26){
		f(j,0,a[i]){
			help += (char)('a' + i);
		}
	}
	a2 = solve(help);
	int min_val = min(a1,a2) + 1;
	dp[s] = min_val;
	return min_val;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		dp.clear();
		string s;
		cin>>s;
		cin>>k;
		cout<<solve(s)<<endl;
	}
	return 0;
}
