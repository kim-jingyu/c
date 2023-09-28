#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);

int main(void)
{
    // 문이 5개가있고, 각 문마다 점점 어려운 수식 퀴즈가 출제 (랜덤)
    // 맞히면 통과, 틀리면 실패

    srand(time(NULL));
    int count = 0;
    for (int i = 1; i <= 5; i++)
    {
        // x * y = ?
        int x = getRandomNumber(i);
        int y = getRandomNumber(i);
        int temp = -1;

        showQuestion(i, x, y);
        scanf("%d", &temp);

        if (temp == (x * y))
        {
            printf("\n정답입니다!\n");
            count++;
        }
        else if (temp == -1)
        {
            printf("\n종료합니다.\n");
            break;
        }
        else
        {
            printf("\n땡! 틀렸습니다.\n");
        }

        if (i == 5)
        {
            printf("\n총 %d번 맞췄습니다.\n", count);
        }
    }

    return 0;
}

int getRandomNumber(int level)
{
    return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
    printf("\n현재 level은 %d입니다.\n", level);
    printf("%d X %d = (종료: -1)", num1, num2);
}