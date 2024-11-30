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
#define INVERT_Y 1
#define INVERT_X 1


#define DRAWFIELD_DEBUG


void drawField(int key1_position, int key2_position, int ball_position_x, int ball_position_y, int score1, int score2) {
    int x = 0;
    int y = 0;      //инициализируем переменные
    system("cls");
    for (y = FIELD_HEIGTH; y > 0; y--){         //запускаем цикл по оси у
        for (x = 0; x < FIELD_LENGTH; x++) {        //запускаем вложенный цикл по оси х
            
            if ((y <= key1_position) && (y >= key1_position - 2) && x == KEY1_X) {
                    printf("|");
                } 
            else if ((y <= key2_position) && (y >= key2_position - 2) && x == KEY2_X){
                printf("|");                                                                //отрисовываем ракетки
            }
            else if  (y == ball_position_y && x == ball_position_x){
                printf("o");                                                        //отрисовываем мячик
            }
            else if (y == SCORE_Y && x == SCORE1_X){
                printf ("%d", score1);
                if (score1 > 9)
                    x += 1;                                         //создаем условие для двузначного счета, чтобы основное поле не выходило за рамки
            }
            else if (y == SCORE_Y && x == SCORE2_X){
                printf("%d", score2);
                if (score2 > 9)
                    x += 1;
            }
            else if (x == FIELD_LENGTH / 2){
                printf("|");                                        //отрисовка сетки
            }
            else {
                printf(".");                                    //основное пространство поля
            }
        }
        printf("\n");
        
    }


    
    return;
}  

int getKeyPosition(int key_position, char click){                           //функия расчета перемещения ракетки
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


//Человек
struct pare                         //структура
{
    int x, y;

};



struct pare getBallPosition(int ballPosition_X, int ballPosition_Y, int key1_position, int key2_position, struct pare fr) {             //функция изменения вектора движения мяча
    
    if (ballPosition_Y == FIELD_HEIGTH || ballPosition_Y == 1)
            fr.y = fr.y * -1;
    if ((ballPosition_X == KEY1_X + 1 && (ballPosition_Y > key1_position - 3 && ballPosition_Y <= key1_position)) || (ballPosition_X == KEY2_X - 1 && (ballPosition_Y > key2_position - 3 && ballPosition_Y <= key2_position)))
            fr.x = fr.x * -1; 
    /*if ((fr.x == 1 && fr.y == 1) && (ballPosition_Y == key2_position - 2)){
        fr.x *= -1;
        fr.y *= -1;
    }
    if ((fr.x == 1 && fr.y == 1) && (ballPosition_Y == key)) */
            return fr;
}

/*struct pare newBattle(struct pare goal, int ballPosition_X, int ballPosition_Y) {
    if (ballPosition_X < KEY1_X)
        ballPosition_X == 40;
        ballPosition_Y == 13;
    if (ballPosition_X > KEY2_X)
        sc.y ++;
        return sc;
}*/

int main() {
    int key1_position = 10;
    int key2_position = 24;
    char click;
    int ballPosition_X = 40;
    int ballPosition_Y = 13;
    
    //Вова
    struct pare vector;
    //Паша
    //struct pare pasha;
    //Если вове выкололи глаз, Паша - со здоровыми глазами


    struct pare score;
    score.x = 0;
    score.y = 0;

    vector.x = 1;
    vector.y = 1;

#ifdef DRAWFIELD_DEBUG 
    drawField(key1_position, key2_position, ballPosition_X, ballPosition_Y, score.x, score.y);
    printf("pole(10, 20, 56, 12, 7, 12);\n");
    while (1){
        click = _getch();
        if (click == 'a' || click == 'z'){
            key1_position = getKeyPosition(key1_position, click);
        }
        else if (click == 'k' || click == 'm'){ 
            key2_position = getKeyPosition(key2_position, click);
        }
        /*
        pasha = getBallPosition(ballPosition_X, ballPosition_Y, key1_position, key2_position);
        ballPosition_X = ballPosition_X + vector.x;
        ballPosition_Y = ballPosition_Y + vector.y;

        Значения сохранили в pasha, vector - не инициализирован, выше - неправильно.
        Структур - тип, который описывает что внутри. vector и pasha - конкретные обьекты, со своим x и y.
        */
        
        vector = getBallPosition(ballPosition_X, ballPosition_Y, key1_position, key2_position, vector);             //тут мы записываем значение работы функции
        ballPosition_X = ballPosition_X + vector.x;
        ballPosition_Y = ballPosition_Y + vector.y;

    if (ballPosition_X < 1){                                //todo: function
        score.y ++;
        ballPosition_X = 40;
        ballPosition_Y = 13;
        vector.x = 1;
        vector.y = 1;
        }
    else if (ballPosition_X > FIELD_LENGTH){
             score.x ++;
             ballPosition_X = 40;
        ballPosition_Y = 13;
        vector.x = -1;
        vector.y = 1;
    }
         drawField(key1_position, key2_position, ballPosition_X, ballPosition_Y, score.x, score.y);
        
   


                 //тут мы просто вызываем результат работы функции, подставляя нужные переменные
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