#include <raylib.h>
#include <string>

int main() {
  InitWindow(600, 600, "Tic-Tac-Toe");
  SetWindowState(FLAG_VSYNC_HINT);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(WHITE);
      
    EndDrawing();
  }
}