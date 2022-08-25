import java.io.*;
import java.util.*;

class ValidSudoku {
    public boolean validSudoku(char[][] board) {
         for (int i=0; i<board[0].length; i++) {
      boolean checkRow[] = new boolean[9];
      boolean checkCol[] = new boolean[9];

      for (int j=0; j<board.length; j++) {
         if (board[i][j] != '.') {
            //check row
            if (checkRow[board[i][j] - '1']) {
               return false;
            }
            else {
               checkRow[board[i][j] - '1'] = true;
            }
         }

         if (board[j][i] != '.') {
            //check col
            if (checkCol[board[j][i] - '1']) {
               return false;
            }
            else {
               checkCol[board[j][i] - '1'] = true;
            }
         }
      }
   }
   
   for (int i=0; i<board[0].length; i+=3) {
      for (int j=0; j<board.length; j+=3) {
         boolean check3x3[] = new boolean[9];
         for (int k=i; k<i+3; k++) {
            for (int l=j; l<j+3; l++) {
               if (board[k][l] == '.') continue;
               
               if (check3x3[board[k][l] - '1']) {
                  return false;
               }
               else {
                  check3x3[board[k][l] - '1'] = true;
               }
            }
         }
      }
   }
   
   return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char board[][] = new char[9][9];
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
                board[i][j] = scanner.next().charAt(0);
            }
        }
        scanner.close();
        boolean result = new ValidSudoku().validSudoku(board);
        System.out.println(result);
    }
}