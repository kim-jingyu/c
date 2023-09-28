#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // for (int i = 0; i < 5; i++)
    // {
    //     int temp = 5 - i - 1;

    //     for (int j = 0; j < temp; j++)
    //     {
    //         printf(" ");
    //     }

    //     for (int k = 0; k < i + 1; k++)
    //     {
    //         printf("*");
    //     }

    //     printf("\n");
    // }

    // 피라미드를 쌓아라
    // int floor;
    // printf("몇 층으로 쌓을까요? : ");
    // scanf("%d", &floor);

    // for (int i = 0; i < floor; i++)
    // {
    //     int temp = i * 2 + 1;

    //     for (int j = i; j < floor - 1; j++)
    //     {
    //         printf(" ");
    //     }

    //     for (int k = 0; k < temp; k++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // 가위 0, 바위 1, 보 2
    // srand(time(NULL));
    // int value = rand() % 3;

    // if (value == 0)
    // {
    //     printf("가위\n");
    // }
    // else if (value == 1)
    // {
    //     printf("바위\n");
    // }
    // else if (value == 2)
    // {
    //     printf("보\n");
    // }
    // else
    // {
    //     printf("모르는 값\n");
    // }

    // switch (value)
    // {
    // case 0:
    //     printf("가위\n");
    //     break;
    // case 1:
    //     printf("바위\n");
    //     break;
    // case 2:
    //     printf("보\n");
    //     break;
    // default:
    //     printf("모르는 값\n");
    //     break;
    // }

    // Up and Down

    srand(time(NULL));
    int answer = rand() % 100 + 1;
    printf("타켓 : %d\n", answer);

    int chance = 5;
    int temp = 0;

    while (1)
    {
        printf("남은 기회 %d 번\n", chance);

        if (chance == 0)
        {
            printf("모든 기회를 소진하였습니다.\n");
            break;
        }

        printf("숫자를 입력해주세요 : ");
        scanf("%d", &temp);

        if (temp > answer)
        {
            printf("Down👎 \n\n");
        }
        else if (temp < answer)
        {
            printf("Up👍 \n\n");
        }
        else
        {
            printf("정답입니다!\n");
            break;
        }

        chance--;
    }

    return 0;
}
