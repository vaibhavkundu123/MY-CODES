import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;

class BankAccount {
    private String accountNumber;
    private String accountHolderName;
    private double balance;
    private File logFile;

    public BankAccount(String accountNumber, String accountHolderName, double initialBalance) {
        this.accountNumber = accountNumber;
        this.accountHolderName = accountHolderName;
        this.balance = initialBalance;
        this.logFile = new File(accountNumber + "_log.txt");
    }
    void writeInitialAccountCreationDetails()
    {
        // Write initial account creation details to log file
        try (BufferedWriter logWriter = new BufferedWriter(new FileWriter(logFile, true))) {
            logWriter.write("Account Created on: " + getCurrentDateTime() + "\n");
            logWriter.write("Initial Deposit: " + balance + "\n\n");
        } catch (IOException e) {
            System.out.println("Error writing to log file.");
        }
    }
    private String getCurrentDateTime() {
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        return formatter.format(new Date());
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }

    public double getBalance() {
        return balance;
    }

    public void depositMoney(double money) {
        if (money <= 0) {
            System.out.println("Invalid deposit amount. Please try again.");
        } else {
            balance += money;
            System.out.println("Successfully deposited: " + money);
            updateAccountDetails();

            // Log deposit transaction
            appendLog("Deposit of " + money + " on: " + getCurrentDateTime());
        }
    }

    public double withdrawMoney(double money) {
        if (money <= 0) {
            System.out.println("Invalid withdrawal amount. Please try again.");
            return 0;
        } else if (balance >= money) {
            balance -= money;
            System.out.println("Successfully withdrawn: " + money);
        } else {
            System.out.println("Insufficient balance! Withdrawing remaining: " + balance);
            money = balance;
            balance = 0;
        }
        updateAccountDetails();

        // Log withdrawal transaction
        appendLog("Withdrawal of " + money + " on: " + getCurrentDateTime());

        return money;
    }

    public void displayAccountDetails() {
        System.out.println("Account Details:");
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Holder Name: " + accountHolderName);
        System.out.println("Balance: " + balance);
    }

    public void displayLogFile() {
        System.out.println("\nTransaction History:");
        try (BufferedReader reader = new BufferedReader(new FileReader(logFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println("Error reading log file.");
        }
    }

    private void appendLog(String message) {
        try (BufferedWriter logWriter = new BufferedWriter(new FileWriter(logFile, true))) {
            logWriter.write(message + "\n");
            logWriter.write("\n"); // Adding a blank line for spacing
            updateBalanceInLog();
        } catch (IOException e) {
            System.out.println("Error writing to log file.");
        }
    }

    private void updateBalanceInLog() {
        try (BufferedWriter logWriter = new BufferedWriter(new FileWriter(logFile, true))) {
            logWriter.write("Current Balance: " + balance + "\n");
        } catch (IOException e) {
            System.out.println("Error writing to log file.");
        }
    }

    public void saveAccountDetails() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("bank_database.txt", true))) {
            writer.write(accountNumber + "," + accountHolderName + "," + balance);
            writer.newLine();
        } catch (IOException e) {
            System.out.println("Error saving account details.");
        }
    }

    public void updateAccountDetails() {
        File databaseFile = new File("bank_database.txt");
        StringBuilder fileContent = new StringBuilder();

        try (BufferedReader reader = new BufferedReader(new FileReader(databaseFile))) {
            String line;
            boolean accountUpdated = false;

            while ((line = reader.readLine()) != null) {
                String[] details = line.split(",");
                if (details[0].equals(accountNumber)) {
                    fileContent.append(accountNumber).append(",")
                               .append(accountHolderName).append(",")
                               .append(balance).append("\n");
                    accountUpdated = true;
                } else {
                    fileContent.append(line).append("\n");
                }
            }

            if (!accountUpdated) {
                fileContent.append(accountNumber).append(",")
                           .append(accountHolderName).append(",")
                           .append(balance).append("\n");
            }

        } catch (IOException e) {
            System.out.println("Error reading database file.");
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(databaseFile))) {
            writer.write(fileContent.toString());
        } catch (IOException e) {
            System.out.println("Error writing to database file.");
        }
    }

    public static BankAccount retrieveAccount(String accountNumber, String accountHolderName) {
        try (BufferedReader reader = new BufferedReader(new FileReader("bank_database.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] details = line.split(",");
                if (details[0].equals(accountNumber) && details[1].equalsIgnoreCase(accountHolderName)) {
                    double balance = Double.parseDouble(details[2]);
                    BankAccount account = new BankAccount(accountNumber, accountHolderName, balance);
                    account.appendLog("Account Accessed on: " + account.getCurrentDateTime());
                    return account;
                }
            }
            System.out.println("Account not found!");
        } catch (IOException e) {
            System.out.println("Error retrieving account details.");
        }
        return null;
    }

    public static void deleteAccount(String accountNumber, String accountHolderName) {
        File databaseFile = new File("bank_database.txt");
        StringBuilder fileContent = new StringBuilder();

        boolean accountFound = false;

        try (BufferedReader reader = new BufferedReader(new FileReader(databaseFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] details = line.split(",");
                if (details[0].equals(accountNumber) && details[1].equalsIgnoreCase(accountHolderName)) {
                    accountFound = true;
                    System.out.println("Account deleted successfully.");

                    // Delete the customer's log file
                    File logFile = new File(accountNumber + "_log.txt");
                    if (logFile.exists()) {
                        logFile.delete();
                    }
                } else {
                    fileContent.append(line).append("\n");
                }
            }

            if (!accountFound) {
                System.out.println("Account not found! Unable to delete.");
            }

        } catch (IOException e) {
            System.out.println("Error deleting account.");
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(databaseFile))) {
            writer.write(fileContent.toString());
        } catch (IOException e) {
            System.out.println("Error writing to database file.");
        }
    }
}
