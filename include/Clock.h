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
	// Constants for defining the limit for hour, minute, and seconds
	constexpr unsigned int HOUR_MAX = 24;
	constexpr unsigned int MINUTE_MAX = 60;
	constexpr unsigned int SECOND_MAX = 60;

public:
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

private:
	unsigned int clockHour, clockMinute, clockSecond; // Member variables storing hour, minute and seconds.
};

//TODO: Add clock-type enum
/**
 * Overrides the ostream to enable printing the clock to the screen.
 * @param os the incoming output stream to which clock's data is appended 
 * @param clock object to print.
 * @return ostream instance that has the clock print string attached.
 */
std::ostream& operator<<(const std::ostream& os, const Clock& clock);