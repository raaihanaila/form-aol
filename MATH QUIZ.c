#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* structure to store score data */
struct Score {
    char name[30];
    int score;
};

/* function prototypes */
void playQuiz();
void saveScore(char name[], int score);
void readScore();
void sortScore(struct Score data[], int count);

int main() {
    int choice;

    do {
        printf("\n=== MATH QUIZ GAME ===\n");
        printf("1. Play Quiz\n");
        printf("2. View Scores\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                playQuiz();
                break;
            case 2:
                readScore();
                break;
            case 3:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);

    return 0;
}

/* function to start the math quiz */
void playQuiz() {
    int i, a, b, answer, userAnswer;
    int score = 0;
    char name[30];

    printf("\nEnter your name: ");
    scanf("%s", name);

    srand(time(NULL));

    for(i = 0; i < 5; i++) {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        answer = a + b;

        printf("Question %d: %d + %d = ", i+1, a, b);
        scanf("%d", &userAnswer);

        if(userAnswer == answer) {
            score += 20;
        }
    }

    printf("Your score: %d\n", score);
    saveScore(name, score);
}

/* function to save score into file */
void saveScore(char name[], int score) {
    FILE *fp;
    fp = fopen("score.txt", "a");

    if(fp != NULL) {
        fprintf(fp, "%s %d\n", name, score);
        fclose(fp);
    }
}

/* function to read score from file */
void readScore() {
    FILE *fp;
    struct Score data[100];
    int count = 0, i;

    fp = fopen("score.txt", "r");

    if(fp == NULL) {
        printf("No score data found.\n");
        return;
    }

    while(fscanf(fp, "%s %d", data[count].name, &data[count].score) != EOF) {
        count++;
    }
    fclose(fp);

    sortScore(data, count);

    printf("\n=== SCORE BOARD ===\n");
    for(i = 0; i < count; i++) {
        printf("%d. %s - %d\n", i+1, data[i].name, data[i].score);
    }
}

/* function to sort score descending */
void sortScore(struct Score data[], int count) {
    int i, j;
    struct Score temp;

    for(i = 0; i < count-1; i++) {
        for(j = i+1; j < count; j++) {
            if(data[i].score < data[j].score) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
