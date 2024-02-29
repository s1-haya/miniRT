/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:33:51 by hsawamur          #+#    #+#             */
/*   Updated: 2023/01/13 21:48:28 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	boolean;

	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		boolean = 1;
	else
		boolean = 0;
	return (boolean);
}

// int main()
// {
// 	  // declaring character variable
//   char ch = 'd';

//   // checking whether ch is an uppercase alphabet or not
//   if (ft_isalpha(ch)) {
//     printf("%c is an Uppercase Letter", ch);
//   } else {
//     printf("%c is not an Uppercase Letter", ch);
//   }
// 	return (0);
// }