/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:19:07 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/25 08:19:09 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		///// Orthodox Canonical Form /////
		// Default Constructor
		AForm();

		// Copy Constructor
		AForm(const AForm &other);

		// Assignment Operator Overloading
		AForm &operator=(const AForm &other);

		// Destructor
		~AForm();

		///// Member Functions /////
		/// Constructor
		// Constructor with name, gradeToSign, and gradeToExecute
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);

		/// Getters
		// getName
		const std::string &getName() const;

		// getIsSigned
		bool getIsSigned() const;

		// getGradeToSign
		int getGradeToSign() const;

		// getGradeToExecute
		int getGradeToExecute() const;

		/// Member functions
		// beSigned
		void beSigned(const Bureaucrat &bureaucrat);

		// execute added
		virtual void execute(Bureaucrat const & executor) const = 0;

		/// Exception Classes
		// GradeTooHighException
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		// GradeTooLowException
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		// FormNotSignedException
		class FormNotSignedException : public std::exception {
			public:
				const char* what() const throw();
		};

};

///// Operator Overloading /////
// << operator overloading
std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif