/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:31:50 by gpeyre            #+#    #+#             */
/*   Updated: 2024/07/03 17:49:26 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void isItDigit(int argc, char **argv)
{
	size_t j;
	for (int i = 1; i < argc; i++)
	{
		j = 0;
		for (; j < strlen(argv[i]); j++)
		{
			if (!isdigit(argv[i][j]))
				throw InvalidInput();
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << RED << "Use: " << argv[0] << " <nb> <nb> .." << RESET << std::endl;
		return (1);
	}
	try
	{
		isItDigit(argc, argv);
		std::cout << GREEN << "Vector" << RESET << std::endl;
		PmergeMe< std::vector<int> > sortThat(argv);
		std::cout << "Before : ";
		sortThat.displayRes();
		std::clock_t start = std::clock();
		sortThat.fordJohnsonVecSort();
		std::clock_t end = std::clock();
		double elapsedTimeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "After : ";
		sortThat.displayRes();
		std::cout << "Time to process of "<< argc - 1 << " elements with "<<
			GREEN << "std::vector" << RESET << " : " << elapsedTimeVec << " us" << std::endl;
		std::cout << "-----------------------------------------------" << std::endl;
		std::cout << GREEN << "List" << RESET << std::endl;
		PmergeMe< std::list<int> > sortThis(argv);
		std::cout << "Before : ";
		sortThis.displayRes();
		start = std::clock();
		sortThis.fordJohnsonListSort();
		end = std::clock();
		double elapsedTimeLst = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "After : ";
		sortThis.displayRes();
		std::cout << "Time to process of "<< argc - 1 << " elements with "<<
			GREEN << "std::list" << RESET << " : " << elapsedTimeLst << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	return 0;
}
