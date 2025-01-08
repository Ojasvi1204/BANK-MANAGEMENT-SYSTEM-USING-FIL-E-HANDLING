
# Bank Management System

## Overview
The **Bank Management System** is a console-based application written in C that provides basic banking functionalities such as account creation, balance inquiry, deposit, withdrawal, and account details management. This program demonstrates the use of file handling, functions, and structured programming concepts in C.

---

## Features
1. **Account Creation**: Create a new bank account by providing details such as account holder's name, account number, and initial deposit.
2. **Deposit Funds**: Add money to an existing account.
3. **Withdraw Funds**: Withdraw money from an existing account (subject to sufficient balance).
4. **Check Balance**: View the current balance of an account.
5. **View Account Details**: Display the details of an account.
6. **Exit**: exits from the system.

---

## Installation

### Prerequisites
- A C compiler
- A text editor or IDE

### Steps
1. Clone or download the project files.
2. Open the terminal/command prompt and navigate to the project folder.
3. Compile the program:
4. Run the program:
   
---

## Usage
1. Launch the program.
2. Follow the menu prompts to navigate through the functionalities.
3. Input the required information when prompted.

---

## Code Structure
- **Header Files**: Includes standard libraries (`stdio.h`, `stdlib.h`, `string.h`).
- **File Handling**: Persistent storage of account data using files.
- **Functions**: Modular design for each feature.
  - `createAccount()`: Handles account creation.
  - `deposit()`: Adds funds to an account.
  - `withdraw()`: Handles withdrawals.
  - `checkBalance()`: Displays the account balance.
  - `viewDetails()`: Shows account details.
  - `exit()`: exits the system.

---

## Example Workflow
1. **Create Account**: 
   - Input details: Name, Account Number, and Initial Deposit.
   - The program saves the account details to a file.
   
2. **Deposit**: 
   - Enter account number and deposit amount.
   - The program updates the balance in the file.

3. **Withdraw**: 
   - Enter account number and withdrawal amount.
   - The program checks the balance before processing the withdrawal.

4. **Check Balance**: 
   - Enter account number to view the current balance.

5. **Exit**: 
   - Exits from the system.

---

## Limitations
- Only supports basic banking features.
- No graphical interface (CLI-based).
- Limited error handling (e.g., invalid inputs, file corruption).

---

## Future Improvements
- Add user authentication for security.
- Enhance error handling.
- Support multiple currencies.
- Implement a graphical user interface (GUI).
- Enable online banking functionalities like fund transfers.

---

## License
This project is open-source and free to use under the MIT License.

---

For any issues or contributions, feel free to contact [ojasvij3@gmail.com]. 
