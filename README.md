#Library for the Robot Sensors
Library for reading from the sensors in the issued robot through the MSP430.
Example code included in example.c

## General Notes
To be used in future implementation with the library for interacting with the motors.

## Functions

- `void initSensos()`
    - ADC10ON, enables the interrupt and selects SMLCLK

- `unsigned int midSensor()`
    - Reads from the middle sensor and returns ADC10MEM
    - Pin 3

- `unsigned int leftSensor()`
    - Reads from the left sensor and returns ADC10MEM
    - Pin 4

- `unsigned int rightSensor()`
    - Reads from the right sensor and returns ADC10MEM
    - Pin 7
   
## License
Anyone is free to use and modify this for any purpose, provided they pay three easy payments of $15,000

## Documentation
C2C Taorimina helped debug my code-found errors in values I was using to the sensors in the example and also noted that I was not clearing ADC10CTL0

