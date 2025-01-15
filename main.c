#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer, guess, attempts = 0;
    int playAgain;
    // 랜덤 숫자 생성을 위한 시드 초기화
    srand(time(NULL));
    do
    {
        // 1부터 100 사이의 랜덤 숫자 생성
        answer = rand() % 100 + 1;
        attempts = 0; // 시도 횟수 초기화

        printf("숫자 맞추기 게임에 오신 것을 환영합니다!\n");
        printf("1부터 100 사이의 숫자를 맞춰보세요.\n");

        while (1)
        {
            printf("숫자를 입력하세요: ");
            scanf("%d", &guess);

            ++attempts;

            if (guess > answer)
            {
                printf("숫자가 너무 커요. 낮춰주세요.\n");
            }
            else if (guess < answer)
            {
                printf("숫자가 너무 작아요. 높혀주세요.\n");
            }
            else
            {
                printf("정답입니다! 시도 횟수: %d번\n", attempts);
                break;
            }
        }
        // 재시작 여부 확인
        printf("게임을 다시 하시겠습니까? (Y: 1/N: 2): ");
        scanf("%d", &playAgain);

    } while (playAgain == 1);

    printf("게임을 종료합니다. 감사합니다!\n");

    return 0;
}