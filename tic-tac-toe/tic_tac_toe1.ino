#include <LiquidCrystal.h>
#include <Keypad.h>

// LCD Pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {A4, A5, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Game variables
char board[3][3];
bool playerTurn = true; // true = X, false = O
bool gameOver = false;
int currentPage = 0; // 0 = top+middle, 1 = middle+bottom

void setup() {
  lcd.begin(16, 2);
  resetBoard();
  lcd.print("Tic-Tac-Toe");
  delay(1500);
  lcd.clear();
  lcd.print("Use # to toggle");
  delay(1500);
  lcd.clear();
  displayPage();
}

void loop() {
  char key = keypad.getKey();

  if (key == '*') {
    resetBoard();
    lcd.clear();
    lcd.print("New Game!");
    delay(800);
    displayPage();
    return;
  }

  if (key == '#' && !gameOver) {
    currentPage = (currentPage + 1) % 2; // Toggle page
    displayPage();
    return;
  }

  if (gameOver || key < '1' || key > '9') return;

  int pos = key - '1';
  int row = pos / 3;
  int col = pos % 3;

  if (board[row][col] == ' ') {
    board[row][col] = playerTurn ? 'X' : 'O';
    displayPage();

    if (checkWin()) {
      lcd.setCursor(0, 1);
      lcd.print(playerTurn ? "X wins! * to reset" : "O wins! * to reset");
      gameOver = true;
    } else if (checkDraw()) {
      lcd.setCursor(0, 1);
      lcd.print("Draw! * to reset");
      gameOver = true;
    } else {
      playerTurn = !playerTurn;
    }
  }
}

void resetBoard() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      board[i][j] = ' ';

  playerTurn = true;
  gameOver = false;
  currentPage = 0;
  lcd.clear();
}

void displayPage() {
  lcd.clear();

  if (currentPage == 0) {
    // Top and middle rows
    lcd.setCursor(0, 0);
    printRow(0);
    lcd.setCursor(0, 1);
    printRow(1);
  } else {
    // Middle and bottom rows
    lcd.setCursor(0, 0);
    printRow(1);
    lcd.setCursor(0, 1);
    printRow(2);
  }
}

void printRow(int r) {
  for (int i = 0; i < 3; i++) {
    lcd.print(board[r][i]);
    if (i < 2) lcd.print("|");
  }
}

bool checkWin() {
  char p = playerTurn ? 'X' : 'O';
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) ||
        (board[0][i] == p && board[1][i] == p && board[2][i] == p))
      return true;
  }
  if ((board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
      (board[0][2] == p && board[1][1] == p && board[2][0] == p))
    return true;

  return false;
}

bool checkDraw() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i][j] == ' ') return false;
  return true;
}