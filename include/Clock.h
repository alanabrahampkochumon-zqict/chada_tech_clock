#pragma once
/**
 * @author Alan Abraham Puthenparambil Kochumon
 * @date Created on: March 15, 2026
 *
 * @brief A simple clock class that stores hour, minutes, and seconds.
 *        This class encloses methods for manipulating time, and printing it in 24-hour and 12-hour format.
 *
 */


#include <iostream>


constexpr unsigned char LINE_WIDTH = 32; // Maximum print line width
constexpr unsigned int PADDING = 8;      // Padding between clock prints

// Constants for clock validation
constexpr unsigned char HOUR_MAX = 24;
constexpr unsigned char MINUTE_MAX = 60;
constexpr unsigned char SECOND_MAX = 60;

class Clock
{
public:

    /*
     * @brief Initializes a @ref Clock with all member variables set to 0.
     */
    Clock();


    /**
     * @brief Initializes a @ref Clock with passed in values.
     *
     * @param hour number of hours to initialize with.
     * @param minute number of minutes to initialize with.
     * @param second number of seconds to initialize with.
     */
    Clock(unsigned int hour, unsigned int minute, unsigned second);


    /**
     * @brief Adds one hour to the existing hour.
     *        Loops back on value >= @ref HOUR_MAX.
     */
    void addHour();


    /**
     * @brief Adds one minute to the existing minute.
     *        Loops back on value >= @ref MINUTE_MAX.
     */
    void addMinute();

    /**
     * @brief Adds one second to the existing minute.
     *        Loops back on value >= @ref MINUTE_MAX.
     */
    void addSecond();

    /**
     * @brief Outputs the clock to the screen.
     *        Prints the formatted time in both 24-hour and 12-hour format.
     */
    void printClock() const;

    /**
     * @brief Create a clock from user input.
     * @note Input validation and exceptions are handled internally.
     */
    void getClockInput();


private:
    unsigned int clockHour, clockMinute, clockSecond; // Member variables storing hour, minute and seconds.
};