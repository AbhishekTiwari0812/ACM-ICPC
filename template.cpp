#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>
#define s(a) set<a>
#define m(a,b) map<a,b>
#define MOD (int)(1e9+7)

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;

//unchecked
ll Pow(ll a,ll x){ll b=Pow(a,x/2);if( x==0 )return 1;if(x%2==1)return (((b*b)%MOD)*a)%MOD;else return (b*b)%MOD;}
ll GCD(ll a,ll b){}
//nCr
ll C(ll n,ll r){}

int main(){
	ifstream in;
	in.open("in");
	ofstream out;
	out.open("out");



	in.close();
	out.close();
	return 0;
}
