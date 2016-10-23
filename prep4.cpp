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

ll dp[105][905];
int a[110];
ll sum;
int size;

int knapsack(int i,int w){
	//cout<<"I:"<<i<<" w:"<<w<<endl;
	if(w==0)
		return 0;
    else if(w-a[i] == 0)
        return 1;
	if(w < 0 )
		return INT_MAX;
	else if( i == size )
		return INT_MAX;
	else{
	    int x= INT_MAX;
        int y = INT_MAX;
        if(i+1  <  size){
            if(dp[i+1][w]!=-1){
                x = dp[i+1][w];
            }
            else{
                x = knapsack(i+1,w);
                dp[i+1][w] = x;
            }
            if(w-a[i] >= 0){
                if(dp[i+1][w-a[i]]!=-1){
                    y = dp[i+1][w-a[i]]+1;
                }
                else{
                    y = knapsack(i+1, w - a[i] )+1;
                    dp[i+1][w-a[i]] = y - 1 ;
                }
            }

        }
        if(abs(size/2-x)  < abs(size/2 - y) )
            return x;
        else return y;
	}
}

void solve(){
	int ans=0;
	int min_ans=INT_MAX;
	int i=0;
	int w;
	while(true){
        if((sum + i*11 )%2 ==  1){
        	i++;
			continue;
        }
        else
        	w = (sum + i*11)/2;
        i++;
        //cout<<"SUM:"<<sum<<" w:"<<w<<endl;
        if(w>sum)
            break;
		ans = knapsack(0,w);
        ////cout<<ans<<endl;
		if(abs(size/2 - ans )  < abs(size/2-min_ans)){
			min_ans=ans;
		}

	}
	ans =  min_ans;
	//cout<<"FINAL:"<<ans<<endl;
    int other = size - ans;
    //cout<<"OTHER:"<<other<<endl;
    int zeros;
    if(abs(ans) > 10000000){
    	cout<<-1<<endl;
    	return;
    }
    if(abs(ans-other) <= 1)
    	zeros=0;
    else zeros = max(other,ans) - min(ans,other) - 1;
    //cout<<"zeros:"<<zeros<<endl;
    cout<<(ans+other+zeros)<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int start;
	int n;
	while(t--){
		sum=0;
		start=0;
		f(i,0,105)
		f(j,0,905)
		dp[i][j]=-1;
		f(i,1,10){
			cin>>n;
			sum += i*n;
			f(j,0,n){
				a[start++]=i;
			}
		}
		size=start;
		solve();
	}
	return 0;
}
