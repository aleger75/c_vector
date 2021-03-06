/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:11:51 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/15 02:06:53 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "c_vector.h"

static void			init_pointers(t_vector **self)
{
	(*self)->pop = &vector_pop;
	(*self)->push = &vector_push;
	(*self)->free = c_vector_free;
	(*self)->each = c_vector_each;
	(*self)->map = c_vector_map;
	(*self)->remove = c_vector_remove;
	(*self)->v_capacity = &vector_capacity;
	(*self)->is_empty = &vector_is_empty;
	(*self)->at = &vector_at;
	(*self)->size = &vector_size;
	(*self)->front = &vector_front;
	(*self)->back = &vector_back;
	(*self)->swap = &vector_swap;
	(*self)->data = &vector_data;
	(*self)->push_front = &vector_push_front;
	(*self)->pop_front = &vector_pop_front;
}

t_vector			*new_vector(size_t elt_size, void (*_delete)(void *))
{
	t_vector		*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (v)
	{
		v->count = 0;
		v->cursor = 0;
		v->capacity = VECTOR_INIT_SIZE;
		v->content = vector_memalloc(elt_size * v->capacity);
		v->elt_size = elt_size;
		init_pointers(&v);
		v->delete_function = _delete != NULL ? _delete : NULL;
	}
	return (v);
}
