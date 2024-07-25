/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeong <rjeong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:58:27 by rjeong            #+#    #+#             */
/*   Updated: 2024/07/09 01:58:28 by rjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		///// Orthodox Canonical Form /////
		// Default Constructor
		Form();

		// Copy Constructor
		Form(const Form &other);

		// Assignment Operator Overloading
		Form &operator=(const Form &other);

		// Destructor
		~Form();

		///// Member Functions /////
		/// Constructor
		// Constructor with name, gradeToSign, and gradeToExecute
		Form(const std::string &name, int gradeToSign, int gradeToExecute);

		/// Getters
		// getName
		const std::string &getName() const;

		// getIsSigned
		bool getIsSigned() const;

		// getGradeToSign
		int getGradeToSign() const;

		// getGradeToExecute
		int getGradeToExecute() const;

		/// Member function
		// beSigned
		void beSigned(const Bureaucrat &bureaucrat);

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
};

///// Operator Overloading /////
// << operator overloading
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif