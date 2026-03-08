#include "../include/Clock.h"

#include <iomanip>
#include <sstream>
#include <string>

Clock::Clock(): clockHour(0), clockMinute(0), clockSecond(0) {}


Clock::Clock(unsigned int hour, unsigned int minute, unsigned second)
    : clockHour(hour), clockMinute(minute), clockSecond(second)
{
}

void Clock::addHour() { clockHour = (clockHour + 1) % HOUR_MAX; }

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

static void printCentered(const std::string& str, const int lineWidth)
{
    int totalInside = lineWidth - 2;
    int leftPadding = (totalInside - str.length()) / 2;
    int rightPadding = totalInside - str.length() - leftPadding;

    std::cout << "*" << std::setfill(' ') << std::setw(leftPadding) << "" << str << std::setw(rightPadding) << ""
              << "*";
}

/*
 * Helper function for printing the border
 */
static void printClockBorder()
{
    std::cout << std::setfill('*') << std::setw(LINE_WIDTH) << "";
    std::cout << std::setfill(' ') << std::setw(PADDING) << "";
    std::cout << std::setfill('*') << std::setw(LINE_WIDTH) << "" << '\n';
}


void Clock::printClock() const
{
    // String stream object for appending string
    std::stringstream ss;

    std::string amPM = (clockHour >= 12) ? "PM" : "AM";
    unsigned int hourFactored = clockHour % 12;
    ss << std::setw(2) << std::setfill('0') << hourFactored << ":" << std::setw(2) << std::setfill('0') << clockMinute // Adds clock string with padded 0s
       << ":" << std::setw(2) << std::setfill('0') << clockSecond << " " << amPM;
    std::string twelveHourClock = ss.str();

    ss.str(""); // Clears the string stream
    ss << std::setw(2) << std::setfill('0') << clockHour << ":" << std::setw(2) << std::setfill('0') << clockMinute
       << ":" << std::setw(2) << std::setfill('0') << clockSecond;
    std::string twentyFourHourClock = ss.str();

    // Prints top border
    printClockBorder();

    // Prints 12-Hour Clock followed by 24-Hour clock
    printCentered("12-Hour Clock", LINE_WIDTH);
    std::cout << std::setw(PADDING) << "";
    printCentered("24-Hour Clock", LINE_WIDTH);
    std::cout << "\n";

    // Prints 12-Hour clock time followed by 24-Hour clock time
    printCentered(twelveHourClock, LINE_WIDTH);
    std::cout << std::setw(PADDING) << " ";
    printCentered(twentyFourHourClock, LINE_WIDTH);
    std::cout << "\n";

    // Prints bottom border
    printClockBorder();
}

void Clock::getClockInput()
{
    std::cin.exceptions(std::ios_base::failbit); // Converts flags from cin to exceptions

    // Stores basic information like the messages, limit, and size of input for the clock
    constexpr unsigned int SIZE = 3;
    const std::string errorMessage = "Invalid limit! Please try again!";
    const std::string messages[SIZE] = { "Enter hour: ", "Enter minutes: ", "Enter seconds: " };
    const unsigned int validLimit[SIZE] = { HOUR_MAX, MINUTE_MAX, SECOND_MAX };

    // Placeholder inputs for storing time
    unsigned int inputs[SIZE] = { 0, 0, 0 };

    // Counter that loops through the input
    unsigned int counter = 0;
    while (counter < SIZE)
    {
        try
        {
            std::cout << messages[counter];
            std::cin >> inputs[counter];

            // Input validation
            if (inputs[counter] > validLimit[counter])
                throw std::runtime_error(errorMessage);

            ++counter;
        }
        catch (const std::ios_base::failure& _)
        {
            std::cout << errorMessage << "\n";
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
    clockHour = inputs[0];
    clockMinute = inputs[1];
    clockSecond = inputs[2];
}