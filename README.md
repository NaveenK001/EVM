# EVM
# Electronic Voting Machine (EVM) with Biometric Authentication
# Project Description
This project implements a secure Electronic Voting Machine (EVM) system using biometric authentication (fingerprint recognition). It ensures that only eligible voters can cast their votes by verifying their identity through fingerprint matching. The system also includes an admin mode for viewing election results, resetting the system, and more.
The system is designed using the PIC16F877A microcontroller, with several peripherals such as an LCD display, GSM module, fingerprint sensor, and buzzer. The software enables vote counting, results display, and secure communication with voters via SMS.

# Features
Biometric Authentication: Fingerprint-based voter identification to ensure only registered voters can vote.
Multi-Candidate Voting: Supports voting for multiple candidates.
Admin Mode: Admins can access the system to view results, reset vote counts, and start/close the voting session.
Security: Limited retry attempts for fingerprint authentication to prevent misuse.
Vote Counting and Results: Tracks votes for each candidate and displays the final tally at the end of the election.
GSM Communication: Sends an SMS confirmation to voters after their vote is cast.
Error Handling: Buzzer alerts for failed fingerprint matches or invalid operations.
System Reset: Admin can reset the system to prepare it for a new voting session.
# Components and Technologies Used
# Hardware:
PIC16F877A Microcontroller: Controls the voting system and interfaces with peripherals.
Fingerprint Sensor (R305): Used for biometric authentication of voters.
LCD Display (16x2): Provides real-time feedback to the voter and admin.
GSM Module (SIM900): Sends confirmation SMS to voters.
Buzzer: Alerts on invalid operations or failed authentication attempts.
Keypad: Allows candidate selection and system control.
Power Supply: Provides power to the entire system, using voltage regulators and transformers.
Software:
MPLAB X IDE: Used for writing and compiling the embedded code for the PIC16F877A microcontroller.
Embedded C: Language used for programming the microcontroller.
# Project Setup
# Hardware Setup:
Connect the Fingerprint Sensor (R305) to the PIC16F877A microcontroller via the UART interface.
Wire the LCD Display to PORTC of the PIC microcontroller for displaying status messages.
Interface the GSM Module to the microcontroller via another UART connection.
Connect the Keypad for candidate selection to the respective I/O pins of the microcontroller.
Power the system using a 5V regulated power supply.
# Software Setup:
# Download and install MPLAB X IDE.
# git clone https://github.com/yourusername/e-voting-system.git
Open the project in MPLAB X IDE and connect your PIC16F877A for flashing the firmware.
Compile and flash the code onto the microcontroller.
# Folder Structure:
/project-root
│
├── /src                  # Source code files (Embedded C)
│   ├── main.c            # Main source file for the voting system
│   ├── lcd.c             # Functions to interface with the LCD display
│   ├── fingerprint.c     # Functions for fingerprint module interaction
│   └── gsm.c             # Functions for GSM module communication
│
├── /docs                 # Project documentation
│   ├── circuit_diagram.pdf
│   └── component_list.pdf
│
├── /images               # Images for README and documentation
│
├── README.md             # Project README file
│
└── LICENSE               # License information
# Usage
Start the system: Power on the system. The LCD will prompt the voter to place their finger on the scanner.
Fingerprint Authentication: The voter places their finger on the fingerprint sensor. If the fingerprint is verified, the system moves to the voting phase.
Vote Casting: The voter selects their candidate using the keypad. The system confirms their vote.
Vote Confirmation: The GSM module sends a confirmation message to the voter via SMS.
Admin Mode: The admin can view the results or reset the system using the designated admin pin.
Circuit Diagram
Provide a high-level description of the circuit here or include an image from the /images directory. Mention connections between the microcontroller and peripherals (LCD, fingerprint sensor, GSM module, keypad).


# Feel free to contribute by:

Reporting issues
Suggesting features
Creating pull requests
