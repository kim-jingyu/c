#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
물고기가 6마리가 있다.
사막의 더운 날씨 탓에 물이 아주 빨리 증발한다.
물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주자.
물고기를 키워서 먹는다.
*/

int level;
int arrayFish[6];
int *cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main(void) {
    long startTime = 0;
    long totalElapsedTime = 0;
    long prevElapsedTime = 0; // 직전 경과 시간

    int input; // 몇 번 어항에 물을 줄 것인가
    initData();

    cursor = arrayFish;

    startTime = clock(); // 현재 시간을 milli second 단위 (1000분의 1초)로 나타냄
    printf("startTime = %ld\n", startTime);
    while (1)
    {
        printFishes(); // 물고기 어항 상태 보여주기
        printf("몇번 어항에 물을 주시겠어요? ");
        scanf("%d", &input);

        // 입력값 체크
        if (input < 1 || input > 6)
        {
            printf("\n입력값이 잘못 되었습니다.\n");
            continue;
        }
        
        // 총 경과 시간
        printf("clock() = %ld\n", clock());

        totalElapsedTime = (clock() - startTime) / 100;
        printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

        // 마지막으로 물 준 시간 이후로 흐른 시간
        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

        // 증발
        decreaseWater(prevElapsedTime);

        // 사용자가 입력한 어항에 물을 준다.
        
        // 어항의 물이 0이면, 물을 주지 않는다.
        if (cursor[input - 1] <= 0)
        {
            printf("%d번 물고기는 이미 죽었습니다. 물을 주지 않습니다.\n", input);
        }
        
        // 어항의 물이 0이 아닌경우, 물을 준다. 단, 100을 넘지 않는지 체크한다.
        else if (cursor[input - 1] < 100)
        {
            // 물을 준다.
            printf("%d번 어항에 물을 준다.\n\n", input);
            cursor[input - 1]++;
        }

        // 레벨업은 20초마다 한번씩 수행한다.
        if (totalElapsedTime / 20 > level - 1)
        {
            level++;
            printf("레벨업!! 기존 %d 레벨 -> %d 레벨로 업그레이드!!\n\n", level - 1, level);

            if (level == 5){
                printf("\n\n 축하합니다. 최고 레벨에 달성하였습니다.");
                break;
            }
        }

        // 모든 물고기가 죽었는지 확인
        if (checkFishAlive() == 0)
        {
            /* code */
            printf("모든 물고기가 모두 죽었습니다.\n");
        } else {
            printf("물고기가 아직 살아있어요!\n");
        }
        prevElapsedTime = totalElapsedTime;
    }
    

    return 0;
}

void initData() {
    level = 1; // (1 ~ 5)
    for (int i = 0; i < 6; i++){
        arrayFish[i] = 100;
    }
}

void printFishes() {
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번 \n", 1,2,3,4,5,6);
    for (int i = 0; i < 6; i++)
    {
        printf(" %4d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime) {
    for (int i = 0; i < 6; i++)
    {
        arrayFish[i] -= (level * 3 * (int)elapsedTime); // 증발
        if (arrayFish[i] < 0)
        {
            arrayFish[i] = 0;
        }
        
    }
    
}

int checkFishAlive() {
    for (int i = 0; i < 6; i++)
    {
        if (arrayFish[i] > 0)
        {
            return 1;
        }
    }
    return 0;
}