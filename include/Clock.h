#pragma once
#include <iostream>

/**
 * Author: Alan Abraham Puthenparambil Kochumon
 * Date: 15-03-2026
 *
 * A simple clock class that stores hour, minutes, and seconds.
 * It has methods for manipulating time, and printing it in 24-hour and 12-hour format.
 */
class Clock
{

    public:

    enum class PrintMode : unsigned char
    {
        TWELVE_HOUR, TWENTY_FOUR_HOUR, BOTH
    };

    // Constants for defining the limit for hour, minute, and seconds
    constexpr unsigned int HOUR_MAX = 24;
    constexpr unsigned int MINUTE_MAX = 60;
    constexpr unsigned int SECOND_MAX = 60;
    constexpr unsigned int PRINT_WIDTH = 32;

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
     * @param printMode the designated mode to print the clock. Can be 12-hour, 24-hour or both the formats.
     */
    void printClock(PrintMode printMode = PrintMode::BOTH) const;

    private:
    unsigned int clockHour, clockMinute, clockSecond; // Member variables storing hour, minute and seconds.
};