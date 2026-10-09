#include <stdio.h>
#include <stdlib.h>
#include <time.h>

constexpr int WINNING_SCORE = 3;

// Datatypes
enum Shape { ROCK = 0, SCISSORS = 1, LIZARD = 2, PAPER = 3, SPOCK = 4 };
enum Status { DRAW, HUMAN_SCORES, AGENT_SCORES };

// We did not introduce this syntax. Alternative is to repeat `printf`s.
constexpr char SHAPES_STR[] =
    "0: Rock ✊ || 1: Scissors ✌️ || 2: Lizard 🤏 || 3: Paper ✋ || 4: Spock 🖖";

constexpr int SHAPE_COUNT = 5;

enum Status resolve(enum Shape human, enum Shape agent) {
  int difference = (agent - human + SHAPE_COUNT) % SHAPE_COUNT;
  if (difference == 0) {
    return DRAW;
  } else if (difference <= 2) {
    return HUMAN_SCORES;
  } else {
    return AGENT_SCORES;
  }
}

char *shape_to_str(enum Shape shape) {
  switch (shape) {
  case ROCK:
    return "Rock ✊";
  case SCISSORS:
    return "Scissors ✌️";
  case LIZARD:
    return "Lizard 🤏";
  case PAPER:
    return "Paper ✋";
  case SPOCK:
    return "Spock 🖖";
  }
}

int main() {
  srand(time(NULL)); // Use another random sequence every time
  puts("============================================");
  puts("Welcome to Rock Paper Scissors Lizard Spock!");
  puts("============================================");

  printf("Winning score is %d.\n\n", WINNING_SCORE);
  puts("Enter the nummer id of the shape you want to play:");
  puts(SHAPES_STR);
  puts("");

  // Game loop
  int human_score = 0, agent_score = 0;
  while (human_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
    enum Shape human_shape, agent_shape;

    printf("Human 👫: ");
    scanf("%d", &human_shape);

    if (human_shape >= SHAPE_COUNT) {
      printf("Shape key %d does not exist ❌. Try again.\n", human_shape);
      puts(SHAPES_STR);
      puts("");
      continue; // Ask again
    }

    agent_shape = rand() % SHAPE_COUNT;
    printf("Agent 🤖: %d\n", agent_shape);

    switch (resolve(agent_shape, human_shape)) {
    case DRAW:
      printf("%s == %s It is a draw.", shape_to_str(human_shape),
             shape_to_str(agent_shape));
      break;
    case HUMAN_SCORES:
      ++human_score;
      printf("%s beats %s", shape_to_str(human_shape),
             shape_to_str(agent_shape));
      break;
    case AGENT_SCORES:
      ++agent_score;
      printf("%s loses to %s", shape_to_str(human_shape),
             shape_to_str(agent_shape));
      break;
    }
    puts("");
    // Resolution
    printf("Human 👫 : Agent 🤖  %d : %d\n\n", human_score, agent_score);
  }

  // Announce the winner
  printf("%s won!\n", human_score > agent_score ? "Human" : "Agent");
  printf("%s🏆\n", human_score > agent_score ? "👫" : "🤖");
}
