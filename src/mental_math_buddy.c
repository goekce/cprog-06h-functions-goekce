// Repetitively ask random arithmetics questions based on difficulty

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Difficulty { EASY = 1, MEDIUM = 2, HARD = 3, EXPERT = 4 };
constexpr int EASY_MIN_A = 12, EASY_MAX_A = 19;
constexpr int EASY_MIN_B = 3, EASY_MAX_B = 9;

constexpr int MEDIUM_MIN_A = 21, MEDIUM_MAX_A = 99;
constexpr int MEDIUM_MIN_B = 3, MEDIUM_MAX_B = 9;

constexpr int HARD_MIN_A = 12, HARD_MAX_A = 35;
constexpr int HARD_MIN_B = 12, HARD_MAX_B = 35;

constexpr int EXPERT_MIN_A = 51, EXPERT_MAX_A = 99;
constexpr int EXPERT_MIN_B = 11, EXPERT_MAX_B = 50;

int rand_int(int min, int max) {
  int total_count = max - min + 1;
  return rand() % total_count + min;
}

int multiplication_question(enum Difficulty difficulty) {
  int a, b;
  switch (difficulty) {
  case EASY:
    a = rand_int(EASY_MIN_A, EASY_MAX_A);
    b = rand_int(EASY_MIN_B, EASY_MAX_B);
    break;
  case MEDIUM:
    a = rand_int(MEDIUM_MIN_A, MEDIUM_MAX_A);
    b = rand_int(MEDIUM_MIN_B, MEDIUM_MAX_B);
    break;
  case HARD:
    a = rand_int(HARD_MIN_A, HARD_MAX_A);
    b = rand_int(HARD_MIN_B, HARD_MAX_B);
    break;
  case EXPERT:
    a = rand_int(EXPERT_MIN_A, EXPERT_MAX_A);
    b = rand_int(EXPERT_MIN_B, EXPERT_MAX_B);
    break;
  }
  printf("%d * %d ?\n", a, b);
  return a * b;
}

bool enteredIsCorrect(int expected, int entered) {
  if (expected != entered) {
    puts("No, please try again.");
    return false;
  }
  puts("Yes, very good job!");
  return true;
}

bool difficulty_is_valid(int prompt) {
  return EASY <= prompt && prompt <= EXPERT;
}

enum Difficulty prompt_difficulty() {
  puts("What difficulty would you like?\n"
       "  1) Easy\n"
       "  2) Medium\n"
       "  3) Hard\n"
       "  4) Expert\n");
  printf("Enter 1-4: ");
  enum Difficulty difficulty;
  scanf("%d", &difficulty);

  while (!difficulty_is_valid(difficulty)) {
    printf("Invalid input. Enter 1-4: ");
    scanf("%d", &difficulty);
  }

  return difficulty;
}

int main() {
  srand(time(nullptr));

  puts("Hi! I'm your arithmetic buddy.\n"
       "I'll ask you multiplication questions.\n");
  enum Difficulty difficulty = prompt_difficulty();
  puts("Let's start! Enter -1 to exit.");
  puts("");

  int expected, entered;
  do {
    expected = multiplication_question(difficulty);
    do {
      scanf("%d", &entered);
    } while (entered != -1 && !enteredIsCorrect(expected, entered));
    puts("");
  } while (entered != -1);

  puts("Bye!");
}
