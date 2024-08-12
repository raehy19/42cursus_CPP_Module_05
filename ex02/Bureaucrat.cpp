/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:47:57 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/09 01:47:59 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

///// Orthodox Canonical Form /////
// Default Constructor
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade) {
	// Copy constructor, copying name and grade
}

// Assignment Operator Overloading
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this != &bureaucrat) {
		this->_grade = bureaucrat._grade;
	}
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	// No action needed
}

///// Member Functions /////
/// Constructor
// Constructor with name and grade
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

/// Exception Classes
// GradeTooHighException
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

// GradeTooLowException
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

/// Getters
// getName
const std::string &Bureaucrat::getName(void) const {
	return _name;
}

// getGrade
int Bureaucrat::getGrade(void) const {
	return _grade;
}

/// Grade Modifiers
// incrementGrade
void Bureaucrat::incrementGrade(void) {
	if (_grade <= 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

// decrementGrade
void Bureaucrat::decrementGrade(void) {
	if (_grade >= 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

///// Operator Overloading /////
// << operator overloading
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

///// signForm /////
void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

//// executeForm Added /////
void Bureaucrat::executeForm(AForm const &form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}