class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp =0,rp=height.size()-1,maxArea=0;
        while(lp<rp){
            int w=rp-lp;
            int ht=min(height[lp],height[rp]);
            int currentarea=w*ht;
            maxArea=max(maxArea,currentarea);

            if(height[lp]<height[rp]){
                lp++;
            }else {
                rp--;
            }
        }
        return maxArea;
    }
};
