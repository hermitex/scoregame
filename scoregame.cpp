// scoregame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
    std::ifstream fin;
    std::ofstream fout;

    char highscore[] = "highscore.txt";
    char temp_score[] = "temp.txt";

    fin.open(highscore);

    int num = 0;
    int score = 0;
    int high_score = 0;

    bool status = true;

    srand(time(0));

    std::string welcome_msg = "****Welcome to OnlyEven OddScore game****";

    std::cout << welcome_msg;

    fin >> high_score;

    std::cout << "High Score is " << high_score << std::endl;

    while (status) {
        std::cout << "Enter a number to play: ";
        std::cin >> num;

        if (num % 2 == 0) {
            score += 2;
            std::cout << "You get 2 points. New score is: " << score << std::endl;
        }
        else {
            fout.open(temp_score);
            if (high_score >= score) {
                fin.close();
                fout.close();
            }
            else {
                fout << score;
                fin.close();
                fout.close();
                remove(highscore);
                rename(temp_score, highscore);
                fin.close();
                fout.close();

            }
            std::cout << "You entered an odd number. You lose";
            status = false;
        }
    }
        return 0;
}
