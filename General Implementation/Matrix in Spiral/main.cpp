#include <iostream>
#define R 3
#define C 3
#include <vector>
using namespace std;

int main()
{
    int matrix[R][C] = {
                         {1, 2, 3},
                         {4, 5, 6},
                         {7, 8, 9}
                        };
    vector<int> answer;
    int no_of_rows = R, no_of_columns = C;
    int ir=no_of_rows, ic = no_of_columns;
    int jr = 0, jc = -1;
    int r = 0, c = 0;
    for(;;)
    {
        if(!(c < ic))
            break;
        for(; c < ic ; c++ )
            {
                cout << matrix[r][c] << " " ;
                answer.push_back(matrix[r][c]);
            }
        r++;c--;ic--;
        if(!(r < ir))
            break;
        for( ; r < ir ; r++ )
            {cout << matrix[r][c] << " " ;answer.push_back(matrix[r][c]);}
        c--;r--;ir--;
        if(!(c > jc))
            break;
        for(  ; c > jc ; c-- )
            {cout << matrix[r][c] << " " ;answer.push_back(matrix[r][c]);}
        c++;r--;jc++;
        if(!(r > jr))
            break;
        for(  ; r > jr ; r-- )
            {cout << matrix[r][c] << " " ;answer.push_back(matrix[r][c]);}
        r++;jr++;
        c++;//, ir--, ic--;
    }
    vector<vector<int> > v;

    vector<int>::iterator it;
    cout << endl;
    for( it=answer.begin();it!=answer.end() ;it++ )
    {
        cout << *it << " ";
    }
    return 0;
}
