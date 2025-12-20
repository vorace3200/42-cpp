#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	this->_parseDb();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
	if (this != &src) {
		this->_data = src._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::_parseDb(void) {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: could not open data.csv" << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line); 

	while (std::getline(file, line)) {
		size_t delim = line.find(',');
		if (delim == std::string::npos)
			continue;
		
		std::string date = line.substr(0, delim);
		std::string valueStr = line.substr(delim + 1);
		
		float value = std::atof(valueStr.c_str());
		this->_data[date] = value;
	}
	file.close();
}

bool BitcoinExchange::_isValidDate(const std::string& date) const {
	if (date.length() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2022) return false; 
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;

	if (month == 2) {
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28)) return false;
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) return false;
	}
	
	return true;
}

bool BitcoinExchange::_isValidValue(const float& value) const {
	return value >= 0 && value <= 1000;
}

void BitcoinExchange::run(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::string line;
	std::getline(file, line); 

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		size_t delim = line.find('|');
		if (delim == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		std::string valueStr = line.substr(delim + 1);

		if (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		if (!valueStr.empty() && valueStr[0] == ' ')
			valueStr.erase(0, 1);
		
		if (!this->_isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		char* end;
		double val = std::strtod(valueStr.c_str(), &end);
		
		if (val < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (val > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (valueStr != "0" && val == 0 && end == valueStr.c_str()) { 
			std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

		std::map<std::string, float>::iterator it = this->_data.lower_bound(date);
		
		if (it->first != date) {
			if (it == this->_data.begin()) {
				std::cout << "Error: no data valid for this date." << std::endl;
				continue;
			}
			--it;
		}
		
		std::cout << date << " => " << valueStr << " = " << val * it->second << std::endl;
	}
	file.close();
}
