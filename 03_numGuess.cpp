#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    int secretNumber = rand() % 15 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 3;

    cout << "\n Welcome to the Number Guessing Game!\n";
    cout << " I'm generating a number between 1 and 15....\n";
    cout << " You have only three attempts to guess the number: \n";
    cout << "Good Luck!\n";
    
    for (int i = 1; i <= attempts; i++)
    {
        cout << "\n Attempts " << i << " : Enter your Guess: ";
        cin >> guess;

        if (guess == secretNumber)
        {
            cout << " Congratulation! You guess the number \n";
            return 0;
        }
        else if (guess > secretNumber)
        {
            cout << " Too High! Try again! \n";
        }
        else
        {
            cout << " Too Low! Try again! \n";
        }
        
    }
    
    cout << "\n Sorry! You have used your all Attempts: \n";
    cout << " The correct number was: " << secretNumber << "\n";

    return 0;
}
