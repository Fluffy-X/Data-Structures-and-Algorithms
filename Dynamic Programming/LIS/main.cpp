#include <bits/stdc++.h>

using namespace std;

int binary(vector<int>& v, int val, int start, int stop)
{
    if(val < v[start])
        return -1;
    if(val > v[stop])
        return -2;
	while(1)
	{
	    if(start-stop == 0)
            return start;
		if(stop-start == 1)
        {
            if(v[stop] < val)
                return stop;
            return start;
        }
		if(v[(start+stop)/2] < val)
			start = (start+stop)/2;
		else
			stop = ((start+stop)/2)-1;
	}
}
int binarysearch(vector<int>& v, int val, int start, int stop)
{
    while(1)
    {
        if(start == stop)
        {
            if(v[start] == val)
                return 1;
            else
                return 0;
        }
        if(v[(start+stop)/2] == val)
            return 1;
        else if(v[(start+stop)/2] > val)
        {
            stop = (start+stop)/2-1;
        }
        else
        {
            start = (start+stop)/2+1;
        }
    }
}

int longestIncreasingSubsequence(vector<int>& v)
{
    if(v.size()==0)
        return 0;
    if(v.size()==1)
        return 1;
	std::vector<int> memo(1000001);
	int start=1,stop=1;
	memo[1] = v[0];
	int cat;
	for (int i = 1; i < v.size(); ++i)
	{
        if(binarysearch(memo,v[i],start,stop))
            continue;
		cat = binary(memo,v[i],start,stop);
		//cout << " Cat is : " << cat << endl;
		if(cat == -1)
			memo[start] = v[i];
		else if( cat == -2)
		{
			stop++;
			memo[stop] = v[i];
		}
		else
		{
			memo[cat+1] = v[i];
		}
	}
	/*for (int i = 0; i <= 5; ++i)
    {
        cout << memo[i] << " ";
    }*/
	return stop;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int val;int t; cin >> t;
    //int result = longestIncreasingSubsequence(arr);
    while(t--)
    {
        cin >> val;
        int result = binarysearch(arr,val,1,1);
        cout << result << endl;
    }
    return 0;
}
