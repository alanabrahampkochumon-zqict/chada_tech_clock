#include "../include/Clock.h"

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

std::ostream& operator<<(const std::ostream& os, const Clock& clock)
{
}
