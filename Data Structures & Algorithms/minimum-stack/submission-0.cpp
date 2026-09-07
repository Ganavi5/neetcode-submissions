class MinStack {
public:
    MinStack() {
        
        
    }
    stack<int> st;
    stack<int> min_st;
    
    void push(int val) {
        st.push(val);
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        } else {
            min_st.push(min_st.top());
        }
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
       int t=st.top();
        
        return t;
        
    }
    
    int getMin() {
        return min_st.top();
    } 
};
