class Solution {
public:
    int maxArea(vector<int>& height) {
    int l=0;
    int r= height.size()-1;
    int  max_area =0;
    while (l<r){
     int h_left = height[l];
        int h_right = height[r];
        int area = (r - l) * std::min(h_left, h_right);
     if(area>max_area){
        max_area = area;
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