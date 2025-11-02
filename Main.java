public class Main {
    public static void main(String[] args) {
        DBConnection.getConnection();  // σύνδεση κατά το άνοιγμα της εφαρμογής
        new MainForm();
    }
}