class TimeMap {
public:
    TimeMap() {
       


        
    }
    unordered_map<string ,vector<pair<int,string>>> u;


    
    void set(string key, string value, int timestamp) {
        u[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        
        
        int l=0;
        int r=u[key].size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            
            if(u[key][mid].first==timestamp){
                return u[key][mid].second;
            }
            else if(u[key][mid].first>timestamp){
                r=mid-1;
                
            }
            else {
                l=mid+1;
            }

            





        }
        if(r<0) return "";

        return u[key][r].second;
       


        
    }
};
