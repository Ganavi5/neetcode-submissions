class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());
        int ans=0;
        //now we need to find if start elemnt is present or not
        for(int num : st){
            if(!st.count(num-1)){
                int len=1;
                int curr=num;
                while(st.count(curr+1)){
                    curr++;
                    len++;
                    

                }
                ans=max(ans,len);


            }
            

        }
        
        

        





        


    return ans;    
    }
};
