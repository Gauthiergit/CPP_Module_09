/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:01:11 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/28 10:58:27 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string findDate(const std::string &line, const char sep)
{
	std::size_t pos = line.find(sep);
	if (pos != std::string::npos)
		return line.substr(0, pos);
	return line;
}

bool isValid(const std::string &line)
{
	int year, month, day;
	long 	value;
	char sep1, sep2, sep3, sep4, sep5;

	int numElem = sscanf(line.c_str(), "%d%c%d%c%d%c%c%c%ld",
		&year, &sep1, &month, &sep2, &day, &sep3, &sep4, &sep5, &value);

	if(numElem != 9 || sep1 != '-' || sep2 != '-' || sep3 != ' ' || sep4 != '|' || sep5 != ' '
		|| year < 0 || month < 0 || month > 12 || day < 0 || day > 31)
	{
		std::cerr << "Error: bad input => " << line << std::endl;	
		return false;
	}
	if (value < 0)
	{
		std::cerr << "Error: Not a positive number." << std::endl;
		return false;
	}
	else if (value > 1000)
	{
		std::cerr << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

float getValue(const std::string &line, const char sep)
{
	std::size_t pos = line.find(sep);
	std::string svalue;
	float			fvalue;
	if (pos != std::string::npos)
		svalue = line.substr(pos + 1);
	fvalue = std::atof(svalue.c_str());
	return fvalue;
}


int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << RED << "Use: ./btc <file>." << RESET << std::endl;
		return 1;
	}
	std::string infile_name = argv[1];
	std::ifstream infile(infile_name.c_str());
	if (!infile.is_open())
	{
		std::cerr << RED << "Error to open input file." << RESET << std::endl;
		return (1);
	}
	BitcoinExchange bitcoin("data.csv");
	std::string line;
	std::map<std::string,float>::iterator it;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (isValid(line))
		{
			std::string date = findDate(line, ' ');
			it = bitcoin.findRate(date);
			float value = getValue(line, '|');
			float result = value * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
	infile.close();
	return 0;
}
