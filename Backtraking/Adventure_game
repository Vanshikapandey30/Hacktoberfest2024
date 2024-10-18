import java.util.Random;
import java.util.Scanner;

public class DungeonAdventure {
    static int playerHealth = 100;
    static int monsterHealth = 50;
    static int potions = 3;
    static int attackDamage = 25;
    static int numMonstersDefeated = 0;
    static boolean running = true;
    static Random rand = new Random();
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Welcome to Dungeon Adventure!");
        System.out.println("Your goal is to defeat monsters and survive the dungeon.");

        while (running) {
            System.out.println("\n---------------------------------------------");
            System.out.println("You have " + playerHealth + " HP and " + potions + " potions left.");
            System.out.println("A wild monster has appeared! It has " + monsterHealth + " HP.");
            System.out.println("What will you do?");
            System.out.println("1. Attack the monster");
            System.out.println("2. Drink a potion");
            System.out.println("3. Run away");

            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    attackMonster();
                    break;
                case "2":
                    drinkPotion();
                    break;
                case "3":
                    runAway();
                    break;
                default:
                    System.out.println("Invalid choice! Please select 1, 2, or 3.");
                    System.out.println("Type carefully and enter one of the available options.");
            }

            if (playerHealth <= 0) {
                System.out.println("You have been defeated! Game over.");
                running = false;
            } else if (monsterHealth <= 0) {
                numMonstersDefeated++;
                System.out.println("You defeated the monster! Monsters defeated: " + numMonstersDefeated);
                monsterHealth = 50 + rand.nextInt(50); // Respawn a new monster with a random health
                System.out.println("Another monster approaches with " + monsterHealth + " HP!");
            }
        }

        System.out.println("\nYou defeated " + numMonstersDefeated + " monster(s) in total.");
        System.out.println("Thanks for playing Dungeon Adventure!");
    }

    public static void attackMonster() {
        int damageDealt = rand.nextInt(attackDamage);
        int damageTaken = rand.nextInt(attackDamage);

        monsterHealth -= damageDealt;
        playerHealth -= damageTaken;

        System.out.println("You dealt " + damageDealt + " damage to the monster.");
        System.out.println("You received " + damageTaken + " damage from the monster.");
    }

    public static void drinkPotion() {
        if (potions > 0) {
            playerHealth += 30;
            potions--;
            System.out.println("You drank a potion and restored 30 HP.");
        } else {
            System.out.println("You have no potions left!");
        }
    }

    public static void runAway() {
        System.out.println("You ran away from the monster!");
        System.out.println("You take a moment to catch your breath and regain 10 HP.");
        playerHealth += 10;
    }
}
