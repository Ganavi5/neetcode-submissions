class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        //[1 ,2 ,+ ,3, * ,4 ,-]
        //take the integers to a stack 
        stack<int > st;
        for(int i=0;i<tokens.size();i++){
            
            if( tokens[i]=="+") {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a+b);
                

            
            }
            else if (tokens[i]=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);

            }
            else if (tokens[i]=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if (tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
            }
            else{    st.push(stoi(tokens[i]));
            }

            

        }

    return st.top();    

        
    }
};
