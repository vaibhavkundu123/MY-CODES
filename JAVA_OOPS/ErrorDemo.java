class ErrorDemo {
    static void subroutine() {
        int d, a;
        d = 0;
        a = 50/d;
        System.out.println("a = " + a);
    }
    public static void main(String[] args) {
        ErrorDemo.subroutine();
    }
}
