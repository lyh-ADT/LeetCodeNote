class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i < nums.size(); ++i){
            int t = find(target-nums[i], nums);
            if(t != -1 && t != i){
                vector<int> a;
                a.push_back(i);
                a.push_back(t);
                return a;
            }
        }
        //return NULL;
    }
private:
    int find(int a, vector<int>& nums){
        for(int i=0; i < nums.size(); ++i){
            if(a == nums[i]){
                return i;
            }
        }
        return -1;
    }
};
