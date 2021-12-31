#include <iostream>
using namespace std;

int count = 0;  // counts the number of ways possible to place knights

// Checking if we can place knight at (i,j)th position on board
bool canplaceKnight(int size, int board[][10], int i, int j){
    for(int row=0;row<i;row++){
        for(int col=0;col<size;col++){
            if(board[row][col] == 1){
                if((abs(j-col)==2 && i-row == 1) || (abs(j-col)==1 && i-row == 2)){
                        return false;  
                }
            }
        }
    }
    return true;
}


void f(int n, int board[][10], int size,int i = 0,int j = 0){
    
    // base case
	// We have placed all the knights
    if(n == 0){
        count++;
        for(int row = 0; row < size; row++){
            for(int col = 0; col < size; col++){
                if(board[row][col] == 1){
                    cout << "{" << row << "-" << col << "}" << " ";
                }
            }
        }
        cout << " ";
        return;
    }
	// We have reached the end of the chessboard
    if(i==size && j==0) 
        return;

    //recursive case

    if( canplaceKnight(size, board, i, j)){
        board[i][j] = 1;
        if(j == size-1){              // We have reached end of row
            f(n-1,board,size,i+1,0);  
        }else{
            f(n-1,board,size,i,j+1);
        }
        board[i][j] = 0;             //backtrack
    }

    if(j == size-1){
        f(n,board,size,i+1,0);
    }else{
        f(n,board,size,i,j+1);
    }
    
}

int main() {
    int N;
    cin >> N;               // Number of knights to be placed
    int board[10][10] = {};
    int size = N;           // Size of chessboard

    f(N,board,size);       // Places 'N' knights on chessboard
    cout<<endl;
    cout<<count<<endl;

    return 0;
}