/*Using O(n), iterating with two pointer to find the middle elements*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, j, l, mid1, mid2, l1=nums1.size(), l2=nums2.size();
        double median, val1, val2;
        l = l1+l2;
        if(l%2 == 1){
            mid1 = l/2;
            i=0, j=0;
            while(mid1>=0){
                if(i<nums1.size() && j<nums2.size()){
                    if(nums1[i]>nums2[j]){
                        median = nums2[j];
                        j++;
                    }
                    else{
                        median = nums1[i];
                        i++;
                    }
                }
                else if(i<nums1.size()){
                    median = nums1[i];
                    i++;
                }
                else{
                    median = nums2[j];
                    j++;
                }
                mid1--;
            }
        }
        else{
            mid1 = l/2, mid2=mid1-1;
            i=0, j=0;
            while(mid1>=0){
                if(i<nums1.size() && j<nums2.size()){
                    if(nums1[i]>nums2[j]){
                        val1 = nums2[j];
                        j++;
                    }
                    else{
                        val1 = nums1[i];
                        i++;
                    }
                }
                else if(i<nums1.size()){
                    val1 = nums1[i];
                    i++;
                }
                else{
                    val1 = nums2[j];
                    j++;
                }
                mid1--;
            }
            // cout<<val1<<endl;
            i=0, j=0;
            while(mid2>=0){
                if(i<nums1.size() && j<nums2.size()){
                    if(nums1[i]>nums2[j]){
                        val2 = nums2[j];
                        j++;
                    }
                    else{
                        val2 = nums1[i];
                        i++;
                    }
                }
                else if(i<nums1.size()){
                    val2 = nums1[i];
                    i++;
                }
                else{
                    val2 = nums2[j];
                    j++;
                }
                mid2--;
            }
            // cout<<val2<<endl;
            median = (val1+val2)/2;
        }
        return median;
    }
};