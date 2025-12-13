/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 23:30:09 by psantos-          #+#    #+#             */
/*   Updated: 2025/12/12 11:29:23 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    int year, month, day;
    try {
        year  = std::stoi(date.substr(0, 4));
        month = std::stoi(date.substr(5, 2));
        day   = std::stoi(date.substr(8, 2));
		(void) year;
    }
    catch (...) {
        return false;
    }
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

bool isPositiveFloat(const std::string& s)
{
    std::string trimmed = s;
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);
    std::stringstream ss(trimmed);
    float v;
    char extra;
    if (!(ss >> v))
        return false;
    if (ss >> extra)
        return false;
    return v >= 0 && v <= 1000;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;
        if (!isValidDate(date))
            continue;
        try
        {
            float rate = std::stof(valueStr);
            _data[date] = rate;
        }
        catch (...)
        {
            continue;
        }
    }
}

float BitcoinExchange::getRate(const std::string& date) const {
    if (_data.empty())
        throw std::runtime_error("Database is empty");

	std::map<std::string,float>::const_iterator it = _data.lower_bound(date);

    if (it == _data.end())
        return std::prev(it)->second;

    if (it->first == date)
        return it->second;

    if (it == _data.begin())
        return it->second;

    return std::prev(it)->second;
}

void parseInput(const std::string& line, std::string& dateStr, float& value)
{
    std::stringstream ss(line);
    std::string valueStr;

    if (!std::getline(ss, dateStr, '|') || !std::getline(ss, valueStr))
        throw std::runtime_error("Error: bad input format");

    size_t start = valueStr.find_first_not_of(" \t");
    size_t end   = valueStr.find_last_not_of(" \t");
    if (start == std::string::npos)
        throw std::runtime_error("Error: missing value");
    valueStr = valueStr.substr(start, end - start + 1);

    size_t idx = 0;
    try {
        value = std::stof(valueStr, &idx);
    } catch (...) {
        throw std::runtime_error("Error: not a valid number");
    }
    if (idx != valueStr.size())
        throw std::runtime_error("Error: bad input format");
    if (value < 0)
        throw std::runtime_error("Error: not a positive number");
    if (value > 1000)
        throw std::runtime_error("Error: too large a number");
}