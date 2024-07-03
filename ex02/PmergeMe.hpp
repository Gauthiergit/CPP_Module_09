/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:53:50 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/03 17:38:05 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>

#define BLUE "\033[94m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"


class InvalidInput : public std::exception
{
	public:

	virtual const char* what() const throw()
	{
		return ("Error.");
	}
};

template< typename It >
void merge(It result, It begin1, It end1, It begin2, It end2)
{
	while (begin1 != end1 && begin2 != end2)
	{
		if (*begin1 < *begin2)
		{
			*result = *begin1;
			++begin1;
		} 
		else
		{
			*result = *begin2;
			++begin2;
		}
		++result;
	}
	while (begin1 != end1)
	{
		*result = *begin1;
		++begin1;
		++result;
	}
	while (begin2 != end2)
	{
		*result = *begin2;
		++begin2;
		++result;
	}
}

template< typename Ct >
class PmergeMe
{
	private:

	Ct ct_input;

	public:

	PmergeMe<Ct>(char **argv)
	{
		int nb = 0;
		for (int i = 1; argv[i]; i++)
		{
			nb = atoi(argv[i]);
			if (nb < 0)
				throw InvalidInput();
			else
				this->ct_input.push_back(nb);
		}
	}

	PmergeMe(const PmergeMe &copy){*this = copy;}
	~PmergeMe(){}

	PmergeMe& operator=(const PmergeMe &change)
	{
		this->ct_input = change.ct_input;
		return (*this);
	}

	
	void fordJohnsonVecSort()
	{
		if (this->ct_input.size() <= 1) return;

		std::vector<Ct> pairs;
		typename Ct::iterator it = this->ct_input.begin();
		while (it != this->ct_input.end())
		{
			Ct pair;
			pair.push_back(*it);
			++it;
			if (it != this->ct_input.end())
			{
				pair.push_back(*it);
				++it;
			}
			std::sort(pair.begin(), pair.end());
			pairs.push_back(pair);
		}

		while (pairs.size() > 1)
		{
			std::vector<Ct> newPairs;
			for (size_t i = 0; i < pairs.size(); i += 2)
			{
				if (i + 1 < pairs.size())
				{
					Ct merged;
					merged.resize(pairs[i].size() + pairs[i + 1].size());
					merge(merged.begin(), pairs[i].begin(), pairs[i].end(), pairs[i + 1].begin(), pairs[i + 1].end());
					newPairs.push_back(merged);
				}
				else
					newPairs.push_back(pairs[i]);
			}
			pairs = newPairs;
		}
		this->ct_input = pairs[0];
	}

	void fordJohnsonListSort()
	{
		if (this->ct_input.size() <= 1) return;

		std::vector<Ct> pairs;
		typename Ct::iterator it = this->ct_input.begin();
		while (it != this->ct_input.end())
		{
			Ct pair;
			pair.push_back(*it);
			++it;
			if (it != this->ct_input.end())
			{
				pair.push_back(*it);
				++it;
			}
			pair.sort();
			pairs.push_back(pair);
		}

		while (pairs.size() > 1)
		{
			std::vector<Ct> newPairs;
			for (size_t i = 0; i < pairs.size(); i += 2)
			{
				if (i + 1 < pairs.size())
				{
					Ct merged;
					merged.resize(pairs[i].size() + pairs[i + 1].size());
					merge(merged.begin(), pairs[i].begin(), pairs[i].end(), pairs[i + 1].begin(), pairs[i + 1].end());
					newPairs.push_back(merged);
				}
				else
					newPairs.push_back(pairs[i]);
			}
			pairs = newPairs;
		}
		this->ct_input = pairs[0];
	}

	void displayRes()
	{
		if (this->ct_input.size() <= 10)
		{
			for (typename Ct::iterator it = this->ct_input.begin(); it != this->ct_input.end(); ++it)
				std::cout << *it << " ";
		}
		else
		{
			typename Ct::iterator it = this->ct_input.begin();	
			for (int i = 0; i < 4 && it != this->ct_input.end(); i++, ++it)
				std::cout << *it << " ";
			std::cout << "[...]";
		}
		std::cout << std::endl;
	}
};

#endif