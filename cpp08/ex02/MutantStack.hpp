/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:10:57 by cprojean          #+#    #+#             */
/*   Updated: 2024/04/03 19:53:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>
# include <iterator>

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
	public :
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack &toCopy)
        {
            *this = toCopy;
        }
        typedef typename container::iterator iterator;
		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
};

#endif