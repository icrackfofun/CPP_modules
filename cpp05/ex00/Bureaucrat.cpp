/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psantos- <psantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:05:58 by psantos-          #+#    #+#             */
/*   Updated: 2025/11/27 14:26:42 by psantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Empty"), _grade(150)
{
	std::cout << "Empty Bureaucrat Constructed." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade > 150) throw GradeTooLowException();
	else if (grade < 1) throw GradeTooHighException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " Constructed." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat Copy Constructor Called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Copy Assignment Operator Called." << std::endl;
	if (this != &other) _grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {std::cout << "Bureaucrat " << _name << " Destroyed." << std::endl;}

const std::string	&Bureaucrat::getName() const {return _name;}

int					Bureaucrat::getGrade() const {return _grade;}

void				Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1) throw GradeTooHighException();
	_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150) throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low!";
}

std::ostream		&operator<<(std::ostream &out, const Bureaucrat &b)
{
	return out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}