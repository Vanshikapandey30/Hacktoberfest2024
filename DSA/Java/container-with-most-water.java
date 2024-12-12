class Solution {
    public int maxArea(int[] height) {
        int n=height.length;
        int left=0,right=n-1;
            int max=0;
            for(int i=0;i<n;i++)
            {
                int area=Math.min(height[left],height[right])*(right-left);
                max=Math.max(area,max);
                if(height[left]<height[right])
                    left++;
                else
                    right--;
                if (left >= right) 
                    break;
            }
        return max;

    }
}
