#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 난이도 설정을 위한 enum 정의
enum Difficulty
{
    EASY = 1,
    MEDIUM,
    HARD
};

int main()
{
    int answer, guess, attempts = 0;
    int playAgain;
    enum Difficulty difficulty;
    int maxNumber = 100;       // 기본 숫자 범위
    int bestScore = -1;        // 최고 점수 (초기값: 기록 없음)
    const int TIME_LIMIT = 30; // 시간 제한 (초)
    time_t startTime, currentTime;

    // 랜덤 숫자 생성을 위한 시드 초기화
    srand(time(NULL));

    do
    {
        // 난이도 선택
        printf("숫자 맞추기 게임에 오신 것을 환영합니다!\n");
        printf("난이도를 선택하세요:\n");
        printf("1. 쉬움 (1 ~ 100)\n");
        printf("2. 중간 (1 ~ 1000)\n");
        printf("3. 어려움 (1 ~ 10000)\n");
        printf("선택: ");
        scanf("%d", &difficulty);

        // 난이도에 따른 숫자 범위 설정
        switch (difficulty)
        {
        case EASY:
            maxNumber = 100;
            break;
        case MEDIUM:
            maxNumber = 1000;
            break;
        case HARD:
            maxNumber = 10000;
            break;
        default:
            printf("잘못된 선택입니다. 기본 난이도(쉬움)로 진행합니다.\n");
            maxNumber = 100;
        }

        // 랜덤 숫자 생성
        answer = rand() % maxNumber + 1;
        printf("정답: %d\n", answer); // 디버깅용 출력 (배포 시 제거)
        attempts = 0;                 // 시도 횟수 초기화

        printf("1부터 %d 사이의 숫자를 맞춰보세요. 시간 제한: %d초\n", maxNumber, TIME_LIMIT);

        // 게임 시작 시간 기록
        startTime = time(NULL);

        while (1)
        {
            // 현재 시간 확인
            currentTime = time(NULL);
            if (currentTime - startTime > TIME_LIMIT)
            {
                printf("\n시간 초과! 정답을 맞히지 못했습니다. 정답은 %d였습니다.\n", answer);
                break;
            }

            printf("숫자를 입력하세요 (남은 시간: %ld초): ", TIME_LIMIT - (currentTime - startTime));
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
                // 최고 점수 업데이트
                if (bestScore == -1 || attempts < bestScore)
                {
                    bestScore = attempts;
                    printf("축하합니다! 새로운 최고 점수: %d번\n", bestScore);
                }
                else
                {
                    printf("최고 점수: %d번\n", bestScore);
                }
                break;
            }
        }

        // 시간 초과 시 재시작 여부 확인
        if (currentTime - startTime > TIME_LIMIT)
        {
            printf("게임을 다시 하시겠습니까? (Y: 1/N: 2): ");
        }
        else
        {
            printf("게임을 다시 하시겠습니까? (Y: 1/N: 2): ");
        }
        scanf("%d", &playAgain);

    } while (playAgain == 1);

    printf("게임을 종료합니다. 감사합니다!\n");

    return 0;
}