class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //find the target elemnt wherein the target element 
        
        //we need to loop from brgining to the elemnt that is less than the target elemnt
    //find the index of the elemt which is less or equal to tareget elemnt
    //keep two pointers one at the last one at begin if sum>target decrement last index if sum<target incremnt the start index 

int i=0;
int j=numbers.size()-1;
vector<int> r;
while(i<j){
    if(numbers[i]+numbers[j]>target){
        j--;
    }
    else if(numbers[i]+numbers[j]<target){
        i++;
    }
    else{
        return { i+1,j+1};
    }
   
}
return { };       
}

};
