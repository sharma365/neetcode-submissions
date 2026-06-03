class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1;
        int area=0;
        
        while(left<right){
            int width=right-left;
            int height=min(heights[left],heights[right]);
            area=max(area,width*height);
            
            if(heights[left]<=heights[right])
            left++;
            else right--;
        }
        return area;
    }
};
