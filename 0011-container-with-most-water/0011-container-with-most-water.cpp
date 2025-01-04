class Solution {
public:
    int maxArea(vector<int>& height) {
    int l=0;
    int r= height.size()-1;
    int  max_area =0;
    while (l<r){
     int current_area = (r-l) * min(height[l],height[r]);
     if(current_area>max_area){
        max_area = current_area;
     }

     if (height[l]<height[r]){
        l++;
     }
     else {
            r--;
        }
       
    }
        return max_area;
    }
};