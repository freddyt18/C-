#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        map<int, int> count;
        vector<vector<int>> result;
        

        for(int i = 0; i < n; i++){
            count[i] = 0;
        }


        for(vector x : connections){
            for(int y : x){
                for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
                {
                    if(y == it->first){
                        count[it->first] = it->second += 1;
                    }
                }
            }
        }


        int minimum = 999999999;
        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        {
            if(it->second < minimum){
                minimum = it->second;
            }
        }

        for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it)
        {
            cout << it->first << ":" << it->second << endl;
            if(it->second == minimum){
                for(vector x : connections){
                    if (find(x.begin(), x.end(), it->first) != x.end())
                    {
                        result.push_back(x);
                    }
                }
            }
        }

        // for(vector<int> x : result)
        // {
        //     if(find(result.begin(), result.end(), x) != result.end())
        //     {
        //         result.erase(find(result.begin(), result.end(), x));
        //     }
        // }

        if(result.size() > connections.size()) return {result[0]};

        return result;

    }
};


int main(){

    Solution s;

    vector<vector<int>> con = {
        {0,1},
        {1,2},
        {2,0},
        {1,3},
        {3,4},
        {4,5},
        {5,3}
    };

    for(vector x : s.criticalConnections(6, con)){
        for(int y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}