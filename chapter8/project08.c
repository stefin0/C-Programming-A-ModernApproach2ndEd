/*
Modify Programming Project 7 so that it prompts for five quiz grades for each of
five students, then computes the total score and average score for each
student, and the average score, high score, and low score for each quiz.
*/
#include <stdio.h>

#define STUDENTS 5
#define QUIZZES 5

int main(void) {
  int grades[STUDENTS][QUIZZES] = {0};
  float student_total_scores[STUDENTS] = {0};
  float quiz_total_scores[QUIZZES] = {0};
  int quiz_high_scores[QUIZZES], quiz_low_scores[QUIZZES];

  // Input grades for each student
  for (int student = 0; student < STUDENTS; student++) {
    printf("Enter grades for student %d: ", student + 1);
    for (int j = 0; j < STUDENTS; j++) {
      scanf("%d", &grades[student][j]);
    }
  }

  // Initialize high and low scores for each quiz.
  for (int quiz = 0; quiz < QUIZZES; quiz++) {
    quiz_high_scores[quiz] = grades[0][quiz];
    quiz_low_scores[quiz] = grades[0][quiz];
  }

  // Sum all scores for each student, and all scores for each quiz
  for (int student = 0; student < STUDENTS; student++) {
    for (int quiz = 0; quiz < QUIZZES; quiz++) {
      student_total_scores[student] += grades[student][quiz];
      quiz_total_scores[quiz] += grades[student][quiz];

      // Determine highest and lowest score for each quiz
      if (grades[student][quiz] > quiz_high_scores[quiz]) {
        quiz_high_scores[quiz] = grades[student][quiz];
      }
      if (grades[student][quiz] < quiz_low_scores[quiz]) {
        quiz_low_scores[quiz] = grades[student][quiz];
      }
    }
  }

  for (int student = 0; student < STUDENTS; student++) {
    int student_num = student + 1;
    printf("\nTotal score for student %d: %.0f", student_num, student_total_scores[student]);
    printf("\nAverage score for student %d: %.2f\n", student_num,
           student_total_scores[student] / QUIZZES);
  }

  for (int quiz = 0; quiz < QUIZZES; quiz++) {
    int quiz_num = quiz + 1;
    printf("\nAverage score for quiz %d: %.2f", quiz_num,
           quiz_total_scores[quiz] / STUDENTS);
    printf("\nHigh score for quiz %d: %d", quiz_num, quiz_high_scores[quiz]);
    printf("\nLow score for quiz %d: %d\n", quiz_num, quiz_low_scores[quiz]);
  }

  return 0;
}
