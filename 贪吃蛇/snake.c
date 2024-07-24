#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // 使用getch()函数，该头文件在Windows下可用

#define WIDTH 20
#define HEIGHT 10

int gameOver;
int score;
int headX, headY;
int fruitX, fruitY;
int tailX[100], tailY[100];
int nTail;

enum Direction {
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum Direction dir;

void setup() {
    gameOver = 0;
    score = 0;
    headX = WIDTH / 2;
    headY = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    dir = STOP;
}

void draw() {
    system("cls");  // 清屏，Windows下使用

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");

            if (i == headY && j == headX)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else {
                int isTail = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        isTail = 1;
                    }
                }
                if (!isTail)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score:%d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }
}

void algorithm() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = headX;
    tailY[0] = headY;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            headX--;
            break;
        case RIGHT:
            headX++;
            break;
        case UP:
            headY--;
            break;
        case DOWN:
            headY++;
            break;
    }

    // Check for collision with walls
    if (headX < 0 || headX >= WIDTH || headY < 0 || headY >= HEIGHT)
        gameOver = 1;

    // Check for collision with self
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == headX && tailY[i] == headY)
            gameOver = 1;
    }

    // Check for collision with fruit
    if (headX == fruitX && headY == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        
        input();
        algorithm();
    }

    printf("Game Over! Your score is %d\n", score);

    return 0;
}
