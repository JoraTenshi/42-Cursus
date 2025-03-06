/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:41:05 by jcallejo          #+#    #+#             */
/*   Updated: 2025/03/06 10:55:41 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG_MSG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
#define INFO_MSG "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING_MSG "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

#define DEBUG "DEBUG"
#define INFO "INFO"
#define WARNING "WARNING"
#define ERROR "ERROR"

class Harl
{
	private:
		void	debug ( void );
		void	info ( void );
		void	warning ( void );
		void	error ( void );
	
	public:
	
		/**
		 * @brief Construct a new Harl object
		 * 
		 */
		Harl();
		
		/**
		 * @brief Destroy the Harl object
		 * 
		 */
		~Harl();

		/**
		 * @brief Calls any of the four privates depending on level passed
		 * 
		 * @param level 
		 */
		void complain( std::string level );
};

typedef void (Harl::*t_harl) (void);

#endif