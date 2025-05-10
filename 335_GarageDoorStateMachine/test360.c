/**
 * @file test360.c
 * @author M. Z.
 * @brief Garage door state machine
 * @version 0.1
 * @date 2025-04-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>

// Define the states 
typedef enum {
  STATE_CLOSED,
  STATE_OPENING,
  STATE_OPEN,
  STATE_CLOSING,
  STATE_ERROR
} DoorState;

// Define the inputs
typedef enum {
  INPUT_BUTTON_PRESSED,
  INPUT_LIMIT_SWITCH_OPEN,
  INPUT_LIMIT_SWITCH_CLOSED,
  INPUT_MOTOR_OVERCURRENT
} Input;

// Function prototypes
DoorState next_state(DoorState current_state, Input input);
void state_actions(DoorState current_state);

// Main function
int main() {
  DoorState current_state = STATE_CLOSED;
  Input current_input;

  // Simulating the garage door's behavior
  printf("Garage door starts in the %s state.\n",
         current_state == STATE_CLOSED ? "closed" : "open");
  while (1) {
    // Simulate input
    printf("Enter the input (1=button, 2=open limit, 3=closed limit, "
           "4=overcurrent): ");
    scanf("%d", &current_input);
    current_input--; // Adjust to 0-based indexing

    if (current_input < 0 || current_input >= 4) {
      printf("Invalid input.\n");
      continue;
    }

    // Get the next state based on the current state and input
    current_state = next_state(current_state, current_input);

    // Perform actions for the current state
    state_actions(current_state);

    // Print the current state
    if (current_state == STATE_CLOSED) {
      printf("Current state: CLOSED\n");
    } else if (current_state == STATE_OPENING) {
      printf("Current state: OPENING\n");
    } else if (current_state == STATE_OPEN) {
      printf("Current state: OPEN\n");
    } else if (current_state == STATE_CLOSING) {
      printf("Current state: CLOSING\n");
    } else if (current_state == STATE_ERROR) {
      printf("Current state: ERROR\n");
    }

    // Break the loop to stop the simulation
    if (current_input == 0 && current_state == STATE_CLOSED) {
      break;
    }
  }

  return 0;
}

// Determine the next state based on the current state and input
DoorState next_state(DoorState current_state, Input input) {
  switch (current_state) {
  case STATE_CLOSED:
    if (input == INPUT_BUTTON_PRESSED) {
      return STATE_OPENING;
    }
    return STATE_CLOSED;
  case STATE_OPENING:
    if (input == INPUT_LIMIT_SWITCH_OPEN) {
      return STATE_OPEN;
    }
    return STATE_OPENING;
  case STATE_OPEN:
    if (input == INPUT_BUTTON_PRESSED) {
      return STATE_CLOSING;
    }
    return STATE_OPEN;
  case STATE_CLOSING:
    if (input == INPUT_LIMIT_SWITCH_CLOSED) {
      return STATE_CLOSED;
    }
    return STATE_CLOSING;
  case STATE_ERROR:
    return STATE_ERROR;
  default:
    return STATE_ERROR;
  }
}

// Perform actions based on the current state
void state_actions(DoorState current_state) {
  switch (current_state) {
  case STATE_CLOSED:
    printf("Door is closed.\n");
    break;
  case STATE_OPENING:
    printf("Motor is moving the door up.\n");
    break;
  case STATE_OPEN:
    printf("Door is fully open.\n");
    break;
  case STATE_CLOSING:
    printf("Motor is moving the door down.\n");
    break;
  case STATE_ERROR:
    printf("Error state: check for obstructions or other problems.\n");
    break;
  default:
    break;
  }
}


