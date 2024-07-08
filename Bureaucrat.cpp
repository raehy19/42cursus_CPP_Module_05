/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:00:17 by rjeong            #+#    #+#             */
/*   Updated: 2024/04/28 15:00:18 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

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

// Constructor with name and grade
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

// Exception class implementation
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

// Function to return the name
const std::string &Bureaucrat::getName(void) const {
	return _name;
}

// Function to return the grade
int Bureaucrat::getGrade(void) const {
	return _grade;
}

// Function to increment the grade
void Bureaucrat::incrementGrade(void) {
	if (_grade <= 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

// Function to decrement the grade
void Bureaucrat::decrementGrade(void) {
	if (_grade >= 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

// << operator overloading
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}