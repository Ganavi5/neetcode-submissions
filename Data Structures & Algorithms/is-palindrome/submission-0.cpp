class Solution {
public:
    bool isPalindrome(string s) {
        //check for palindrom
       
        string str="";
        for(char c :s){
            if(isalnum(c)){
                str+=tolower(c);
            }
        }
        int n=str.size()-1;
        int mid=n/2;
        

        
        for(int i=0;i<=mid;i++){
            if(str[i]!=str[n]){
                return false;

            }
            n--;
            
        }
            
        return true;       
        }
        
      
    };
