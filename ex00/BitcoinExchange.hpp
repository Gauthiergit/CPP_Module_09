/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:57:53 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/02 11:51:37 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class BitcoinExchange
{
	private:
	
	std::map<std::string,float> mymap;

	public:
	BitcoinExchange(const std::string file);
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange();

	BitcoinExchange& operator=(const BitcoinExchange &change);

	std::pair<std::map<std::string,float>::iterator, bool> findRate(const std::string& date);
};

std::string findDate(const std::string &line, const char sep);
float getValue(const std::string &line, const char sep);

#endif