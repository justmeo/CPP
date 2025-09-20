/*
Implement methods exactly as declared in BitcoinExchange.hpp.
Parsing notes:

CSV "data.csv" lines like "2011-01-03,0.3". Skip header if present.

For input lines: trim spaces around tokens; accept "date | value" only.

Use std::map<string,double>::lower_bound(date). If iterator->first != date:

if it == begin() and key < begin()->first: it's an error "bad input => <date>"? (Or choose to deny; the subject requires using closest lower date only if any lower exists.)

else decrement iterator to get closest lower date.

Print format exactly: "YYYY-MM-DD => <value> = <value*price>" with no extra spaces.
*/

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;
    
    return str.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    
    int year = 0, month = 0, day = 0;
    for (int i = 0; i < 4; i++)
        year = year * 10 + (date[i] - '0');
    for (int i = 5; i < 7; i++)
        month = month * 10 + (date[i] - '0');
    for (int i = 8; i < 10; i++)
        day = day * 10 + (date[i] - '0');
    
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) const
{
    if (valueStr.empty())
        return false;
    
    size_t i = 0;
    if (valueStr[0] == '-')
        return false;
    if (valueStr[0] == '+')
        i = 1;
    
    bool hasDot = false;
    bool hasDigit = false;
    
    for (; i < valueStr.length(); i++)
    {
        if (valueStr[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (valueStr[i] >= '0' && valueStr[i] <= '9')
        {
            hasDigit = true;
        }
        else
        {
            return false;
        }
    }
    
    return hasDigit;
}

double BitcoinExchange::parseValue(const std::string& valueStr) const
{
    std::stringstream ss(valueStr);
    double value;
    ss >> value;
    return value;
}

void BitcoinExchange::loadDatabase(const std::string& csvPath)
{
    std::ifstream file(csvPath.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            if (line.find("date") != std::string::npos)
                continue;
        }
        
        if (line.empty())
            continue;
        
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        
        std::string date = line.substr(0, commaPos);
        std::string priceStr = line.substr(commaPos + 1);
        
        if (isValidDate(date) && isValidValue(priceStr))
        {
            double price = parseValue(priceStr);
            _database[date] = price;
        }
    }
}

void BitcoinExchange::evaluateFile(const std::string& inputPath)
{
    std::ifstream file(inputPath.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    bool firstLine = true;
    
    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            if (line.find("date") != std::string::npos && line.find("value") != std::string::npos)
                continue;
        }
        
        if (line.empty())
            continue;
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));
        
        if (!isValidDate(dateStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (!isValidValue(valueStr))
        {
            if (valueStr[0] == '-')
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        double value = parseValue(valueStr);
        
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        std::map<std::string, double>::iterator it = _database.lower_bound(dateStr);
        
        if (it != _database.end() && it->first == dateStr)
        {
            std::cout << dateStr << " => " << value << " = " << (value * it->second) << std::endl;
        }
        else if (it == _database.begin())
        {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
        }
        else
        {
            --it;
            std::cout << dateStr << " => " << value << " = " << (value * it->second) << std::endl;
        }
    }
}

void BitcoinExchange::clear()
{
    _database.clear();
}