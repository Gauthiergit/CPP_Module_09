/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:06:18 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/01 15:51:55 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& input)
{
	this->tokens = split(input);
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN &change)
{
	this->tokens = change.tokens;
	return *this;
}

const char* RPN::InvalidToken::what() const throw()
{
	return ("Error: invalid token.");
}

void	RPN::calculate()
{
	float res = 0.0;
	float temp = 0.0;
	while(!this->tokens.empty())
	{
		if (isdigit(this->tokens.top()[0]))
			this->nbs.push(std::atof(this->tokens.top().c_str()));
		else
		{
			if (this->nbs.size() >= 2)
			{
				temp = this->nbs.top();
				this->nbs.pop();
				if (tokens.top()[0] == '+')
					res = this->nbs.top() + temp;
				else if (tokens.top()[0] == '-')
					res = this->nbs.top() - temp;
				else if (tokens.top()[0] == '*')
					res = this->nbs.top() * temp;
				else if (tokens.top()[0] == '/')
					res = this->nbs.top() / temp;
				this->nbs.pop();
				this->nbs.push(res);
			}
			else
				throw RPN::InvalidToken();
		}
		this->tokens.pop();
	}
}

void	RPN::displayRes()
{
	std::stack<int> revNbs;
	if (this->nbs.size() > 1)
	{
		while (!this->nbs.empty())
		{
			revNbs.push(this->nbs.top());
			this->nbs.pop();
		}
		while (!revNbs.empty())
		{
			std::cout << revNbs.top() << " ";
			revNbs.pop();
		}
		std::cout << std::endl;
	}
	else
		std::cout << this->nbs.top() << std::endl;
}