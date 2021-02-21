// scoregame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <ctime>


std::ifstream fin;
std::ofstream fout;

char highscore[] = "highscore.txt";
char temp_score[] = "temp.txt";


int num = 0;
int score = 0;
int high_score = 0;

bool status = true;


char continueToPlay() {
    char option = ' ';
    std::cout << "\t\t\t\t\t\t\t" <<"Press:  \n\n\t\t\t\t\t\t\t  y to continue \n\n\t\t\t\t\t\t\t\tOR\n \n \t\t\t\t\t\t\t any key to quit: ";
    std::cin >> option;
    return option;
}

void updateHighScore(int high_score, int score) {
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

    }
}

void play() {
    if (!(std::cin >> num)) {
        std::cout << "\t\t\t\t\t\t\t*****************************************\n" << std::endl;
        std::cout << "\t\t\t\t\t\t\t  Error! Whole Numbers Only Allowed!\n";
        std::cout << "\n\t\t\t\t\t\t\t*****************************************\n\a" << std::endl;
        status = false;
    }
    else {
        if (num % 2 == 0) {
            score += 2;
            std::cout << "\t\t\t\t\t\t\tYou get 2 points. New score is: " << score << std::endl;
        }
        else {
            updateHighScore(high_score, score);
            std::cout << "\n \t\t\t\t\t\t*************************************\n" << std::endl;
            std::cout << "\t\t\t\t\t\tYou entered an odd number. Game Over!" << std::endl;
            std::cout << "\n\t\t\t\t\t\t *************************************\n" << std::endl;
            if (tolower(continueToPlay()) == 'y') {
                updateHighScore(high_score, score);
                if (score > high_score) {
                    high_score = score;
                    fin >> high_score;
                }
                else {
                    fin >> high_score;
                }
                score = 0;
                std::cout << "\t\t\t\t\t\t\t" << "........................." << std::endl;               
                std::cout << "\t\t\t\t\t\t\t" << std::endl;
                std::cout << "\t\t\t\t\t\t\t* ";
                std::cout << "  High Score is " << high_score << "\t*";               
                std::cout << "\t\t\t\t\t\t\t" << std::endl;           
                std::cout << "\t\t\t\t\t\t\t" << "........................." << std::endl;
                status = true;
            }
            else {
                status = false;
            }

        }
    }
}




int main()
{

    fin.open(highscore);

    std::string welcome_msg = "\t\t\t\t\t\t****Welcome to OnlyEven OddScore Game****\n\n";

    std::cout << welcome_msg;

    fin >> high_score;

    std::cout << "\t\t\t\t\t\t\t" << "........................." << std::endl;
    std::cout << "\t\t\t\t\t\t\t" << std::endl;
    std::cout << "\t\t\t\t\t\t\t* ";
    std::cout << "  High Score is " << high_score << "\t*";
    std::cout << "\t\t\t\t\t\t\t" << std::endl;
    std::cout << "\t\t\t\t\t\t\t" << "........................." << std::endl;

    while (status) {
        std::cout << "\n\t\t\t\t\t\t\t" << "Enter a number to play: ";
        play();

    }
          
        return 0;
 }
     

