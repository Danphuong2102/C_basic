// Viết chương trình trò chơi tic tac toe

#include<stdio.h>
#include<string.h>
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
void drawboard();
int markboard(int position, char mark);
char checkwinner();
int main(){ 
    int position;
    char currentPlayer = 'X';
    int turnCount = 0;

    while (1) {
        drawboard();
        printf("nguoi choi %c, chon o (1-9): ", currentPlayer);
        scanf("%d", &position);

        if (position < 1 || position > 9 || !markboard(position, currentPlayer)) {
            printf("Khong hơp le! Hay chon lailai.\n");
            continue;
        }

        turnCount++;
        char winner = checkwinner();

        if (winner != ' ') {
            drawboard();
            printf("Nguoi choi %c thangthang!\n", winner);
            break;
        } else if (turnCount == 9) {
            drawboard();
            printf("HoaHoa!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
    }

    return 0;
}

// Hàm vẽ bảng tic tac toetoe
void drawboard(){
    printf("\n");
    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
           printf(" %c ", board[i][j]);
           if(j<2) printf("|");
        }
        printf("\n");
        if (i<2) printf("---+---+---\n");
    }
}
// Hàm đánh dấu x or o lên bảng 
int markboard(int position, char mark) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        return 0; 
    }

    board[row][col] = mark;
    return 1;
}

char checkwinner() {
  
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0]; // Hàng ngang
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i]; // Hàng dọc
    }

    // Kiểm tra đường chéo
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    return ' '; 
}

