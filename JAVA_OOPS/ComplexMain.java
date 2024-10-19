import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Complex
{
    int real, imaginary;
    Complex()
    {
        real = 5;
        imaginary = 10;
    }
    Complex(int r, int i)
    {
        real = r;
        imaginary = i;
    }
    Complex(Complex ob)
    {
        real = ob.real;
        imaginary = ob.imaginary;
    }
    Complex addition(Complex ob1, Complex ob2)
    {
        real = ob1.real + ob2.real;
        imaginary = ob1.imaginary + ob2.imaginary;
        return this;
    }
    Complex subtraction(Complex ob1, Complex ob2)
    {
        real = ob1.real - ob2.real;
        imaginary = ob1.imaginary - ob2.imaginary;
        return this;
    }
    Complex multiplication(Complex ob1, Complex ob2)
    {
        real = (ob1.real * ob2.real) - (ob1.imaginary * ob2.imaginary);
        imaginary = (ob1.real * ob2.imaginary) + (ob1.imaginary * ob2.real);
        return this;
    }
    void print()
    {
        System.out.println(real + " + " + "(" + imaginary + ")" + "i");
    }
}

class ComplexMain {
    public static void main(String args[]) throws IOException
    {
        System.out.println();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Complex ob1 = new Complex();
        Complex ob2 = new Complex();
        Complex ob10 = new Complex();
        ob10 = ob10.addition(ob1, ob2);
        System.out.print("Addition(default object): ");
        ob10.print();
        System.out.println();
        ob10 = ob10.subtraction(ob1, ob2);
        System.out.print("Subtraction(default object): ");
        ob10.print();
        System.out.println();
        ob10 = ob10.multiplication(ob1, ob2);
        System.out.print("Multiplication(default object): ");
        ob10.print();
        System.out.println();
        System.out.print("Enter the real number of 1st object: ");
        int r1 = Integer.parseInt(br.readLine());
        System.out.print("Enter the imaginary number of 1st object: ");
        int i1 = Integer.parseInt(br.readLine());
        Complex ob3 = new Complex(r1, i1);
        System.out.print("Enter the real number of 2nd object: ");
        int r2 = Integer.parseInt(br.readLine());
        System.out.print("Enter the imaginary number of 2nd object: ");
        int i2 = Integer.parseInt(br.readLine());
        Complex ob4 = new Complex(r2, i2);
        System.out.println();
        ob10 = ob10.addition(ob3, ob4);
        System.out.print("Addition(parameterized object): ");
        ob10.print();
        System.out.println();
        ob10 = ob10.subtraction(ob3, ob4);
        System.out.print("Subtraction(parameterized object): ");
        ob10.print();
        System.out.println();
        ob10 = ob10.multiplication(ob3, ob4);
        System.out.print("Multiplication(parameterized object): ");
        ob10.print();
        System.out.println();
        Complex ob5 = new Complex(ob1);
        Complex ob6 = new Complex(ob3);
        ob10 = ob10.addition(ob5, ob6);
        System.out.print("Addition(copy object): ");
        ob10.print();
        System.out.println();
        ob10 = ob10.subtraction(ob5, ob6);
        System.out.print("Subtraction(copy object): ");
        ob10.print();
        System.out.println();
        ob10 = ob10.multiplication(ob5, ob6);
        System.out.print("Multiplication(copy object): ");
        ob10.print();
        System.out.println();
    }
}
