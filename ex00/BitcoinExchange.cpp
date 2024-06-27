/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:27:40 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/27 18:55:15 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file)
{
	std::ifstream data(file.c_str());
	if (!data.is_open())
	{
		std::cerr << RED << "Error to open infile" << RESET << std::endl;
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
	this->mymap.clear();
	for (std::map<std::string,float>::iterator it = copy.mymap.begin(); it != copy.mymap.end(); it++)
		

}