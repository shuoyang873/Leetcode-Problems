/*
经典版：NOIP1999 普及组 · 导弹拦截
对应题库：洛谷 P1020 / codevs 1044 / 信息学奥赛一本通 1260
题目描述
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种系统有一个缺陷：虽然第一发炮弹能到达任意高度，但以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国导弹来袭，由于只有一套系统，可能无法拦截所有导弹。
输入导弹依次飞来的高度（不大于 30000 的正整数），请计算：
这套系统最多能拦截多少导弹？
要拦截所有导弹，最少要配备多少套这样的系统？
输入输出
输入：一行，若干个正整数，表示导弹依次飞来的高度
输出：两行，第一行为最多拦截数，第二行为最少系统套数
样例
文本



输入：389 207 155 300 299 170 158 65
输出：
6
2
解题要点
第一问：求最长不上升子序列（LNIS）的长度，经典 DP，可用 O(n²) 或 O(n log n)（二分优化）解决
第二问：根据 Dilworth 定理，最少链划分 = 最长反链长度，即求最长上升子序列（LIS）的长度
*/


//先解决最少需要几套系统的问题，首先，这道题可以抽象为最少的非递增数列的数量，然后根据Dilword定理，最少非递减数列的数量等于最长严格递增数列的长度，所以可以采用动态规划的方法来解题

// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     vector<int>missile;
//     while(cin>>n){
//         missile.push_back(n);
//     }
//     vector<int>dp(missile.size(),1);
//     int len=missile.size();
//     for(int i=1;i<len;i++){
//         for(int j=0;j<i;j++){
//             if(missile[j]<missile[i]){
//                 dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//     }
//     int max_len=0;
//     for(int i=0;i<len;i++){
//         max_len=max(max_len,dp[i]);
//     }
//     cout<<max_len<<endl;
//     return 0;
// }


//第二种方法就是采用tail数组和贪心算法来写的

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>tail;

int main(){
    int n;
    vector<int>missile;
    while(cin>>n){
        missile.push_back(n);
        if(tail.empty()||tail.back()<n){
            tail.push_back(n);
        }
        else{
            *lower_bound(tail.begin(), tail.end(), n) = n;
        }
    }
    cout<<tail.size()<<endl;
    return 0;
}