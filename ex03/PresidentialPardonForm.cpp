/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:47:48 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:47:49 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**
 * @brief Constructor with target parameter
 *
 * @param target Target of the form
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon", 25, 5), _target(target) {}

/**
 * @brief Copy constructor
 *
 * @param other Another instance of PresidentialPardonForm to copy
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {}

/**
 * @brief Assignment operator overload
 *
 * @param other Another instance of PresidentialPardonForm to assign from
 * @return PresidentialPardonForm& Reference to the assigned object
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

/**
 * @brief Destructor
 */
PresidentialPardonForm::~PresidentialPardonForm() {}

/**
 * @brief Execute the form's action, which is to pardon the target
 *
 * @param executor Bureaucrat who executes the form
 * @throw AForm::FormNotSignedException if the form is not signed
 * @throw AForm::GradeTooLowException if the executor's grade is too low
 */
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
