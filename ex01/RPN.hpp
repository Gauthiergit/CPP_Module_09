/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:58:16 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/28 19:32:54 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stack>
#include <cstdlib>

class RPN
{
	private:
	
	std::stack<std::string> tokens;
	std::stack<int> nbs;

	public:

	RPN(const std::string& input);
	RPN(const RPN &copy);
	~RPN();

	RPN& operator=(const RPN &change);

	int	calculate();
};

std::stack<std::string> split(const std::string& input);
bool tokenIsValid(const std::string& token);

#endif