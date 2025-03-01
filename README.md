Heart Rate Sensor Simulator

Overview

This program simulates a Heart Rate Sensor System using bitwise operations in C. It takes user input for heart rate (in beats per minute) and encodes sensor-related information into a 16-bit unsigned short integer. The program then processes and presents this data in a human-readable format.

Features
User Input Handling:
Accepts heart rate in BPM and validates the input range.
Bitwise Operations:
Uses bit manipulation to encode and decode sensor data.
Implements functions for setting, clearing, and reading bits.

Sensor State Representation:
Indicates if the device is functioning correctly.
Detects abnormal heart rates.
Identifies whether the sensor needs a reset.
Encodes heart rate volume and parity checks.

Binary Output Display:
Prints the 16-bit heart rate representation in binary.
Displays details about each bit's significance.
Code Structure

main()
Prompts user for heart rate input.
Calls getHeartRate() to encode sensor data.
Calls prepareHeartRate() to process sensor-related functions.
Calls presentHeartRate() to display formatted output.
getHeartRate(int, short *)
Validates input heart rate range.
Encodes heart rate into bits 3–10.
Returns 1 if the heart rate is out of range.

prepareHeartRate(int, unsigned short *)
Modifies sensor bits based on heart rate.
Marks abnormal conditions when applicable.

presentHeartRate(unsigned short)
Extracts and prints sensor data from the 16-bit integer.
Displays heart rate, device status, and abnormal readings.

Bitwise Operations
bitRead(num, pos): Reads a specific bit.
bitSet(num, pos): Sets a specific bit.
bitClear(num, pos): Clears a specific bit.
printAsBinary(unsigned short)
Converts and prints the heart rate value in binary format.
