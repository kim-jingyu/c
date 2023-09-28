#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));
    printf("=== 아빠는 대머리 게임 ===\n\n");

    int input;
    int treatment = rand() % 4; // 발모제 번호

    int cntShowBottle = 0;
    int prevCntShowBottle = 0;

    // 3번의 기회
    for (int i = 0; i < 3; i++)
    {
        printf("%d번째 시도입니다.", i + 1);
        int bottle[4] = {0, 0, 0, 0};

        do
        {
            cntShowBottle = rand() % 2 + 2; // 보여줄 병의 개수 ( 2, 3 )
        } while (cntShowBottle == prevCntShowBottle);
        prevCntShowBottle = cntShowBottle;

        int is_included = 0;

        // 보여줄 병 종류를 선택한다.
        for (int j = 0; j < cntShowBottle; j++)
        {
            int randBottle = rand() % 4;

            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;
                if (randBottle == treatment)
                {
                    is_included = 1;
                }
            }
            else
            {
                j--;
            }
        }

        // 사용자에게 문제 표시
        for (int k = 0; k < 4; k++)
        {
            if (bottle[k] == 1)
            {
                printf("%d ", k + 1);
            }
        }
        printf("물약을 머리에 바릅니다\n\n");

        if (is_included == 1)
        {
            printf(" 성공! 머리가 났어요! \n");
        }
        else
        {
            printf(" 실패! 머리가 나지 않았어요! \n");
        }

        printf("\n계속 하려면 아무버튼이나 누르세요...");
        getchar();
    }

    printf("\n\n발모제는 몇 번일까요?");
    scanf("%d", &input);

    if (input == treatment + 1)
    {
        printf("\n 정답입니다! \n");
    }
    else
    {
        printf("\n 땡! 틀렸습니다. 정답은 %d입니다.\n", treatment + 1);
    }

    return 0;
}