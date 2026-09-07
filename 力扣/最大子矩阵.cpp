#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=m;i++){
        dp[1][i]=dp[1][i-1]+mat[1][i];
    }
    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1]+mat[i][1];
    }
    int max_n=-1e9;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i][j]-dp[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(max_n<dp[i][j]){
                max_n=dp[i][j];
            }
        }
    }
    cout<<max_n<<endl;
    return 0;
}