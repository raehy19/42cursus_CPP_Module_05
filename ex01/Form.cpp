/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:58:20 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/09 01:58:22 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

///// Orthodox Canonical Form /////
// Default Constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Copy Constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
								_gradeToExecute(other._gradeToExecute) {}

// Assignment Operator Overloading
Form &Form::operator=(const Form &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
Form::~Form() {}

///// Member Functions /////
/// Constructor
// Constructor with name, gradeToSign, and gradeToExecute
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

/// Getters
// getName
const std::string &Form::getName() const { return _name; }

// getIsSigned
bool Form::getIsSigned() const { return _isSigned; }

// getGradeToSign
int Form::getGradeToSign() const { return _gradeToSign; }

// getGradeToExecute
int Form::getGradeToExecute() const { return _gradeToExecute; }

/// Member function
// beSigned
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

/// Exception Classes
// GradeTooHighException
const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

// GradeTooLowException
const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

///// Operator Overloading /////
// << operator overloading
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() << ":"
	   << "\nSigned: " << (form.getIsSigned() ? "Yes" : "No")
	   << "\nGrade to sign: " << form.getGradeToSign()
	   << "\nGrade to execute: " << form.getGradeToExecute();
	return os;
}