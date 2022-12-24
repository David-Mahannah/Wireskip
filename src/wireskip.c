#include <curses.h>

#define ENTER_KEY 3

int main(int argc, char ** argv)
{
  // Parse address and port
  char msg_2_send [512];
  tid id = pthread_create();
  if (id == 0) {
    while(1) {
      setupScreen(); 
      paintScreen();

      char c = handleInput();
      if (c == ENTER_KEY) {
        sockSend(buffer);
      } else {
        msg_2_send[idx++] = c;
      }
    }
    // DONE
  }
  else if (id == 1)
  {
    while(1)
    {
      read(sock, 512);
    }
  } 
}

void setupScreen()
{
  #ifdef XCURSES
     xinitscr(argc, argv);
  #else
     initscr();
  #endif

  nodelay(stdscr, TRUE);
  noecho();
  nonl();
  refresh();
  
  #ifdef A_COLOR
    if (has_colors())
      start_color();
  #endif

  curs_set(0);
}

void paintScreen()
{

}

void sockHandler()
{

}

