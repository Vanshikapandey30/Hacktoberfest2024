fun main() {
    val homepage = HomePage()
    homepage.display()
}

class HomePage {
    private var isLoggedIn = false
    private val users = mutableMapOf("admin" to "admin123")
    
    fun display() {
        printHeader()
        
        while (true) {
            if (!isLoggedIn) {
                showLoginMenu()
            } else {
                showMainMenu()
            }
        }
    }
    
    private fun printHeader() {
        println("╔════════════════════════════════╗")
        println("║      Welcome to KotlinHub      ║")
        println("║    Your Interactive Portal     ║")
        println("╚════════════════════════════════╝")
    }
    
    private fun showLoginMenu() {
        println("\n=== Login Menu ===")
        println("1. Login")
        println("2. Register")
        println("3. Exit")
        print("\nEnter your choice: ")
        
        when (readLine()) {
            "1" -> login()
            "2" -> register()
            "3" -> {
                println("\nThank you for visiting! Goodbye!")
                System.exit(0)
            }
            else -> println("\nInvalid choice! Please try again.")
        }
    }
    
    private fun showMainMenu() {
        println("\n=== Main Menu ===")
        println("1. View Profile")
        println("2. Send Message")
        println("3. View Dashboard")
        println("4. Logout")
        print("\nEnter your choice: ")
        
        when (readLine()) {
            "1" -> viewProfile()
            "2" -> sendMessage()
            "3" -> viewDashboard()
            "4" -> logout()
            else -> println("\nInvalid choice! Please try again.")
        }
    }
    
    private fun login() {
        print("\nEnter username: ")
        val username = readLine() ?: ""
        print("Enter password: ")
        val password = readLine() ?: ""
        
        if (users[username] == password) {
            isLoggedIn = true
            println("\n✨ Login successful! Welcome, $username!")
        } else {
            println("\n❌ Invalid username or password!")
        }
    }
    
    private fun register() {
        print("\nEnter new username: ")
        val username = readLine() ?: ""
        if (users.containsKey(username)) {
            println("\n❌ Username already exists!")
            return
        }
        print("Enter new password: ")
        val password = readLine() ?: ""
        users[username] = password
        println("\n✨ Registration successful! Please login.")
    }
    
    private fun viewProfile() {
        println("\n=== Profile Information ===")
        println("Status: Active")
        println("Member Since: 2024")
        println("Last Login: Just now")
        pressEnterToContinue()
    }
    
    private fun sendMessage() {
        print("\nEnter your message: ")
        val message = readLine()
        println("\n✨ Message sent successfully!")
        pressEnterToContinue()
    }
    
    private fun viewDashboard() {
        println("\n=== Dashboard ===")
        println("📊 Active Projects: 3")
        println("📫 New Messages: 5")
        println("🔔 Notifications: 2")
        pressEnterToContinue()
    }
    
    private fun logout() {
        isLoggedIn = false
        println("\n👋 Logged out successfully!")
    }
    
    private fun pressEnterToContinue() {
        print("\nPress Enter to continue...")
        readLine()
    }
}
