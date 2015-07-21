#include<iostream>
#include<vector>
#include<map>
#include<time.h>
#include<math.h>
#include<unordered_set>
#include<stack>
using namespace std;
vector<vector<bool> > square(9,vector<bool>(9,true));
vector<vector<bool> > row(9,vector<bool>(9,true));
vector<vector<bool> > col(9,vector<bool>(9,true));
bool solve(vector<string>& board,int i,int j){
    if(j==9){j=0;i++;}
    if(i>=9) return true;
    int sqno=3*(i/3) + (j/3);
    if(board[i][j]!='.') {return solve(board,i,j+1);}
    for(int c=49;c<=57;c++){
        if(square[sqno][c%49] && row[i][c%49] && col[j][c%49]){
            board[i][j]=(char)c;
            square[sqno][c%49]=false;
            row[i][c%49]=false;
            col[j][c%49]=false;
            if(solve(board,i,j+1)) return true;
            else{
                board[i][j]='.';
                square[sqno][c%49]=true;
                row[i][c%49]=true;
                col[j][c%49]=true;
            }
        }
    }
    return false;
}
void solveSudoku(vector<string>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            char val=board[i][j];
            if(val!='.'){
            int sqno=3*(i/3) + (j/3);
            square[sqno][val%49]=false;
            row[i][val%49]=false;
            col[j][val%49]=false;
        }
        }
    }
    solve(board,0,0);
}
 
    int main(){
        vector<string> board {{"..9748..."},{"7........"},{".2.1.9..."},{"..7...24."},{".64.1.59."},{".98...3.."},{"...8.3.2."},{"........6"},{"...2759.."}};
        solveSudoku(board);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }

