#include "../include/Clock.h"

#include <string>
#include <iomanip>

Clock::Clock(unsigned int hour, unsigned int minute, unsigned second): clockHour(hour), clockMinute(minute), clockSecond(second) { }

void Clock::addHour()
{
	clockHour = (clockHour + 1) % HOUR_MAX;
}

void Clock::addMinute()
{
	if (clockMinute + 1 >= MINUTE_MAX)
		addHour();
	clockMinute = (clockMinute + 1) % MINUTE_MAX;
}

void Clock::addSecond()
{
	if (clockSecond + 1 >= SECOND_MAX)
		addMinute();
	clockSecond++;
}


void Clock::printClock(PrintMode printMode) const
{
    if (printMode == PrintMode::BOTH || printMode == PrintMode::TWELVE_HOUR)
    {
        std::string amPM = (clockHour >= 12) ? "PM" : "AM";
        unsigned int hourFactored = clockHour % 12;
        std::cout << std::setfill("*") << std::setw(PRINT_WIDTH) << "\n";
        std::cout << "*" << std::setfill(" ") << std::setw(PRINT_WIDTH) << "12-Hour Clock" << "*\n";
        std::cout << "*" << std::setfill(" ") << std::setw(PRINT_WIDTH) << clockHour << ":" << clockMinute << ":"
                  << clockSecond << "*\n";
        std::cout << std::setfill("*") << std::setw(PRINT_WIDTH) << "\n";
        
    }
}