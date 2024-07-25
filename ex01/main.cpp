/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 02:14:59 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/09 02:15:00 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		// Test 1: Create a valid form and bureaucrat
		std::cout << "Test 1: Valid form and bureaucrat" << std::endl;
		Form form1("Tax Form", 50, 25);
		Bureaucrat bob("Bob", 40);
		std::cout << form1 << std::endl;
		std::cout << bob << std::endl;
		bob.signForm(form1);
		std::cout << form1 << std::endl;
		std::cout << std::endl;

		// Test 2: Bureaucrat's grade too low to sign
		std::cout << "Test 2: Bureaucrat's grade too low" << std::endl;
		Form form2("Top Secret", 20, 10);
		Bureaucrat alice("Alice", 30);
		std::cout << form2 << std::endl;
		std::cout << alice << std::endl;
		alice.signForm(form2);
		std::cout << form2 << std::endl;
		std::cout << std::endl;

		// Test 3: Create form with invalid grades
		std::cout << "Test 3: Form with invalid grades" << std::endl;
		Form form3("Invalid Form", 0, 151);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test 4: Create bureaucrat with invalid grade
	try {
		std::cout << "Test 4: Bureaucrat with invalid grade" << std::endl;
		Bureaucrat charlie("Charlie", 160);
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}