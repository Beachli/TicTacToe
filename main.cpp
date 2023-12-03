#include <raylib.h>
#include <string>

#define COLS 3 //Columns in our grid
#define ROWS 3 //Rows in our grid
const int screenHeight = 400;
const int screenWidth = 400;
const int tileWidth = screenWidth / COLS; //Tile width and height are the window width/height divded by the amount of columns
const int tileHeight = screenHeight / ROWS;

enum TileState {X, O, EMPTY}; //Possible states for a tile

class Tile {
  public:
    int x;
    int y;
    TileState state;
};
Tile board[COLS][ROWS]; //Creates the board in the memory out of an array of Tile objects
void DrawTile(Tile); //Function for drawing the graphical representation of tiles

int main() {
  InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe");
  SetWindowState(FLAG_VSYNC_HINT); //Enables VSYNC

  TileState currentTurn = X;


  //Very ugly nested loop which sets the tiles on the board
  for (int x = 0; x < COLS; x++) { //X represents the COLS on board
    for (int y = 0; y < ROWS; y++) { //Y represents the ROWS on board
      board[x][y] = (Tile){.x = x, .y = y, .state = EMPTY}; //Set the x, y and state values of the tile object on x,y
    }
  }

  while (!WindowShouldClose()) { //While the window is open
    const char *turnIndicator = nullptr; //Turn indicator text

    switch (currentTurn) { //Switch statement to set turnIndicator
      case X:
        turnIndicator = "Player X";
        break;
      case O:
        turnIndicator = "Player O";
        break;
      default:
        printf("currentTurn is either NULL or EMPTY");
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) { //When the left mouse button is pressed
      Vector2 mousePos = GetMousePosition(); 
      int x = mousePos.x / tileWidth; //This math finds the x and y values (on the board) of the tile clicked
      int y = mousePos.y / tileHeight;

      if (board[x][y].state == EMPTY) { //If the tile clicked is empty
        board[x][y].state = currentTurn; //Set the state to the current player's turn (X/O)
        
        switch (currentTurn) { 
          case X: //If it's player X's turn, set currentTurn to O
            printf("%i,%i is X\n", x, y);
            currentTurn = O;
            break;
          case O: //If it's player O's turn, set currentTurn to X
            printf("%i,%i is O\n", x, y);
            currentTurn = X;
            break;
          default:
            printf("An error occurred\n");
        }

      }
    }

    BeginDrawing();
      ClearBackground(WHITE);

      //Another very ugly nested loop which draws the board
      for (int x = 0; x < COLS; x++) { //Horizontal indices
        for (int y = 0; y < ROWS; y++) { //Vertical indices
          DrawTile(board[x][y]);
          switch (board[x][y].state) { //Decides what it should draw in the tile
            case X:
              DrawText("X", x * tileWidth + tileWidth / 4, y * tileHeight + tileHeight / 8, tileHeight - 20, BLACK);
              break;
            case O: 
              DrawText("O", x * tileWidth + tileWidth / 4, y * tileHeight + tileHeight / 8, tileHeight - 20, BLACK);
              break;
            case EMPTY:
              break;
          }

          int turnIndicatorWidth = MeasureText(turnIndicator, 20);
          DrawText(turnIndicator, GetScreenWidth() / 2 - turnIndicatorWidth / 2, 5, 20, RED);
        }
      }

    EndDrawing();
  }

  return 0;
}

void DrawTile(Tile tile) {
  //Draw a hollow rectangle using math i don't understand to set position
  DrawRectangleLines(tile.x * tileWidth, tile.y * tileHeight, tileWidth, tileHeight, BLACK); 
}