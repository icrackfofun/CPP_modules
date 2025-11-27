/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:36:04 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 17:19:05 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Empty"), _sign(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Empty Form Constructed." << std::endl;
}

Form::Form(const std::string &name, int sign_grade, int exec_grade)
: _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade > 150 || _exec_grade > 150) throw GradeTooLowException();
	else if (_sign_grade < 1 || _exec_grade < 1) throw GradeTooHighException();
	std::cout << "Form " << _name << " Constructed." << std::endl;
}

Form::Form(const Form &other)
: _name(other._name), _sign(other._sign), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	std::cout << "Form Copy Constructor Called." << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form Copy Assignment Operator Called." << std::endl;
	if (this != &other) _sign = other._sign;
	return *this;
}

Form::~Form() {std::cout << "Form " << _name << " Destroyed." << std::endl;}

const std::string	&Form::getName() const {return _name;}
bool				Form::getSigned() const {return _sign;}
int					Form::getSignGrade() const {return _sign_grade;}
int					Form::getExecGrade() const {return _exec_grade;}

void				Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _sign_grade) throw GradeTooLowException();
	_sign = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	std::string sign = (f.getSigned() == true) ? "signed" : "not signed";
	return out << "Form " << f.getName() << ", " << sign << ", grade " << f.getSignGrade() << " to sign, grade " << f.getExecGrade() << " to execute.";
}