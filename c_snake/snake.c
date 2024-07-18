#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    RIGHT = 0,
    UP = 1,
    LEFT = 2,
    DOWN = 3
} direction;

int windowWidth = 96;
int windowHeight = 36;

int headX = 0;
int headY = 0;
int bodyX, bodyY;
int snakeSize = 5;
direction dir = 0;

int foodX, foodY;

void main()
{
    WINDOW* win = initscr();
    keypad(win, true);
    nodelay(win, true);
    
    foodX = rand() % windowWidth;
    foodY = rand() % windowHeight;

    while(true)
    {
        int pressed = wgetch(win);

        switch(pressed)
        {
        case KEY_RIGHT:
            if(dir != RIGHT && dir != LEFT)
            {
                dir = RIGHT;
            }
            break;
        case KEY_UP:
            if(dir != UP && dir != DOWN)
            {
                dir = UP;
            }
            break;
        case KEY_LEFT:
            if(dir != LEFT && dir != RIGHT)
            {
                dir = LEFT;
            }
            break;
        case KEY_DOWN:
            if(dir != DOWN && dir != UP)
            {
                dir = DOWN;
            }
            break;
        }

        erase();
        
        for(int i = 0; i < snakeSize; i++)
        {
            if(i == 0) mvaddstr(headY, headX, "o");
            else {
                switch(dir)
                {
                case LEFT:
                    bodyX = headX + i;
                    bodyY = headY;
                    break;
                case RIGHT:
                    bodyX = headX - i;
                    bodyY = headY;
                    break;
                case UP:
                    bodyX = headX;
                    bodyY = headY + i;
                    break;
                case DOWN:
                    bodyX = headX;
                    bodyY = headY - i;
                    break;
                }
            mvaddstr(bodyY, bodyX, "#");
            }
        }

        mvaddstr(foodY, foodX, ";");

        if(dir == LEFT ) headX -= 1;
        else if(dir == RIGHT) headX += 1;
        else if(dir == UP) headY -= 1;
        else if(dir == DOWN) headY += 1;
        
        if(foodX == headX && foodY == headY)
        {
            foodX = rand() % windowWidth;
            foodY = rand() % windowHeight;
            snakeSize++;
        }

        usleep(100000);
    }

    endwin();
}

