/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:40 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/02 11:51:48 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string file)
{
	std::ifstream data(file.c_str());
	if (!data.is_open())
	{
		std::cerr << RED << "Error to open data file." << RESET << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		this->mymap.insert(std::pair<std::string, float>(findDate(line, ','), getValue(line, ',')));
	}
	data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &change)
{
	this->mymap.clear();
	this->mymap = change.mymap;
	return *this;
}

std::pair<std::map<std::string,float>::iterator, bool> BitcoinExchange::findRate(const std::string& date)
{
	std::map<std::string,float>::iterator it;
	it = this->mymap.find(date);
	if (it == mymap.end())
	{
		it = this->mymap.lower_bound(date);
		if (it == this->mymap.begin())
			return std::make_pair(this->mymap.end(), false);
    	else if (it == this->mymap.end() || it->first > date)
        	--it;
	}
	return std::make_pair(it, true);
}
