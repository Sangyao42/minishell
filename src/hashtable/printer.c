/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthonytsang <anthonytsang@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 01:38:36 by anthonytsan       #+#    #+#             */
/*   Updated: 2023/05/22 12:42:43 by anthonytsan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINISHELL/hashtable.h"
#include <stdio.h>

void	ht_print(t_ht *ht)
{
	size_t				i;
	struct s_ht_entry	*entry;

	i = 0;
	while (i < ht->capacity)
	{
		entry = vector_get(ht, i);
		if (entry->key)
			printf("%s: %s", entry->key, (char *) entry->value);
		else
			printf("EMPTY");
		if (entry->deleted)
			printf(" (deleted)\n");
		else
			printf("\n");
		i++;
	}
	printf("\n");
}
