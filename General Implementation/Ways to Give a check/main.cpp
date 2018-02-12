#include <bits/stdc++.h>
using namespace std;
int find_knight(int valid, vector<vector<char> > board);
int find_rook(int valid, vector<vector<char> > board);
int find_bishop(int valid, vector<vector<char> > board);
int waysToGiveACheck(vector<vector<char> > &board)
{
    int valid;
    for(int i=0; i<8; i++)
    {
        if(board[1][i] == 'P')
        {
            if(board[0][i] == '#')
                valid = i;
        }
    } // 1,valid
    int king_i;
    int king_j;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(board[i][j] == 'k')
            {
                king_i = i;
                king_j = j;
            }
        }
    }
    board[1][valid] = '#';
    if( king_i == 1)
    {
        for(int j=king_j+1; j<8; j++)
        {
            if(board[1][j] != '#' && (board[1][j] != 'R' && board[1][j] != 'Q') )
                break;
            else if( board[1][j] == 'R' || board[1][j] == 'Q' )
                return 4;
        }
        for(int j=king_j-1; j>=0; j--)
        {
            if(board[1][j]!= '#' && (board[1][j] != 'R' && board[1][j] != 'Q') )
                break;
            else if( board[1][j] == 'R' || board[1][j] == 'Q' )
                return 4;
        }
    }
    if( abs(king_i-1) == abs(king_j-valid))
    {
        int i=king_i;
        int j=king_j;
        i++;j--;

        for( ; i<8 && i>=0 && j>=0 && j<8;)
        {
            if( board[i][j]!= '#' && board[i][j] != 'B' && board[i][j] != 'Q' )
                break;
            else if( board[i][j] == 'B' || board[i][j] == 'Q' )
                return 4;
            i++;j--;
        }

        i=king_i;
        j=king_j;
        i--;j--;

        for( ; i<8 && i>=0 && j>=0 && j<8;)
        {
            if( board[i][j] != '#' && board[i][j] != 'B' && board[i][j] != 'Q' )
                break;
            else if( board[i][j] == 'B' || board[i][j] == 'Q' )
                return 4;
            i--;j--;
        }

        i=king_i;
        j=king_j;
        i++;j++;

        for( ; i<8 && i>=0 && j>=0 && j<8;)
        {
            if(board[i][j]!= '#' && (board[i][j] != 'B' && board[i][j] != 'Q') )
                break;
            else if( board[i][j] == 'B' || board[i][j] == 'Q' )
                return 4;
             i++;j++;
        }

        i=king_i;
        j=king_j;
        i--;j++;

        for( ; i<8 && i>=0 && j>=0 && j<8;)
        {
            if(board[i][j]!= '#' && board[i][j] != 'B' && board[i][j] != 'Q' )
                break;
            else if( board[i][j] == 'B' || board[i][j] == 'Q' )
                return 4;
            i--;j++;
        }

    }
    if(find_knight(valid,board))
        return 1;
    else if(find_bishop(valid,board))
        return 2;
    else if(find_rook(valid,board))
        return 2;
    else
        return 0;

}
int find_knight(int valid, vector<vector<char> > board)
{
    vector<pair<int,int> > v;
    int j=valid;
    v.push_back(make_pair(1,-2));
    v.push_back(make_pair(2,-1));
    v.push_back(make_pair(2,+1));
    v.push_back(make_pair(1,+2));
    for(int i=0; i<4; i++)
    {
        if(v[i].first >=0 && v[i].first <=8 && v[i].second+j >=0 && v[i].second+j <=8)
        {
            if(board[v[i].first][v[i].second+j] == 'k')
                return 1;
        }
    }
    return 0;
}
int find_rook(int valid, vector<vector<char> > board)
{
    for(int i=valid+1; i<8; i++)
    {
        if(board[0][i] != '#' && board[0][i] != 'k' )
            break;
        if(board[0][i] == 'k')
            return 1;
    }
    for(int i=valid-1; i<8; i--)
    {
        if(board[0][i] != '#' && board[0][i] != 'k' )
            break;
        if(board[0][i] == 'k')
            return 1;
    }
    for(int i=0; i<8; i++)
    {
        if(board[i][valid] != '#' && board[i][valid] != 'k' )
            break;
        if(board[i][valid] == 'k')
            return 1;
    }
    return 0;
}
int find_bishop(int valid, vector<vector<char> > board)
{
    int j=valid;
    int i=0;
    for(; i<8 && i>=0 && j>=0 && j<8;)
    {
        if(board[i][j] != '#' && board[i][j] != 'k' )
            break;
        if(board[i][j] == 'k')
            return 1;
         i++;j--;
    }
    j=valid;i=0;
    for(; i<8 && i>=0 && j>=0 && j<8; )
    {
        if(board[i][j] != '#' && board[i][j] != 'k' )
            break;
        if(board[i][j] == 'k')
            return 1;
        i++;j++;
    }
    return 0;
}
int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        vector< vector<char> > board(8,vector<char>(8));
        for(int board_i = 0;board_i < 8;board_i++){
           for(int board_j = 0;board_j < 8;board_j++){
              cin >> board[board_i][board_j];
           }
        }
        int result = waysToGiveACheck(board);
        cout << result << endl;
    }
    return 0;
}
