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
#include "Intern.hpp"
#include <iostream>

int main() {
	try {
		// Create an instance of the Intern class
		Intern someRandomIntern;
		AForm *rrf;

		std::cout << "===== Testing Intern =====" << std::endl;

		// Request to create a 'robotomy request' form
		std::cout << "\n---- Requesting 'robotomy request' form ----" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			// If a form was successfully created, print its details
			std::cout << "\n[Result]\n" << *rrf << std::endl;
			delete rrf;  // Delete the form to prevent memory leaks
		}

		// Request to create a 'presidential pardon' form
		std::cout << "\n---- Requesting 'presidential pardon' form ----" << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Criminal");
		if (rrf) {
			// If a form was successfully created, print its details
			std::cout << "\n[Result]\n" << *rrf << std::endl;
			delete rrf;  // Delete the form to prevent memory leaks
		}

		// Request to create a 'shrubbery creation' form
		std::cout << "\n---- Requesting 'shrubbery creation' form ----" << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
		if (rrf) {
			// If a form was successfully created, print its details
			std::cout << "\n[Result]\n" << *rrf << std::endl;
			delete rrf;  // Delete the form to prevent memory leaks
		}

		// Request an invalid form to check error handling
		std::cout << "\n---- Requesting invalid form 'invalid form' ----" << std::endl;
		rrf = someRandomIntern.makeForm("invalid form", "Nowhere");
		if (rrf) {
			delete rrf;  // This will not be executed as no valid form is created
		}

	} catch (const std::exception &e) {
		// If any unexpected exception occurs, print the error message
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
