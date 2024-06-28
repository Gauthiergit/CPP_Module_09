/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:06:18 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/28 19:34:48 by gpeyre           ###   ########.fr       */
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

int	RPN::calculate()
{
	int res = 0;
	while(!this->tokens.empty())
	{
		if (isdigit(this->tokens.top()[0]))
			this->nbs.push(std::atoi(this->tokens.top().c_str()));
		else
		{
			if (this->nbs.size() == 2)
			{
				res = this->nbs.top();
				this->nbs.pop();
				if (tokens.top()[0] == '+')
					res += this->nbs.top();
				else if (tokens.top()[0] == '-')
					res -= this->nbs.top();
				else if (tokens.top()[0] == '*')
					res *= this->nbs.top();
				else if (tokens.top()[0] == '/')
					res /= this->nbs.top();
				this->nbs.pop();
				this->nbs.push(res);
			}
			else
			{
				std::cout << "Error: Invalid Token." << std::endl;
				exit(1);
			}
		}
		this->tokens.pop();
	}
	return (this->nbs.top());
}
