#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		
		void	run(const std::string& filename);
	private:
		std::map<std::string, float> data;
		
		void	parse_db(void);
		bool	is_valid_date(const std::string& date) const;
		bool	is_valid_value(const float& value) const;
};
