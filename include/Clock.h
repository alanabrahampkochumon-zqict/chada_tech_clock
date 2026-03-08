#pragma once
#include <iostream>

/**
 * Author: Alan Abraham Puthenparambil Kochumon
 * Date: 15-03-2026
 *
 * A simple clock class that stores hour, minutes, and seconds.
 * It has methods for manipulating time, and printing it in 24-hour and 12-hour format.
 */

constexpr unsigned char LINE_WIDTH = 32; // Maximum print line width
constexpr unsigned int PADDING = 8; // Padding between clock prints

// Constants for clock validation
constexpr unsigned char HOUR_MAX = 24;
constexpr unsigned char MINUTE_MAX = 60;
constexpr unsigned char SECOND_MAX = 60;

class Clock
{

    public:

    /*
     * Default constructor for Clock class.
     */
    Clock();

    /**
     * Parameterized constructor for initializing the Clock.
     * @param hour number of hours to initialize with.
     * @param minute number of minutes to initialize with.
     * @param second number of seconds to initialize with.
     */
    Clock(unsigned int hour, unsigned int minute, unsigned second);

    /**
     * Adds one hour to the existing hour, if >= 24 loops back.
     */
    void addHour();

    /**
     * Adds one minute to the existing minute, if >= 60 adds 1 hour and loops back.
     */
    void addMinute();

    /**
     * Adds one second to the existing seconds, if >= 60 adds 1 second and loops back.
     */
    void addSecond();

    /**
     * Prints the clock to the screen.
     */
    void printClock() const;

    /**
     * Creates a clock from user input.
     * Handles input validation and exceptions.
     */
    void getClockInput();

    private:
    unsigned int clockHour, clockMinute, clockSecond; // Member variables storing hour, minute and seconds.
};