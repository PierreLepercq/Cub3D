/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:41:06 by llepesqu          #+#    #+#             */
/*   Updated: 2025/12/04 15:46:02 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*new_node(void *content, void *(*f)(void *),
		void (*del)(void *))
{
	void	*new_content;
	t_list	*node;

	new_content = f(content);
	node = ft_lstnew(new_content);
	if (!node && new_content)
		del(new_content);
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	newlst = new_node(lst->content, f, del);
	if (!newlst)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = new_node(lst->content, f, del);
		if (!tmp)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}

/* On pourrait ajouter une verif sur le retour de f(lst->content) au
cas ou NULL :
void			*new_content;

new_content = f(lst->content);
newlst = ft_lstnew(new_content);
if (!newlst)
	{
		if (new_content)
			del(new_content);
		return (NULL);
	}

et faire le meme test dans le while>
*/