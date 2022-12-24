#include "curses.h"
#include <Winsock2.h>
#define ENTER_KEY 3

short color_table[] =
{
  COLOR_RED, COLOR_BLUE, COLOR_GREEN, COLOR_CYAN,
  COLOR_RED, COLOR_MAGENTA, COLOR_YELLOW, COLOR_WHITE
};


void upScreen()
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


int main(int argc, char ** argv)
{
  upScreen();

  // for (int i = 0; i < 8; i++)
  // {
  //   init_pair(i, color_table[i], COLOR_BLACK);
  // }

  while (getch() == ERR)
  {
    attrset(A_NORMAL);
    mvaddstr(3, 3, "Hello World");
    refresh();
  }

  // Parse address and port
  // char msg_2_send [512];
  // tid id = pthread_create();
  // if (id == 0) 
  // {
  //   while(1) 
  //   {
  //     setupScreen(); 
  //     paintScreen();

  //     char c = handleInput();
  //     if (c == ENTER_KEY) {
  //       sockSend(buffer);
  //     } else {
  //       msg_2_send[idx++] = c;
  //     }
  //   }
  //   // DONE
  // }
  // else if (id == 1)
  // {
  //   while(1)
  //   {
  //     read(sock, 512);
  //     add_safe_buffer();
  //   }
  // } 
}


// void paintScreen()
// {

// }

// void sockHandler()
// {

// }

