class Solution {
public:
    int findMin(vector<int> &nums) {

        // bs l ,m ,r
        //m>r; l=m+1;
        //m<r ; r=m-1;
        //return l
        // 3 4 5 6 1 2
        

        int l=0; 
        int r =nums.size()-1;
        int mid;
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;

            }
            else{
                r=mid;
            }




        }
        return nums[l] ;







        
        
    }
};
