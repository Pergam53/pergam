#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define FIELD_HEIGTH 25
#define FIELD_LENGTH 80
#define SETKA_X 40
#define SCORE1_X 37
#define SCORE2_X 43
#define SCORE_Y 22
#define KEY1_X 5
#define KEY2_X 75


#define DRAWFIELD_DEBUG


void drawField(int key1_position, int key2_position, int ball_position_x, int ball_position_y, int score1, int score2) {
    int x = 0;
    int y = 0;
    system("cls");
    for (y = FIELD_HEIGTH; y > 0; y--){
        for (x = 0; x < FIELD_LENGTH; x++) {
            
            if ((y <= key1_position) && (y >= key1_position - 2) && x == KEY1_X) {
                    printf("|");
                } 
            else if ((y <= key2_position) && (y >= key2_position - 2) && x == KEY2_X){
                printf("|");
            }
            else if  (y == ball_position_y && x == ball_position_x){
                printf("o");
            }
            else if (y == SCORE_Y && x == SCORE1_X){
                printf ("%d", score1);
                if (score1 > 9)
                    x += 1;
            }
            else if (y == SCORE_Y && x == SCORE2_X){
                printf("%d", score2);
                if (score2 > 9)
                    x += 1;
            }
            else if (x == FIELD_LENGTH / 2){
                printf("|");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
        
    }


    
    return;
}  

int keyMoving(int key_position, char click){    
    if ((click == 'a' || click == 'k') && key_position < FIELD_HEIGTH){
        return key_position + 1;
    }
    else if ((click == 'z' || click == 'm') && key_position > 3){
        return key_position - 1;
    }
    else {
        return key_position;
    }
    /*if (click == 'k' && key2_position < FIELD_HEIGTH){
        return key2_position + 1;
    }
    else if (click == 'm' && key2_position > 2){
        return key2_position - 1;
    }
    else {
        return key2_position;
    } */   

}
int main() {
    int key1_position = 10;
    int key2_position = 24;
    char click;
#ifdef DRAWFIELD_DEBUG 
    drawField(key1_position, key2_position, 56, 12, 7, 12);
    printf("pole(10, 20, 56, 12, 7, 12);\n");
    while (1){
    click = _getch();
    if (click == 'a' || click == 'z'){
    key1_position = keyMoving(key1_position, click);
    }
    else if (click == 'k' || click == 'm'){ 
    key2_position = keyMoving(key2_position, click);
    }
    //getchar();
    drawField(key1_position, key2_position, 56, 12, 0, 0);
    //printf("pole(24, 7, 43, 8, 1, 17);\n");
    char stopGame = 'q';
    if (click == stopGame)
    break;
    }
    
    
   /* drawField(1, 13, 24, 10, 20, 19);
    printf("pole(1, 13, 24, 10, 20, 19);\n");
    getchar(); */ 
#endif

    return 0;
}