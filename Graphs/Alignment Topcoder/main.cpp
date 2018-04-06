#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones)
    {
        map<int,unordered_set<int> > m;
        unordered_set<int> visited;
        set<int> stonesHash;
        for (int i=1; i<stones.size(); i++)
            stonesHash.insert(stones[i]);
        if(stonesHash.find(1) == stonesHash.end())
        	return false;
        visited.insert(1);
        m[1].insert(1);
        for (auto i = stonesHash.begin(); i != stonesHash.end() ; i++) {
        	if(visited.find(*i) == visited.end() )
        		continue;
            for (auto itr = m[(*i)].begin(); itr != m[(*i)].end(); itr++) {
                if (stonesHash.find((*itr)+(*i)) != stonesHash.end() ) {
                    m[(*itr)+(*i)].insert((*itr));
                    visited.insert((*itr)+(*i));
                }
                if (stonesHash.find((*itr)+1+(*i)) != stonesHash.end() ) {
                	m[(*itr)+(*i)+1].insert((*itr)+1);
                	visited.insert((*itr)+(*i)+1);
                }
                if (stonesHash.find((*itr)-1+(*i)) != stonesHash.end() && (*itr)-1 != 0) {
                	m[(*itr)+(*i)-1].insert((*itr)-1);
                	visited.insert((*itr)+(*i)-1);
                }
            }
        }/*
        for ( auto itr = visited.begin(); itr!= visited.end(); itr++)
            cout << *itr << " ";*/
        //cout << endl;
        if (visited.find(stones[stones.size()-1]) == visited.end())
        	return false;
        else
        	return true;
    }
};
int main()
{
    vector<int> array = {0,1,2,3,4,8,9,11};
    Solution obj;
    cout << obj.canCross(array);
    return 0;

}
