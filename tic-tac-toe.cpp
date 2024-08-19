#include<iostream>
using namespace std;

void show_config(char board[3][3]){
  cout<<"----------"<<endl;
    for(int i=0; i<3; i++){
      cout<<"|";
      for(int j=0; j<3; j++)
        cout<<board[i][j]<<" |";
        cout<<endl<<"----------"<<endl;
    }
  
}

void check_win(char board[3][3]){
    int i, j, flag=-1;
    for(i=0; i<3; i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' '){
            show_config(board);
            cout<<board[i][0]<<" wins";
            exit(0);
        }
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]!=' '){
            show_config(board);
            cout<<board[0][i]<<" wins";
            exit(0);
        }
    }
    if(((board[0][0]==board[1][1] && board[0][0]==board[2][2]) || (board[0][2]==board[1][1] && board[0][2]==board[2][0])) && board[1][1]!=' '){
        show_config(board);
        cout<<board[1][1]<<" wins";
        exit(0);
    }
    for(i=0; i<3; i++)
      for(j=0; j<3; j++)
        if(board[i][j]==' '){
          flag=0;
        }
    if(flag==-1){
        cout<<"draw";
        exit(0);
    }
}

int check_legal(char board[3][3], int i, int j){
    if(i<3 && j<3 && board[i][j]==' '){
        return 1;
    }
    else{
        return 0;
    }
}

void put_symbol(char board[3][3], int i, int j, char c){
    board[i][j]=c;
}

int main(){
    char board[3][3], c, c1=' ';
    int count=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=' ';
        }
    }
    while(count<9){
      show_config(board);
      int i, j;
      cout<<"enter position"<<endl;
      cin>>i>>j;
      i--; j--;
      if(check_legal(board,i,j)==1){
        cout<<"enter character"<<endl;
        cin>>c;
        if(c1!=c){
          put_symbol(board,i,j,c);
          count++;
        }
        else{
          cout<<"wrong player\n";
        }
      }
      else{
        cout<<"illegal move\n";
        continue;
      }
      check_win(board);
      c1=c;
    }
    return 0;
}