#include <raylib.h>
#include <string>


#define COLS 3
#define ROWS 3

const int screenHeight = 400;
const int screenWidth = 400;
const int cellWidth = GetScreenWidth() / COLS;
const int cellHeight = GetScreenHeight() / ROWS;

char board[3][3];

int main() {
  InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe");
  SetWindowState(FLAG_VSYNC_HINT);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(WHITE);
      
      for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
          DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
        }
      }

    EndDrawing();
  }
}