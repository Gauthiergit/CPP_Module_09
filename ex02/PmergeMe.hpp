/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:53:50 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/03 11:59:32 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


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
		for (int i = 0; argv[i]; i++)
			this->ct_input.push_back(argv[i]);
	}

	PmergeMe(const PmergeMe &copy){*this = copy}
	~PmergeMe(){}

	PmergeMe& operator=(const PmergeMe &change)
	{
		this->ct_input = change.ct_input;
		return (*this);
	}

	template< typename Ct >
	void fordJohnsonVecSort()
	{
		if (this->ct_input.size() <= 1) return;

		std::vector<Ct> pairs;
		Ct::iterator it = this->ct_input.begin();
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
};

#endif