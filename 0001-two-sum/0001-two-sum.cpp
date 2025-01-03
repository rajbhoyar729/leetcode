class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ans;
        for(int i = 0; i < nums.size(); ++i){
        ans.push_back(make_pair(nums[i], i));    }
       int l=0;
        int r= nums.size()-1;
        int sum=0;
             sort(ans.begin(),ans.end()) ;
         while(l<r) {
             sum = ans[l].first + ans[r].first;

             if(sum==target){
             return {ans[l].second, ans[r].second};
             }
             else{
                if(sum<target){
                    l++;
                }
                else{
                    if(sum>target)
                    {
                        r--;
                    }
                }
             }

         }
            return {};
    }
};