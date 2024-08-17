# Bank Project

## Overview

The Bank project consists of three main classes: `User`, `Account`, and `Bank`. Each class is designed to handle different aspects of the banking system. Below is a detailed explanation of each class, its variables, and methods.

## Classes

### User Class

The `User` class handles user information and includes the following private variables:

1. **Name**: An array of characters storing the user's first name.
2. **Surname**: An array of characters storing the user's last name.
3. **Gender**: An array of characters storing the user's gender.
4. **Date of Birth**: A struct that contains arrays of characters for the year, month, and day of birth.
5. **National ID**: An array of characters storing the user's national ID.

**Public Methods:**
- **Setter Methods**: Methods to set values for private variables with input validation to ensure correct values are entered.

### Account Class

The `Account` class manages account information and includes the following private variables:

1. **Account Number**: A long integer for the account number.
2. **ID**: An array of characters storing the user's ID (which is the same as the national ID).
3. **Balance**: A long integer storing the account balance.

**Public Methods:**
- **Create Account**: Methods to initialize the account with either a default balance of 0 or a specified amount.

### Bank Class

The `Bank` class is the core class responsible for handling and coordinating the other classes. It includes the following private variables:

1. **Users Array**: A dynamic array of `User` objects.
2. **Accounts Array**: A dynamic array of `Account` objects.
3. **Population**: A long integer representing the number of users.
4. **Account Number**: A long integer representing the number of accounts.

**Public Methods:**
- **Constructor**: Initializes the `Bank` class by loading data from `user` and `account` files and setting up the arrays and variables.
- **Get Population**: Returns the number of users in the bank.
- **Get Account Number**: Returns the number of accounts in the bank.
- **Show All Users**: Displays all user information.
- **Show All Accounts**: Displays all account information.
- **Show Accounts with ID**: Shows all accounts associated with a specific ID.
- **Show Users with ID**: Shows all users associated with a specific ID.
- **Show Account with Account Number**: Shows information about an account with a given account number.
- **Show User Information**: Prompts for an ID and displays all user and account information associated with that ID.
- **Delete All Accounts with ID**: Deletes all accounts associated with a specific ID.
- **Delete User**: Deletes a user and all their associated accounts based on the provided ID.
- **Delete Account for User**: Deletes a specific account for a user based on the provided ID and user choice.
- **User Place**: Returns the index of a user in the array based on the provided ID.
- **Account Place**: Returns the index of an account in the array based on the provided ID.
- **Search User**: Searches for a user by ID and returns a boolean indicating presence.
- **Search Account**: Searches for an account by ID and returns a boolean indicating presence.
- **Search Account by Number**: Similar to `Account Place`, finds the index of an account based on the account number.
- **Deposit**: Adds a specified amount to an account's balance.
- **Withdrawal**: Withdraws a specified amount from an account's balance, ensuring sufficient funds are available.
- **Edit**: Allows modification of user information based on the provided ID.
- **Save User**: Updates user information in the file.
- **Save Account**: Updates account information in the file.

### Utility Function

- **Change Function**: Converts a string of characters representing a number to an integer.