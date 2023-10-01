#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 10마리의 서로 다른 동물 (각 카드 2장씩)
// 사용자로부터 2개의 입력값을 받아서 같은 동물 카드 찾으면 카드 뒤집기
// 모든 동물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5]; // 카드 20장
char * strAnimal[10];
void initAnimalArray();
void initAnimalName();
int conv_pos_x(int pos);
int conv_pos_y(int pos);

int main(void) {
    srand(time(NULL));

    initAnimalArray();
    initAnimalName();

    shuffleAnimal();

    int failCount = 0; // 실패 횟수 출력용

    while (1)
    {
        int select1;
        int select2;

        printAnimals(); // 동물 위치 출력
        printQuestion(); // 문제 출력 (카드 지도)
        scanf("%d %d", select1, select2);



    }
    

    return 0;
}

void initAnimalArray(){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName() {
    strAnimal[0] = "가";
    strAnimal[1] = "나";
    strAnimal[2] = "다";
    strAnimal[3] = "라";
    strAnimal[4] = "마";

    strAnimal[5] = "바";
    strAnimal[6] = "사";
    strAnimal[7] = "아";
    strAnimal[8] = "자";
    strAnimal[9] = "차";

}

void shuffleAnimal() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);

            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition() {
    while (1)
    {
        int randPos = rand() % 20; // 0 ~ 19 사이의 숫자 반환
        // 19 -> (3,4)
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if (arrayAnimal[x][y] == -1) 
        {
            return randPos;
        }
        return 0;
    }
    
}

int conv_pos_x(int pos) {
    // 19 -> (3,4)
    return pos / 5;
}

int conv_pos_y(int pos) {
    // 19 -> (3,4)
    return pos % 5;
}

void printAnimals() {
    printf("\n================정답================\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++)
        {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
    }
    printf("\n================================\n");
}

void printQuestion() {
    
}