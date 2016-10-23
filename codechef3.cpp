#include <bits/stdc++.h>
using namespace std;


int n,m;
int *maxSubArraySum(int *a,int size){
    int max_so_far = 0, max_ending_here = 0;
    int *b = new int[size];
    for (int i = 0; i < size; i++){
        max_ending_here = max_ending_here + a[i];
        b[i] = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return b;
}

int help[1001];
int a[1001][1001];	
void reverse_col(){

}
void reverse_row(int c){
	for(int i=0;i<m;++i){
		help[i] = a[c][m-i-1];
	}
}

int main(){
	int t;
	cin>>t;
	int sum1[1001][1001];
	int sum2[1001][1001];
	int sum3[1001][1001];
	int sum4[1001][1001];
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>a[i][j];
			}
		}
		
		for(int i=0;i<n;++i){
			sum1[i] = maxSubArraySum(a[i],n);
		}
		for(int i=0;i<n;++i){
			reverse_row(i);
			sum2[i] = maxSubArraySum(help,n);
		}
		


	}
	return 0;
}