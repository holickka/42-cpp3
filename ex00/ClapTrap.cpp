/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsim <hsim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:26:53 by hsim              #+#    #+#             */
/*   Updated: 2025/08/26 21:33:46 by hsim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default constructor called" << std::endl;
	this->name = name;
	this->hit_point = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old_obj)
{
	*this = old_obj;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &old_obj)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this == &old_obj)
		return (*this);
	this->name = old_obj.name;
	this->attack_damage = old_obj.attack_damage;
	this->hit_point = old_obj.hit_point;
	this->energy_point = old_obj.energy_point;
	return (*this);
}

void	ClapTrap::printError(void)
{
	std::cout	<< "ClapTrap " << this->name
				<< " has insufficient health or energy to execute action!"
				<< std::endl;
}

void	ClapTrap::printStat(void)
{
	std::cout	<< "┌─ " << this->name
				<< "\n|  Health: " << this->hit_point
				<< "\n|  Energy: " << this->energy_point
				<< std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		printError();
		return ;
	}

	std::cout	<< "ClapTrap " << this->name
				<< " attacks " << target
				<< ", causing " << this->attack_damage
				<< " points of damage!"
				<< std::endl;
	this->energy_point -= 1;
	printStat();

}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< "ClapTrap " << this->name
				<< " takes in " << amount
				<< " points of damage!"
				<< std::endl;
	this->hit_point -= amount;
	printStat();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_point <= 0 || this->energy_point <= 0)
	{
		printError();
		return ;
	}
	std::cout	<< "ClapTrap " << this->name
				<< " gets repaired by " << amount
				<< " points!"
				<< std::endl;

	this->hit_point += amount;
	this->energy_point -= 1;
	printStat();
}
