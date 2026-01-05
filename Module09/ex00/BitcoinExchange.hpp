#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> data;
		
		void	parse_db(void);
		bool	is_valid_date(const std::string& date) const;
		bool	is_valid_value(const float& value) const;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void	run(const std::string& filename);
};

#endif
