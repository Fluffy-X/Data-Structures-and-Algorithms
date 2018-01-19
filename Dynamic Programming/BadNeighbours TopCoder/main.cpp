#include <bits/stdc++.h>
using namespace std;
int start=1;
template <class T> T MAX(const T &x, const T &y) {return x>y? x:y;}
//TopCoder's Fastest Submission
class BadNeighbors
{
  public:
  map<int, int> answer;
  vector<int> blah;

  int getAnswer(int i1, int i2)
  {
    int key = i1*500+i2;
    if (answer.count(key)) return answer[key];
    if (i1 > i2) return 0;
    answer[key] = MAX(getAnswer(i1+1,i2), getAnswer(i1+2,i2)+blah[i1]);
    return answer[key];
  }

  int maxDonations(vector <int> donations)
  {
    blah = donations;
    int n = donations.size();
    return MAX(getAnswer(0,n-2), getAnswer(1,n-1));
  }
};
//Mine Solution
int F(vector<int>& v,vector<vector<int> >& memo, int i, int j) // i : start, j : stopp indices
{
    if(start)
    {
        if(j==1)
        return max(v[0],v[1]);
        start--;
        return max(v[j]+F(v,memo,i+1,j-2), F(v,memo,i,j-1));
    }
    if(j-i==1 || j-i==0)
        return max(v[i],v[j]);
    else
    {
        if(memo[i][j-2]!=-1 && memo[i][j-1]!=-1)
            return max(memo[i][j-2]+v[j],memo[i][j-1]);
        else if(memo[i][j-2]==-1 && memo[i][j-1]!=-1)
        {
            memo[i][j-2]=F(v,memo,i,j-2);
            return max(memo[i][j-2]+v[j],memo[i][j-1]);
        }
        else if(memo[i][j-2]!=-1 && memo[i][j-1]==-1)
        {
            memo[i][j-1]=F(v,memo,i,j-1);
            return max(memo[i][j-2]+v[j],memo[i][j-1]);
        }
        else
        {
            memo[i][j-1]=F(v,memo,i,j-1);
            memo[i][j-2]=F(v,memo,i,j-2);
            return max(memo[i][j-2]+v[j],memo[i][j-1]);
        }
    }
}

int main()
{
    BadNeighbors b;
    vector<int> v = {924, 602, 959, 7, 608, 218, 523, 697, 292, 980, 881, 265, 205, 256, 198, 862, 142, 940, 715, 482, 425, 288, 791, 929, 876, 594, 704, 404, 682, 901, 719, 450, 81, 114, 738, 498, 657, 72, 966};
    cout << b.maxDonations(v);
    //cout << endl;
    //vector<vector<int> > memo(2,vector<int>(v.size(),-1));
    //cout << F(v,memo,0,v.size()-1);
    return 0;
}
