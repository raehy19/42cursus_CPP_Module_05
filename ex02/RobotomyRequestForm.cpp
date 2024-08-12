/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:47:21 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:47:22 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/**
 * @brief Constructor with target parameter
 *
 * @param target Target of the form
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("Robotomy Request", 72, 45), _target(target) {
	srand(time(0)); // Seed the random number generator
}

/**
 * @brief Copy constructor
 *
 * @param other Another instance of RobotomyRequestForm to copy
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {}

/**
 * @brief Assignment operator overload
 *
 * @param other Another instance of RobotomyRequestForm to assign from
 * @return RobotomyRequestForm& Reference to the assigned object
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/**
 * @brief Destructor
 */
RobotomyRequestForm::~RobotomyRequestForm() {}

/**
 * @brief Execute the form's action, which is to attempt to robotomize the target
 *
 * @param executor Bureaucrat who executes the form
 * @throw AForm::FormNotSignedException if the form is not signed
 * @throw AForm::GradeTooLowException if the executor's grade is too low
 */
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	if (rand() % 2) {
		std::cout << "Grrrrrr... Drilling noises..." << std::endl;
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "The robotomy failed." << std::endl;
	}
}
