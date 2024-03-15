/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedropalomares <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:42:29 by pedropalomare     #+#    #+#             */
/*   Updated: 2023/11/10 22:42:34 by pedropalomare    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*prev;

	if (!*lst)
		return ;
	aux = (*lst)->next;
	ft_lstdelone(*lst, del);
	if (aux)
	{
		while (aux->next)
		{
			prev = aux->next;
			ft_lstdelone(aux, del);
			aux = prev;
		}
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}

/* int	main(void)
{
	char	*content1;
	char	*content2;
	char	*content3;
	t_list	*ptr1;
	t_list	*ptr2;
	t_list	*ptr3;
	t_list	**ptr;

	content1 = (char *)malloc(sizeof(char) * 2);
	content2 = (char *)malloc(sizeof(char) * 2);
	content3 = (char *)malloc(sizeof(char) * 2);
	*content1 = '1';
	content1[1] = 0;
	*content2 = '2';
	content2[1] = 0;
	*content3 = '3';
	content3[1] = 0;
	ptr1 = (t_list *)malloc(sizeof(t_list) * 1);
	ptr2 = (t_list *)malloc(sizeof(t_list) * 1);
	ptr3 = (t_list *)malloc(sizeof(t_list) * 1);
	ptr1->content = content1;
	ptr2->content = content2;
	ptr3->content = content3;
	ptr1->next = ptr2;
	ptr2->next = ptr3;
	ptr3->next = NULL;

	ptr = &ptr2;
	printf("Antes de usar clear\n");
	ft_lstiter(ptr1, prinit);

	ft_lstclear(ptr, free);

	printf("Después de usar clear\n");
	ft_lstiter(ptr1, prinit);
} */
