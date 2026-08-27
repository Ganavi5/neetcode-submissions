class Solution {
public:
    int ans=0;
    int maxArea(vector<int>& heights) {
        //take two pointers one at the end and one at the beg
        //moving the smaller height becuase widith will anyways decrease while we move pointer so we need to discard the smaller height onr and move
        int i=0;
        int j=heights.size()-1;
        int  result;
        
        while(i<j){

            result=(j-i)*min(heights[i],heights[j]);
            ans=max(ans,result);
            if(heights[i]<heights[j]){
                i++;
            }
            else{
                j--;
            }

            
            

            
        }
        
        
        
        
      return ans;  
    }
};
