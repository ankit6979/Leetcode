public class Recursion {
    public static void printRev(String str, int idx) {
        if(idx < 0) {
            return;
        };
        System.out.println(str.charAt(idx));
        printRev(str, idx - 1);
    }
    public static void main(String[] args) {
        String str = "abcd";
        printRev(str, str.length() - 1);
    }
}