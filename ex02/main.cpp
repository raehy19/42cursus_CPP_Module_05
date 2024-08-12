/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:46:21 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:46:22 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	try {
		// Bureaucrats with different grades
		Bureaucrat highRank("High Rank", 1);   // Highest rank
		Bureaucrat midRank("Mid Rank", 50);    // Middle rank
		Bureaucrat lowRank("Low Rank", 150);   // Lowest rank

		std::cout << "===== Testing ShrubberyCreationForm =====" << std::endl;
		// Creating a ShrubberyCreationForm
		ShrubberyCreationForm shrubForm("AAA");

		// Attempt to sign and execute the form with different bureaucrats
		try {
			std::cout << "---- Attempting to sign ShrubberyCreationForm with Mid Rank Bureaucrat ----" << std::endl;
			shrubForm.beSigned(midRank); // Should be successful
			std::cout << "Result: Form signed successfully!" << std::endl;

			std::cout << "---- Attempting to execute ShrubberyCreationForm with Mid Rank Bureaucrat ----" << std::endl;
			midRank.executeForm(shrubForm);  // Using executeForm method
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "===== Testing RobotomyRequestForm =====" << std::endl;
		// Creating a RobotomyRequestForm
		RobotomyRequestForm robotForm("Target");

		// Attempt to sign the form with a bureaucrat of too low grade
		try {
			std::cout << "---- Attempting to sign RobotomyRequestForm with Low Rank Bureaucrat ----" << std::endl;
			robotForm.beSigned(lowRank);  // Should throw exception
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		// Signing and executing the form with a suitable bureaucrat
		try {
			std::cout << "---- Attempting to sign RobotomyRequestForm with Mid Rank Bureaucrat ----" << std::endl;
			robotForm.beSigned(midRank);   // Should be successful
			std::cout << "Result: Form signed successfully!" << std::endl;

			std::cout << "---- Attempting to execute RobotomyRequestForm with Mid Rank Bureaucrat ----" << std::endl;
			midRank.executeForm(robotForm);    // Using executeForm method

			std::cout << "---- Attempting to execute RobotomyRequestForm with High Rank Bureaucrat ----" << std::endl;
			highRank.executeForm(robotForm);   // Using executeForm method
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "===== Testing PresidentialPardonForm =====" << std::endl;
		// Creating a PresidentialPardonForm
		PresidentialPardonForm pardonForm("Criminal");

		// Attempt to execute without signing
		try {
			std::cout << "---- Attempting to execute PresidentialPardonForm with High Rank Bureaucrat without signing ----" << std::endl;
			highRank.executeForm(pardonForm);  // Should throw exception
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		// Signing and executing with a suitable bureaucrat
		try {
			std::cout << "---- Attempting to sign PresidentialPardonForm with High Rank Bureaucrat ----" << std::endl;
			pardonForm.beSigned(highRank);  // Should be successful
			std::cout << "Result: Form signed successfully!" << std::endl;

			std::cout << "---- Attempting to execute PresidentialPardonForm with High Rank Bureaucrat ----" << std::endl;
			highRank.executeForm(pardonForm);   // Using executeForm method
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "===== Testing Exceptions =====" << std::endl;
		// Trying to execute a form with a bureaucrat of insufficient grade
		try {
			std::cout << "---- Attempting to execute PresidentialPardonForm with Mid Rank Bureaucrat ----" << std::endl;
			midRank.executeForm(pardonForm);  // Should throw exception due to low grade
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}

	} catch (const std::exception &e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
