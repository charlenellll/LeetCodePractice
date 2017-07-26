class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        
        for(int i = 0; i < points.size(); i++ ){
            
            unordered_map<int,int> record;
            for(int j = 0; j < points.size(); j++)
                if( j != i )
                    record[ dis(points[i], points[j]) ] ++;
            
            for( unordered_map<int,int>::iterator iter = record.begin(); iter != record.end(); iter++) 
                    res += iter->second * (iter->second - 1);
                    // No need for if( iter->second >= 2) cuz when it == 1, it*(it - 1) = 0: no influence
        }
        
        return res;
    }
    
private:
    int dis( const pair<int,int>&pa, const pair<int,int>&pb){
        return (pa.first - pb.first) * (pa.first - pb.first) + (pa.second - pb.second) * (pa.second - pb.second);
    }
    
};