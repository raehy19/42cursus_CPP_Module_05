/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:48:08 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/09 01:48:09 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		///// Orthodox Canonical Form /////
		// Default Constructor
		Bureaucrat(void);

		// Copy Constructor
		Bureaucrat(const Bureaucrat &bureaucrat);

		// Assignment Operator Overloading
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		// Destructor
		~Bureaucrat(void);

		///// Member Functions /////
		/// Constructor
		// Constructor with name and grade
		Bureaucrat(const std::string &name, int grade);

		/// Exception Classes
		// GradeTooHighException
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		// GradeTooLowException
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		/// Getters
		// getName
		const std::string &getName(void) const;

		// getGrade
		int getGrade(void) const;

		/// Grade Modifiers
		// incrementGrade
		void incrementGrade(void);

		// decrementGrade
		void decrementGrade(void);

		///// signForm Added /////
		void signForm(Form &form);

};

///// Operator Overloading /////
// << operator overloading
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif