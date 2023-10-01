#include <stdio.h>

struct GameInfo
{
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; // 연관업체 게임
};

typedef struct GameInformation
{
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; // 연관업체 게임
} GAME_INFO;

typedef struct
{
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; // 연관업체 게임
} GAME_INFO2;

int main(void) {
    struct GameInfo gameInfo1;
    gameInfo1.name = "배그";
    gameInfo1.year = 2020;

    struct GameInfo gameInfo2 = {"게임",2020,10000,"소니"};

    // 구조체 배열
    struct GameInfo gameArray[2] = {
        {"게임",2020,10000,"소니"},
        {"피파",1920,3000,"이스포츠"}
    };

    // 구조체 포인터
    struct GameInfo * gamePtr;
    gamePtr = &gameInfo1;
    printf("게임명 : %s\n", (*gamePtr).name);
    printf("발매년도 : %d\n", gamePtr -> year);

    // 구조체 안의 구조체
    gameInfo1.friendGame = &gameInfo2;
    printf("게임명 : %s\n", gameInfo1.friendGame -> name);
    printf("발매년도 : %d\n", gameInfo1.friendGame -> year);

    // typedef : 자료형에 별명 지정
    typedef int 정수;
    정수 정수변수 = 3; // int i = 3;
    printf("%d", 정수변수);

    typedef struct GameInfo 게임정보;
    게임정보 game1;
    game1.name;

    GAME_INFO game2;
    game2.name = "한글 게임2";

    return 0;
}