/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:25 by rjeong            #+#    #+#             */
/*   Updated: 2024/04/28 15:00:26 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Test 1: Normal construction and output
	std::cout << "Test 1: Normal construction and output" << std::endl;
	try {
		Bureaucrat b1("John", 100);
		std::cout << b1 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 2: Grade too high exception
	std::cout << "Test 2: Grade too high exception" << std::endl;
	try {
		Bureaucrat b2("Alice", 0);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 3: Grade too low exception
	std::cout << "Test 3: Grade too low exception" << std::endl;
	try {
		Bureaucrat b3("Bob", 151);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Increment and decrement grade
	std::cout << "Test 4: Increment and decrement grade" << std::endl;
	try {
		Bureaucrat b4("Charlie", 2);
		std::cout << b4 << std::endl;
		b4.incrementGrade();
		std::cout << "After increment: " << b4 << std::endl;
		b4.decrementGrade();
		std::cout << "After decrement: " << b4 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 5: Exception on incrementing highest grade
	std::cout << "Test 5: Exception on incrementing highest grade" << std::endl;
	try {
		Bureaucrat b5("David", 1);
		std::cout << b5 << std::endl;
		b5.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 6: Exception on decrementing lowest grade
	std::cout << "Test 6: Exception on decrementing lowest grade" << std::endl;
	try {
		Bureaucrat b6("Eve", 150);
		std::cout << b6 << std::endl;
		b6.decrementGrade();
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
