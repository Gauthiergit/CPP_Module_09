/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:29:14 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/01 15:53:54 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool tokenIsValid(const std::string& token)
{
	if (token.size() == 1)
	{
		if (isdigit(token[0]) || token[0] == '+' || token[0] == '-'
			|| token[0] == '*' || token[0] == '/')
			return true;
	}
	return false;
}

std::stack<std::string> split(const std::string& input)
{
	std::stack<std::string> tokens;
	std::stack<std::string> revTokens;
	size_t start = 0;
	size_t end = input.find(' ');

	while (end != std::string::npos)
	{
		tokens.push(input.substr(start, end - start));
		start = end + 1;
		end = input.find(' ', start);
	}
	tokens.push(input.substr(start));
	while (!tokens.empty())
	{
		if(tokenIsValid(tokens.top()))
		{
			revTokens.push(tokens.top());
			tokens.pop();
		}
		else
			throw RPN::InvalidToken();
	}
	return revTokens;
}


int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Use: ./RPN <calcul>." << std::endl;
		return 1;
	}
	try
	{
		RPN myRPN(argv[1]);
		myRPN.calculate();
		myRPN.displayRes();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
