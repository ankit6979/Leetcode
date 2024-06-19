class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        priority_queue<int, vector<int>, greater<int>> arr;
        int currDiff, currSum=0;
        for(int i=0; i<heights.size()-1; i++){
            currDiff = heights[i+1]-heights[i];
            if(currDiff>0){
                if(ladder != 0){
                    arr.push(currDiff);
                    ladder--;
                }
                else if(ladder==0){
                    if(!arr.empty() && currDiff>arr.top()){
                        currSum+=arr.top();
                        arr.pop();
                        arr.push(currDiff);
                    }
                    else{
                        currSum+=currDiff;
                    }
                }
                if(currSum>bricks){
                    return i;
                }
            }
        }
        return heights.size()-1;
    }
};