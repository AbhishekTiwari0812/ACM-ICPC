#include <ctime>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <map>
#include <utility>
#include <climits>
#include <cstring>
#include <vector>

#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define repmsi(it,m) for(msi::iterator it=(m).begin();it!=m.end();it++)
#define repmii(it,m) for(mii::iterator it=(m).begin();it!=m.end();it++)
#define repvi(i,v) for( vi::iterator i=(v).begin();i!=(v).end();i++)
//add other definitions here!!!
using namespace std;
typedef vector<int> vi;
typedef set<int> si;
typedef long long int ll;
typedef pair<string,int> psi;
typedef pair<int,int> pii;
typedef map<string,int> msi;
typedef map<int,int> mii;
map<ll,ll> answer;
map<ll,ll>::iterator it;

ll compute(ll n){
    //printf("n=%lld",n);
    if(n==1)
        return 1;
    if(n&1)
        return compute((3*n+1)>>1)+2;
    else return compute(n>>1)+1;
}


int main(){
	ll i,j;
	while(scanf("%lld%lld",&i,&j)!=EOF){
		ll temp1=i;
		ll temp2=j;
		ll temp;
		i=min(temp1,temp2);
		j=temp1+temp2-i;
        ll cycle=0;
        temp=i;
        ll max_cycle=INT_MIN;
        while(temp<=j){
            cycle=compute(temp);
           // cout<<cycle<<endl;
            if(max_cycle < cycle)
                max_cycle=cycle;
            temp++;
        }
        printf("%lld %lld %lld\n",temp1,temp2,max_cycle);
	}
}
