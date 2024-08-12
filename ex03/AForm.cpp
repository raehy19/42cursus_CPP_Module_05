/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:20:43 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:20:51 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

///// Orthodox Canonical AForm /////
// Default Constructor
AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Copy Constructor
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
								_gradeToExecute(other._gradeToExecute) {}

// Assignment Operator Overloading
AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
AForm::~AForm() {}

///// Member Functions /////
/// Constructor
// Constructor with name, gradeToSign, and gradeToExecute
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

/// Getters
// getName
const std::string &AForm::getName() const { return _name; }

// getIsSigned
bool AForm::getIsSigned() const { return _isSigned; }

// getGradeToSign
int AForm::getGradeToSign() const { return _gradeToSign; }

// getGradeToExecute
int AForm::getGradeToExecute() const { return _gradeToExecute; }

/// Member functions
// beSigned
void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

// execute
// should not be implemented in AForm class

/// Exception Classes
// GradeTooHighException
const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

// GradeTooLowException
const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

// FormNotSignedException
const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

///// Operator Overloading /////
// << operator overloading
std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() << ":"
	   << "\nSigned: " << (form.getIsSigned() ? "Yes" : "No")
	   << "\nGrade to sign: " << form.getGradeToSign()
	   << "\nGrade to execute: " << form.getGradeToExecute();
	return os;
}