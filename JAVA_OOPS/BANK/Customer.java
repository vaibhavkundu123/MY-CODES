import java.util.Scanner;

public class Customer {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("\nWelcome to the Bank System!");
            System.out.println("Please choose an option:");
            System.out.println("1. Create new account");
            System.out.println("2. Access existing account");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine();  // Consume newline left-over

            switch (choice) {
                case 1:
                    System.out.print("Enter Account Number: ");
                    String accountNumber = scanner.nextLine();

                    System.out.print("Enter Account Holder Name: ");
                    String accountHolderName = scanner.nextLine();

                    System.out.print("Enter Initial Deposit: ");
                    double initialDeposit = scanner.nextDouble();

                    BankAccount account = new BankAccount(accountNumber, accountHolderName, initialDeposit);
                    account.saveAccountDetails();
                    account.writeInitialAccountCreationDetails();
                    System.out.println("Account created successfully!");
                    break;

                case 2:
                    System.out.print("Enter Account Number: ");
                    accountNumber = scanner.nextLine();

                    System.out.print("Enter Account Holder Name: ");
                    accountHolderName = scanner.nextLine();

                    account = BankAccount.retrieveAccount(accountNumber, accountHolderName);
                    if (account != null) {
                        boolean exitAccountMenu = false;
                        while (!exitAccountMenu) {
                            System.out.println("\nPlease choose an option:");
                            System.out.println("1. Deposit Money");
                            System.out.println("2. Withdraw Money");
                            System.out.println("3. Display Account Details");
                            System.out.println("4. Display Transaction History");
                            System.out.println("5. Delete Account");
                            System.out.println("6. Exit to Main Menu");

                            int accountChoice = scanner.nextInt();

                            switch (accountChoice) {
                                case 1:
                                    System.out.print("Enter amount to deposit: ");
                                    double depositAmount = scanner.nextDouble();
                                    account.depositMoney(depositAmount);
                                    break;
                                case 2:
                                    System.out.print("Enter amount to withdraw: ");
                                    double withdrawAmount = scanner.nextDouble();
                                    account.withdrawMoney(withdrawAmount);
                                    break;
                                case 3:
                                    account.displayAccountDetails();
                                    break;
                                case 4:
                                    account.displayLogFile();
                                    break;
                                case 5:
                                    BankAccount.deleteAccount(account.getAccountNumber(), account.getAccountHolderName());
                                    exitAccountMenu = true; // Return to main menu after deletion
                                    break;
                                case 6:
                                    exitAccountMenu = true; // Return to main menu
                                    break;
                                default:
                                    System.out.println("Invalid option! Please try again.");
                            }
                        }
                    }
                    break;

                case 3:
                    exit = true; // Exit the system
                    System.out.println("Exiting the system. Thank you!");
                    break;

                default:
                    System.out.println("Invalid option! Please try again.");
            }
        }

        scanner.close();
    }
}
