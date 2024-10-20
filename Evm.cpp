#include <pic16f877a.h>  // PIC16F877A microcontroller header file

#define VOTER_PIN RD0        // Pin for voter fingerprint detection
#define BUZZER_PIN RD1       // Buzzer output pin
#define LCD_RS RC0           // LCD RS pin
#define LCD_EN RC1           // LCD Enable pin
#define ADMIN_PIN RB0        // Admin mode activation pin
#define RESET_PIN RB1        // Reset pin for resetting the system

// Candidate vote counters
unsigned int candidate1_votes = 0;
unsigned int candidate2_votes = 0;
unsigned int candidate3_votes = 0;
unsigned char retry_attempts = 0;  // Variable for retry attempts for fingerprint matching

// Function prototypes
void init_system();
void check_fingerprint();
void cast_vote();
void send_gsm_message();
void lcd_display(const char *message);
void admin_mode();
void display_results();
void reset_system();
void vote_menu();
void error_buzzer();

void main() {
    init_system();  // Initialize the system
    
    lcd_display("Waiting...");

    while (1) {
        if (ADMIN_PIN == 1) {  // Admin mode
            admin_mode();
        } else if (VOTER_PIN == 1) {  // Voter fingerprint check
            lcd_display("Place Finger");
            check_fingerprint();  // Authenticate fingerprint
        }
    }
}

// Function to initialize system configurations
void init_system() {
    TRISD = 0x01;  // Set RD0 (fingerprint) as input, others as output
    TRISB = 0x03;  // Set RB0, RB1 as input (admin and reset), others as output
    TRISC = 0x00;  // Set PORTC as output for LCD
    // Initialize LCD, GSM, Fingerprint, and other modules
    // Optionally initialize EEPROM for vote storage
}

// Function to check and authenticate the fingerprint
void check_fingerprint() {
    lcd_display("Authenticating...");
    // Logic for interfacing with the fingerprint module
    if (/*fingerprint matched*/) {
        lcd_display("Authenticated");
        cast_vote();  // Allow user to vote
        retry_attempts = 0;  // Reset retry attempts on success
    } else {
        retry_attempts++;
        if (retry_attempts >= 3) {  // Limit attempts for security
            lcd_display("Too many tries");
            error_buzzer();
            retry_attempts = 0;  // Reset retry attempts after error
        } else {
            lcd_display("Try Again");
            error_buzzer();
        }
    }
}

// Function to allow user to cast their vote
void cast_vote() {
    lcd_display("Select Candidate");
    vote_menu();  // Display voting menu

    if (/*button press for candidate 1*/) {
        candidate1_votes++;
        lcd_display("Vote Casted");
    } else if (/*button press for candidate 2*/) {
        candidate2_votes++;
        lcd_display("Vote Casted");
    } else if (/*button press for candidate 3*/) {
        candidate3_votes++;
        lcd_display("Vote Casted");
    }

    send_gsm_message();  // Send SMS to the voter
}

// Function to handle the voting menu and candidate selection
void vote_menu() {
    lcd_display("1:Candidate 1");
    __delay_ms(2000);  // Display for 2 seconds
    lcd_display("2:Candidate 2");
    __delay_ms(2000);
    lcd_display("3:Candidate 3");
    __delay_ms(2000);
}

// Function to send an SMS via the GSM module
void send_gsm_message() {
    lcd_display("Sending SMS");
    // Logic for sending message via GSM
    // Handle success and error cases of GSM communication
    lcd_display("Thank You");
    __delay_ms(2000);  // Wait for user to see the message
}

// Function for admin mode: view results, reset system, etc.
void admin_mode() {
    lcd_display("Admin Mode");
    __delay_ms(1000);  // Wait for admin access

    // Display results or reset system
    if (/*button press for result display*/) {
        display_results();
    } else if (RESET_PIN == 1) {
        reset_system();
    }
}

// Function to display voting results
void display_results() {
    lcd_display("Results:");
    lcd_display("Candidate 1:");
    // Display votes for Candidate 1
    lcd_display("Candidate 2:");
    // Display votes for Candidate 2
    lcd_display("Candidate 3:");
    // Display votes for Candidate 3
    __delay_ms(5000);  // Show the results for 5 seconds
}

// Function to reset the system and vote counts
void reset_system() {
    candidate1_votes = 0;
    candidate2_votes = 0;
    candidate3_votes = 0;
    lcd_display("System Reset");
    __delay_ms(2000);
}

// Function to trigger an error buzzer for invalid operations
void error_buzzer() {
    BUZZER_PIN = 1;  // Activate buzzer
    __delay_ms(1000);  // Keep buzzer on for 1 second
    BUZZER_PIN = 0;  // Deactivate buzzer
}

// Function to display messages on the LCD
void lcd_display(const char *message) {
    // Logic for interfacing with the 16x2 LCD
    // Send commands and data to display the message
}
