/**
 * @author Alan Abraham Puthenparambil Kochumon
 * @date Created on: March 15, 2026
 *
 * @brief Encapsulates the main entry point and functions for running the program.
 * 
 * @copyright Copyright (c) 2026 Alan Abraham P Kochumon
 */



#include <iostream>

#include "Clock.h"

#include <iomanip>
#include <limits>


/**
 * @brief Output the menu to the screen.
 */
static void printMenu()
{
    std::cout << std::setw(LINE_WIDTH) << std::setfill('*') << "" << '\n';
    std::cout << std::setw(LINE_WIDTH - 1) << std::setfill(' ') << std::left << "* 1 - Add One Hour" << "*" << '\n';
    std::cout << std::setw(LINE_WIDTH - 1) << std::setfill(' ') << std::left << "* 2 - Add One Minute" << "*" << '\n';
    std::cout << std::setw(LINE_WIDTH - 1) << std::setfill(' ') << std::left << "* 3 - Add One Second" << "*" << '\n';
    std::cout << std::setw(LINE_WIDTH - 1) << std::setfill(' ') << std::left << "* 4 - Exit Program" << "*";
    std::cout << std::setw(LINE_WIDTH) << std::setfill('*') << '\n';
    std::cout << std::endl;
}


/**
 * @brief Displays menu options, parse input and executes the appropriate action.
 *
 * @param clock the main clock object that is manipulated by the program.
 */
static void processOptions(Clock& clock)
{
    bool running = true; // A boolean switch runs the for loop
    while (running)
    {
        printMenu();
        try
        {
            // Gets the current option
            unsigned int option;
            std::cout << "Enter option (1 - 4): ";
            std::cin >> option;

            // Performs validation to ensure that it is a valid option
            if (option > 4)
                throw std::runtime_error("Invalid option! Try 1 - 4");

            switch (option)
            {
                case 1:
                    clock.addHour();
                    clock.printClock();
                    break;
                case 2:
                    clock.addMinute();
                    clock.printClock();
                    break;
                case 3:
                    clock.addSecond();
                    clock.printClock();
                    break;
                case 4:
                default:
                    std::cout << "Exiting program...\n";
                    running = false;
            }

        }
        catch (const std::ios_base::failure& _)
        {
            std::cout << "Invalid option! Try 1 - 4" << "\n";
            // Clears the input buffer.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n'); // Clears any errorneous input till newline
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << "\n";
        }
    }
}

/*
 * @brief Main entry point
 */
int main()
{
    // Creates a clock object and gets user input.
    Clock clock;
    clock.getClockInput();

    // Start getting user input and manipulating the clock.
    processOptions(clock);
    return 0;
}