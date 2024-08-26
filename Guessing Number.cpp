#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Initialize random seed based on current time
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate a random number between 1 and 100
    int numberToGuess = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    // Loop until the user guesses the correct number
    while (guess != numberToGuess) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Check for invalid input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            continue;
        }

        attempts++;

        // Provide feedback on the guess
        if (guess < numberToGuess) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > numberToGuess) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}

