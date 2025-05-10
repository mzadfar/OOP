/**
 * @file test370.c
 * @author M. Z.
 * @brief Traffic light state machine
 * @version 0.1
 * @date 2025-04-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <unistd.h> // for sleep function

// Define the traffic light states
typedef enum {
  GREEN_NS,  // Green for North-South
  YELLOW_NS, // Yellow for North-South
  RED_NS,    // Red for North-South
  GREEN_EW,  // Green for East-West
  YELLOW_EW, // Yellow for East-West
  RED_EW     // Red for East-West
} TrafficLightState;

// Function to control the traffic lights based on the state
void controlTrafficLights(TrafficLightState state) {
  switch (state) {
  case GREEN_NS:
    printf("North-South: GREEN, East-West: RED\n");
    break;
  case YELLOW_NS:
    printf("North-South: YELLOW, East-West: RED\n");
    break;
  case RED_NS:
    printf("North-South: RED, East-West: GREEN\n");
    break;
  case GREEN_EW:
    printf("North-South: RED, East-West: GREEN\n");
    break;
  case YELLOW_EW:
    printf("North-South: RED, East-West: YELLOW\n");
    break;
  case RED_EW:
    printf("North-South: GREEN, East-West: RED\n");
    break;
  default:
    printf("Invalid traffic light state\n");
  }
}

// Function to implement the 4-way traffic light state machine
void trafficLightControl() {
  TrafficLightState state = GREEN_NS; // Start with green for North-South
  int duration = 5; // Default duration for each state (e.g., seconds)

  while (1) {
    controlTrafficLights(
        state); // Control the lights based on the current state

    // Implement state transitions with time delays
    switch (state) {
    case GREEN_NS:
      sleep(duration); // North-South green for a period
      state = YELLOW_NS;
      break;
    case YELLOW_NS:
      sleep(duration / 2); // North-South yellow for a shorter period
      state = RED_NS;
      break;
    case RED_NS:
      sleep(duration);  // North-South red
      state = GREEN_EW; // Transition to East-West green
      break;
    case GREEN_EW:
      sleep(duration); // East-West green
      state = YELLOW_EW;
      break;
    case YELLOW_EW:
      sleep(duration / 2); // East-West yellow
      state = RED_EW;
      break;
    case RED_EW:
      sleep(duration);  // East-West red
      state = GREEN_NS; // Transition back to North-South green
      break;
    }
  }
}

int main() {
  trafficLightControl(); // Start the traffic light control
  return 0;
}

