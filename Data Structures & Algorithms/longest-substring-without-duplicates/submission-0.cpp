class Solution {
public:


    int lengthOfLongestSubstring(string s) {
        //longest sunstring without repeatng charcters
        // zxyzxyz
        
        //if count>1 then make the length 0 

        unordered_map<char,int> freq;
        int left=0;
        int max_length=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                left++;
                
            }
            max_length=max(max_length,right-left+1);
        }
       
    return max_length;    
    }
};
