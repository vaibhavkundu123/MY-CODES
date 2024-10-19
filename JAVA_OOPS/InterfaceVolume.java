import java.io.*;
interface Volume
{
    double involume(double s1, double s2, double s3);
    double outvolume(double s1, double s2, double s3);
}

class Vol implements Volume
{
    public double involume(double s1, double s2, double s3)
    {
        return (Math.PI*s1*s2*s3)/3;
    }
    
    public double outvolume(double s1, double s2, double s3)
    {
        return (4*Math.PI*s1*s2*s3)/3;
    }
}

class InterfaceVolume
{
    public static void main(String[] args) throws IOException
    {
        Vol obj = new Vol();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the values s1, s2, s3: ");
        double s1 = Double.parseDouble(br.readLine());
        double s2 = Double.parseDouble(br.readLine());
        double s3 = Double.parseDouble(br.readLine());
        System.out.println("Involume: " + obj.involume(s1, s2, s3));
        System.out.println("Outvolume: " + obj.outvolume(s1, s2, s3));
    }
}
