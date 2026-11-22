#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>snow(n);
    for(int i=0;i<n;i++){
        vector<int>a(6),b(6);
        for(int j=0;j<6;j++){
            cin>>a[j];
            b[5-j]=a[j];
        }

        bool first=true;
        vector<int>best(6);
        for(int j=1;j<=6;j++){
            vector<int>l(6),r(6);
            for(int k=0;k<6;k++){
                l[k]=a[(j+k)%6];
                r[k]=b[(j+k)%6];
            }
            if(first){
                best=min(l,r);
                first=false;
            }
            else{
                best=min(min(l,r),best);
            }
        }
        snow[i]=best;
    }
    sort(snow.begin(),snow.end());
    for(int i=1;i<n;i++){
        if(snow[i-1]==snow[i]){
            cout<<"Twin snowflakes found."<<endl;
            return 0;
        }
    }
    cout<<"No two snowflakes are alike."<<endl;
    return 0;
}