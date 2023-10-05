// O(n^2 solution)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        bool equal_flag, gr_flag;
        for(int i=0; i<nums1.size(); i++){
            equal_flag = false;
            gr_flag = false;
            for(int j=0; j<nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    equal_flag = true;
                }
                if(nums2[j] > nums1[i] && equal_flag == true){
                    ans.push_back(nums2[j]);
                    gr_flag = true;
                    break;
                }
            }
            if(gr_flag == false){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};