#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5

struct Student {
    char name[50];
    float scores[MAX_SUBJECTS];
    float average;
};

void inputStudentData(struct Student students[], int *numStudents, int numSubjects) {
    printf("Enter number of students: ");
    scanf("%d", numStudents);

    for (int i = 0; i < *numStudents; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        float total = 0;
        for (int j = 0; j < numSubjects; j++) {
            printf("Enter score for Subject %d: ", j + 1);
            scanf("%f", &students[i].scores[j]);
            total += students[i].scores[j];
        }

        students[i].average = total / numSubjects;
    }
}

void displayResults(struct Student students[], int numStudents, int numSubjects) {
    printf("\n%-20s", "Name");
    for (int j = 0; j < numSubjects; j++) {
        printf("Subject%d  ", j + 1);
    }
    printf("Average\n");

    for (int i = 0; i < numStudents; i++) {
        printf("%-20s", students[i].name);
        for (int j = 0; j < numSubjects; j++) {
            printf("%8.2f  ", students[i].scores[j]);
        }
        printf("%8.2f\n", students[i].average);
    }
}

void findHighestLowest(struct Student students[], int numStudents, int numSubjects) {
    float highest = 0, lowest = 100;
    char highestName[50], lowestName[50];

    for (int i = 0; i < numStudents; i++) {
        if (students[i].average > highest) {
            highest = students[i].average;
            strcpy(highestName, students[i].name);
        }
        if (students[i].average < lowest) {
            lowest = students[i].average;
            strcpy(lowestName, students[i].name);
        }
    }

    printf("\nHighest Scorer: %s with %.2f\n", highestName, highest);
    printf("Lowest Scorer: %s with %.2f\n", lowestName, lowest);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, numSubjects;

    printf("Enter number of subjects: ");
    scanf("%d", &numSubjects);

    if (numSubjects > MAX_SUBJECTS) {
        printf("Maximum number of subjects allowed is %d.\n", MAX_SUBJECTS);
        return 1;
    }

    inputStudentData(students, &numStudents, numSubjects);
    displayResults(students, numStudents, numSubjects);
    findHighestLowest(students, numStudents, numSubjects);

    return 0;
}
