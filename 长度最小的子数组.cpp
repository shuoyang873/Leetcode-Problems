class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        if(n==0)return n;
        int min_len=INT_MAX,sum=0;
        int pos1=0,pos2=0;
        while(pos2<n){
            sum+=nums[pos2];
            while(sum>=target){
                min_len=min(min_len,pos2-pos1+1);
                sum-=nums[pos1];
                pos1++;
            }
            pos2++;
        }
        if(min_len==INT_MAX)return 0;
        return min_len;
    }
};
