## Prompt

```
===========================================================
•       Provide code that simulates an elevator. You are free to use any language.
•       Upload the completed project to GitHub for discussion during interview.
•       Document all assumptions and any features that weren’t implemented.
•       The result should be an executable, or script, that can be run with the following inputs and generate the following outputs.
                   Inputs: [list of floors to visit] (e.g. elevator start=12 floor=2,9,1,32)
                   Outputs: [total travel time, floors visited in order] (e.g. 560 12,2,9,1,32)
                   Program Constants: Single floor travel time: 10
```

## Running
```
.\elevators.exe 12 2 9 1 32
```

## Assumptions

### Elevator Operation
An elevator will start movement in a given direction based on the call button pressed and the floor entered, as well as any additional calls placed during motion, until reaching the end of the queue and returning to any higher floors.

For example, if I am on floor 12 and intended to go to floor 2, I would call "Down" and press 2 in the elevator. If I also pressed 13, the expectation is that the elevator would first traverse to floor 2 (stopping at any additionally input / called floors along the way) before traversing to 13. Any floor that has the opposite call button pressed will be skipped until the elevator completes its initial queue and reverses direction.

(Likely much more complicated than this, but it serves as a simple description.) There can be a situation in real elevator operation where someone on e.g. floor 2 presses the Up call button, and the elevator stops on floor 2 (due to a passenger wanting to exit on 2) on a path to floor 1. In this situation, the elevator will return to and stop on floor 2 again. I am going to assume that this will not happen, as there's no way to account for it with the input being a simple list of floors.

Given the provided example input -- [12, 2, 9, 1, 32] -- the expected traversal order should be [12, 9, 2, 1, 32].

### Secondary Elevator Operation
Given the exact wording of the prompt and following its inputs & outputs, I will assume that floors are traversed in exact order as given.

### Input
I assume the input will be space-separated and have no other non-numeric values. It will be sanitized, so I will not have to perform any verification other than determining if there are enough arguments to execute.

### Output
There will be two outputs. The first will use the assumptions about elevator operation and print that output to console. The second will use the provided example output as its baseline and print results following that to console.

For example,
```
Input : 5 3 2 4 1
Output:
  40 5,4,3,2,1
  80 5,3,2,4,1
```

The program will exit 0 unless there is an expected error (not enough arguments) wherein it will return 1.