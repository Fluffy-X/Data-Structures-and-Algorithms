    // Find greater than
    #include <bits/stdc++.h>
    using namespace std;

    int binary(std::vector<int> v, int val, int start, int stop)
    {
        if(start == stop)
        {
            if(v[start] == val)
                return start+1;
            else
                return -1;
        }
        int m;
        while(1)
        {
            if(stop - start == 1)
            {
                if(v[start] == val)
                    return start+1;
                else if(v[stop] == val)
                    return stop+1;
               else
                    return -1;
            }
            m = (start+stop)/2;
            if( val < v[m])
                stop = m-1;
            else if(val > v[m] )
                start = m+1;
            else
                return m+1;
        }
    }

    int main()
    {
        int n;
        cin >> n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int t;
        cin >> t;
        int val;
        if(v[0] > v[1])
        {
            reverse(v.begin(),v.end());
            while(t--)
            {
                cin >> val;
                cout << n+1-binary(v,val,0,n-1) << endl;
            }
        }

        else
        {
            while(t--)
            {
                cin >> val;
                cout << binary(v,val,0,n-1) << endl;
            }
        }
    }
