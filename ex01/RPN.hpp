/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:58:16 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/01 15:58:14 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stack>
#include <stdexcept>

class RPN
{
	private:
	
	std::stack<std::string> tokens;
	std::stack<float> nbs;

	public:

	class InvalidToken : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};

	RPN(const std::string& input);
	RPN(const RPN &copy);
	~RPN();

	RPN& operator=(const RPN &change);

	void	calculate();
	void	displayRes();
};

std::stack<std::string> split(const std::string& input);
bool tokenIsValid(const std::string& token);

#endif