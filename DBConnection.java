import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {
    private static Connection conn = null;

    public static Connection getConnection() {
        if (conn == null) {
            try {
                conn = DriverManager.getConnection(
                        "jdbc:mysql://localhost:3306/teachers_db?useSSL=false&serverTimezone=UTC",
                        "root",
                        ""
                );
                System.out.println("✅ Συνδέθηκες στη βάση με επιτυχία!");
            } catch (SQLException e) {
                System.out.println("❌ Σφάλμα σύνδεσης: " + e.getMessage());
            }
        }
        return conn;
    }
}
