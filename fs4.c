/* Simple program to demonstrate basic I/O.
 * Written and presented by Group 1.
 */
#include <stdio.h>
#include <string.h>
int main() {
	// Program flag
	int exival = 0;

	// Populate credentials
	char personIdentity[2][20] = {"root", "guest"};
	char passwords[2][20] = {"toor", "guest"};
	
	// Hold username and password
	char username[255];
	char pass[255];
	
	int denominations[] = {100000, 50000, 20000, 10000};

	// Execute program
	while(exival != 1) {
		printf("Input username: ");
		scanf("%s", &username);
		
		if(strcmp(username, "quit") == 0 || strcmp(username, "exit") == 0) {
			return 0;
		}

		printf("Input password: ");
		scanf("%s", &pass);
		
		int loggedIn = 0;
		for(int i = 0; i < 2; i++) {
		
			if(strcmp(username, personIdentity[i]) == 0 && strcmp(pass, passwords[i]) == 0) {
				loggedIn = 1;
				break;
			}
		}
		
		if(!loggedIn) {
			printf("Incorrect credentials. Try again.\n");
		}
		
		else {
			// Hold withdrawal and remainder value
			int withdrawal, balance;
			int counts[4] = {0};

			do {
				// Input withdrawal amount
				printf("Enter the withdrawal amount: ");
				scanf("%d", &withdrawal);
			} 
			while (withdrawal < 0);

			balance = withdrawal; // Initialize balance with withdrawal amount

			// Calculate denomination counts
			for (int i = 0; i < 4; i++) {
				counts[i] = balance / denominations[i];
				balance %= denominations[i];
			}

			// Output current balance
			printf("Your current balance: %d\n", balance);

			// Output withdrawal details
			printf("Withdrawal:\n");
			for (int i = 0; i < 4; i++) {
				if (counts[i] > 0) {
					printf("%d x %d\n", denominations[i], counts[i]);
				}
			}
		}
	}
}
