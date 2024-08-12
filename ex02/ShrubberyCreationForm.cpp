/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:21:28 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:21:37 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/**
 * @brief Constructor with target parameter
 *
 * @param target Target of the form
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) {}

/**
 * @brief Copy constructor
 *
 * @param other Another instance of ShrubberyCreationForm to copy
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

/**
 * @brief Assignment operator overload
 *
 * @param other Another instance of ShrubberyCreationForm to assign from
 * @return ShrubberyCreationForm& Reference to the assigned object
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/**
 * @brief Destructor
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/**
 * @brief Execute the form's action, which is to create a shrubbery file
 *
 * @param executor Bureaucrat who executes the form
 * @throw AForm::FormNotSignedException if the form is not signed
 * @throw AForm::GradeTooLowException if the executor's grade is too low
 */
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (ofs.fail()) {
		std::cerr << "Failed to open file: " << _target << "_shrubbery" << std::endl;
		return;
	}
	ofs << "       _-_" << std::endl;
	ofs << "    /~~   ~~\\" << std::endl;
	ofs << " /~~         ~~\\" << std::endl;
	ofs << "{               }" << std::endl;
	ofs << " \\  _-     -_  /" << std::endl;
	ofs << "   ~  \\ //  ~" << std::endl;
	ofs << "_- -   | | _- _" << std::endl;
	ofs << "  _ -  | |   -_" << std::endl;
	ofs << "      // \\" << std::endl;
	ofs.close();
}
