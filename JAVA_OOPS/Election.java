import java.io.*;

class InvalidVoterAgeException extends Exception
{
    private String name;
    private int age;
    InvalidVoterAgeException(String name, int age)
    {
        this.name = name;
        this.age = age;
    }
    public String toString()
    {
        return this.name + " is not eligible to vote as he/she is only " + this.age + " years";
    }

} 
class Voter
{
    private String name;
    private int age;
    private String voterId;

    Voter(String name, int age, String voterId)
    {
        this.name = name;
        this.age = age;
        this.voterId = voterId;
    }

    void VoterValidator() throws InvalidVoterAgeException
    {
        if (this.age < 18)
            throw new InvalidVoterAgeException(this.name, this.age);
        else
            System.out.println(this.name + " is eligible to vote as he/she is " + this.age + " years");
    }
}

class Election
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the number of voters: ");
        int numberOfVoters = Integer.parseInt(reader.readLine());
        Voter[] voters = new Voter[numberOfVoters];
        for (int i = 0; i < numberOfVoters; i++) {
            System.out.print("Enter voter ID for voter " + (i + 1) + ": ");
            String voterId = reader.readLine();
            System.out.print("Enter name for voter " + (i + 1) + ": ");
            String name = reader.readLine();
            System.out.print("Enter age for voter " + (i + 1) + ": ");
            int age = Integer.parseInt(reader.readLine());
            voters[i] = new Voter(name, age, voterId);
        }
        for (int i = 0; i < voters.length; i++) {
            try {
            voters[i].VoterValidator();
            } catch (InvalidVoterAgeException e) {
            System.out.println("Exception Caught: " + e);
            }
        }
    }

}
