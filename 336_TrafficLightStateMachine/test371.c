/**
 * @file test371.c
 * @author M. Z.
 * @brief Traffic light state machine
 * @version 0.1
 * @date 2025-04-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h> // for sleep function

#define CLOCK_FREQUENCY_HZ 10000000 // 10MHz
#define MAX_COUNTER (CLOCK_FREQUENCY_HZ * 60)

typedef enum {
  STATE_NORTH_NEXT,
  STATE_START_NORTH,
  STATE_NORTH,
  STATE_STOP_NORTH,
  STATE_WEST_NEXT,
  STATE_START_WEST,
  STATE_WEST,
  STATE_STOP_WEST
} TrafficLightState;

TrafficLightState currentState;
uint32_t counter;

bool northRed;
bool northYellow;
bool northGreen;
bool westRed;
bool westYellow;
bool westGreen;

// Function to control the traffic lights based on the state
void controlTrafficLights(TrafficLightState state) {
  switch (state) {
  case STATE_NORTH_NEXT:
    printf("North-South: RED, East-West: RED\n");
    break;
  case STATE_START_NORTH:
    printf("North-South: RED, YELLOW, East-West: RED\n");
    break;
  case STATE_NORTH:
    printf("North-South: GREEN, East-West: RED\n");
    break;
  case STATE_STOP_NORTH:
    printf("North-South: YELLOW, East-West: RED\n");
    break;
  case STATE_WEST_NEXT:
    printf("North-South: RED, East-West: RED\n");
    break;
  case STATE_START_WEST:
    printf("North-South: RED, East-West: RED, YELLOW\n");
    break;
  case STATE_WEST:
    printf("North-South: RED, East-West: GREEN\n");
    break;
  case STATE_STOP_WEST:
    printf("North-South: RED, East-West: YELLOW\n");
    break;
  default:
    printf("Invalid traffic light state\n");
  }
}

void changeState(TrafficLightState nextState, int minutes, int seconds) {
  int totalSeconds = seconds + minutes * 60;
  int clockCycles = totalSeconds * CLOCK_FREQUENCY_HZ - 1;

  if (counter == clockCycles) {
    counter = 0;
    currentState = nextState;
    controlTrafficLights(
        currentState); // Control the lights based on the current state
    sleep(counter);
  }
}

void updateTrafficLight() { //(bool resetSignal) {)
                            // if (resetSignal == false) {
                            //   currentState = STATE_NORTH_NEXT;
                            //   counter = 0;

  //   northRed = true;
  //   northYellow = false;
  //   northGreen = false;
  //   westRed = true;
  //   westYellow = false;
  //   westGreen = false;
  // } else {
  // Default values
  northRed = false;
  northYellow = false;
  northGreen = false;
  westRed = false;
  westYellow = false;
  westGreen = false;
  while (1) {
    counter++;

    switch (currentState) {
    case STATE_NORTH_NEXT:
      northRed = true;
      westRed = true;
      changeState(STATE_START_NORTH, 0, 5);
      break;

    case STATE_START_NORTH:
      northRed = true;
      northYellow = true;
      westRed = true;
      changeState(STATE_NORTH, 0, 5);
      break;

    case STATE_NORTH:
      northGreen = true;
      westRed = true;
      changeState(STATE_STOP_NORTH, 1, 0);
      break;

    case STATE_STOP_NORTH:
      northYellow = true;
      westRed = true;
      changeState(STATE_WEST_NEXT, 0, 5);
      break;

    case STATE_WEST_NEXT:
      northRed = true;
      westRed = true;
      changeState(STATE_START_WEST, 0, 5);
      break;

    case STATE_START_WEST:
      northRed = true;
      westRed = true;
      westYellow = true;
      changeState(STATE_WEST, 0, 5);
      break;

    case STATE_WEST:
      northRed = true;
      westGreen = true;
      changeState(STATE_STOP_WEST, 1, 0);
      break;

    case STATE_STOP_WEST:
      northRed = true;
      westYellow = true;
      changeState(STATE_NORTH_NEXT, 0, 5);
      break;
    }
  }
  //  }
}

int main() {
  updateTrafficLight(); // Start the traffic light control
  return 0;
}




