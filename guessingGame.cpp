#include <bits/stdc++.h>
using namespace std;

class GuessingGame
{
private:
    int score;
    int level;
    // Function to generate a random number
    int randomNumber(int range) { return (rand() % range + 1); }

public:
    GuessingGame() : score(0), level(1)
    {
        srand(static_cast<unsigned>(time(nullptr)));
    }
    void start()
    {
        cout << "-------Welcome to the Guessing Game!-------\n";
        while (true)
        {
            int range = level * 10;
            int guessingNumber = randomNumber(range);
            int count = 4 + level;
            char playYN;
            int guess;

            cout << "Level : " << level << endl;
            cout << "Score : " << score << endl;
            cout << "Guess the number in range 1 to " << range << endl;

            while (--count)
            {
                cin >> guess;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Input. Please enter a number." << endl;
                    count++;
                }
                else if (guess == guessingNumber)
                {
                    cout << "Congrats! You have guessed it right." << endl;
                    score += level * count;
                    level++;
                    break;
                }
                cout << (guess > guessingNumber ? "Guess Lower Number" : "Guess Higher Number.") << endl;
            }
            if (count == 0)
            {
                cout << "Wrong Guess" << endl;
                score -= level;
                if (score < 0)
                {
                    score = 0;
                    level = 1;
                }
                cout << "The correct guess was " << guessingNumber << endl;
                cout << "Do you want to play again: Y(Yes) or N(No) -> ";
                cin >> playYN;
                cout << endl;
            }
            if (playYN == 'N' || playYN == 'n')
            {
                cout << "Your final score is " << score << endl;
                system("pause");
                break;
            }
        }
    }
}

;

int main()
{
    GuessingGame game;
    game.start();

    return 0;
}