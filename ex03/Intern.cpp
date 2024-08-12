/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:48:16 by rjeong            #+#    #+#             */
/*   Updated: 2024/08/12 14:48:17 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/**
 * @brief Default constructor for Intern
 */
Intern::Intern() {}

/**
 * @brief Copy constructor for Intern
 */
Intern::Intern(const Intern &other) {
	*this = other;
}

/**
 * @brief Assignment operator for Intern
 */
Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

/**
 * @brief Destructor for Intern
 */
Intern::~Intern() {}

/**
 * @brief Function to create a ShrubberyCreationForm
 *
 * @param target The target of the form
 * @return A new ShrubberyCreationForm object
 */
AForm *createShrubberyForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

/**
 * @brief Function to create a RobotomyRequestForm
 *
 * @param target The target of the form
 * @return A new RobotomyRequestForm object
 */
AForm *createRobotomyForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

/**
 * @brief Function to create a PresidentialPardonForm
 *
 * @param target The target of the form
 * @return A new PresidentialPardonForm object
 */
AForm *createPresidentialForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

/**
 * @brief Creates a form based on the given form name and target
 *
 * @param formName The name of the form to create
 * @param target The target of the form
 * @return A pointer to the created form, or nullptr if the form name is invalid
 */
AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	// Array of form names
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	// Array of corresponding form creation functions
	AForm* (*formCreators[3])(const std::string &target) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm
	};

	// Iterate through form names to find a match
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	// If no match found, return nullptr and print error
	std::cerr << "Error: Form name " << formName << " is invalid" << std::endl;
	return nullptr;
}

