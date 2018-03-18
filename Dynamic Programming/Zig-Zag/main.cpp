#include <bits/stdc++.h>
using namespace std;
//TopCoder's fastest Solution
class ZigZag {
  public:
  int longestZigZag(vector <int> sequence)
  {
    if(sequence.size() == 1) return 1;
    vector<int> v(sequence.size()-1);
    for(int i=1;i<sequence.size();i++)
    {
      v[i-1] = sequence[i] - sequence[i-1];
    }
    //    dir is first nonzero
    int ii=0;
    while( ii < v.size() && v[ii] == 0)
    ii++;
    if(ii == v.size()) return 1;
    int dir = v[ii];
    int len = 2;
    for(int i=ii+1;i<v.size();i++)
    {
      if(v[i] * dir < 0)
      {
        dir *= -1;
        len++;
      }
    }
    return len;
  }
};
//Mine Solution
// O(nLog(n))
int zigzag(vector<int>& a)
{
    multimap<int,pair<int,char>, greater<int> > m;
    multimap<int,pair<int,char>, greater<int> >::iterator itr;
    if(a.size()==1)
        return 1;
    if(a[0]>a[1])
    {
        m.insert(make_pair(1,make_pair(a[0],'A')));
        m.insert(make_pair(2,make_pair(a[1],'H')));
    }
    else if(a[0]<a[1])
    {
        m.insert(make_pair(1,make_pair(a[0],'A')));
        m.insert(make_pair(2,make_pair(a[1],'L')));
    }
    else
    {
        m.insert(make_pair(1,make_pair(a[0],'A')));
        m.insert(make_pair(1,make_pair(a[1],'A')));
    }
    for(unsigned i=2; i<a.size(); i++)
    {
        itr=m.begin();
        for(; itr!=m.end(); itr++)
        {
            if( ( (*itr).second.first > a[i] )&&((*itr).second.second == 'L' || (*itr).second.second == 'A'))
            {
                m.insert(make_pair((*itr).first+1,make_pair(a[i],'H')));
                break;
            }
            else if(((*itr).second.first < a[i])&&((*itr).second.second == 'H' || (*itr).second.second == 'A'))
            {
                m.insert(make_pair((*itr).first+1,make_pair(a[i],'L')));
                break;
            }
        }
    }
    itr=m.begin();
    return itr->first;
}
int main()
{
    //vector<int> v;//={ 189, 189, 206, 228, 240, 228, 263, 259, 256, 266, 287, 302, 297, 330, 341, 353, 353, 364, 376, 365, 398, 386, 420, 413, 419, 451, 441, 463, 484, 480, 487, 494, 520, 534, 396, 549, 22, 819, 611, 972, 730, 638, 978, 342, 566, 514, 752, 871, 911, 172, 488, 542, 482, 974, 210, 474, 66, 387, 1, 872, 799, 262, 567, 113, 578, 308, 813, 515, 716, 905, 434, 101, 632, 450, 74, 254, 1000, 780, 633, 496, 513, 772, 925, 746};
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++)
        {
            cin >> v[i];
        }
        cout << zigzag(v) << endl;
    }
    return 0;
}
