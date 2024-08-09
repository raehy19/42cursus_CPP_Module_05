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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat bureaucrat("John", 5);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Criminal");

		std::cout << bureaucrat << std::endl;

		bureaucrat.signForm(shrub);
		bureaucrat.executeForm(shrub);

		bureaucrat.signForm(robotomy);
		bureaucrat.executeForm(robotomy);

		bureaucrat.signForm(pardon);
		bureaucrat.executeForm(pardon);
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}