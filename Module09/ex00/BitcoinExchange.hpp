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
		std::map<std::string, float> _data;
		
		void	_parseDb(void);
		bool	_isValidDate(const std::string& date) const;
		bool	_isValidValue(const float& value) const;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void	run(const std::string& filename);
};

#endif
