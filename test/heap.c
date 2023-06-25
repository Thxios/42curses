
#include <stdlib.h>

typedef int	t_elem;

typedef struct	s_heap
{
	int		capacity;
	int		size;
	t_elem	*arr;
}	t_heap;

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cptr;
	char	*src_cptr;
	size_t	idx;

	src_cptr = (char *)src;
	dest_cptr = (char *)dest;
	idx = 0;
	while (idx < n)
	{
		dest_cptr[idx] = src_cptr[idx];
		idx++;
	}
	return (dest);
}

void	swap_elem(t_elem *a, t_elem *b)
{
	t_elem	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	heap_new(int size)
{
	t_heap	*heap;

	heap = (t_heap *)malloc(sizeof(t_heap));
	heap->capacity = size;
	heap->size = 0;
	heap->arr = (t_elem *)malloc(sizeof(t_elem) * (size + 1));
	return (heap);
}

void	heap_expand(t_heap *heap)
{
	t_elem	*new_arr;

	heap->capacity *= 2;
	new_arr = (t_elem *)malloc(sizeof(t_elem) * (heap->capacity + 1));
	ft_memcpy(new_arr + 1, heap->arr + 1, heap->size);
	free(heap->arr);
	heap->arr = new_arr;
}

void	heap_update_to_root(t_heap *heap, int idx)
{
	int	left;
	int	right;

	if (idx == 0)
		return ;
	left = idx * 2;
	right = idx * 2 + 1;
	if (left <= heap->size && heap->arr[idx] > heap->arr[left])
		swap_elem(&heap->arr[left], &heap->arr[idx]);
	if (right <= heap->size && heap->arr[idx] > heap->arr[left])
		swap_elem(&heap->arr[right], &heap->arr[idx]);
	heap_update_to_root(heap, idx / 2);
}

void	heap_push(t_heap *heap, t_elem elem)
{
	if (heap->size == heap->capacity)
		heap_expand(heap);
	heap->size++;
	heap->arr[heap->size] = elem;
	heap_update_to_root(heap, heap->size);
}

t_elem	heap_pop(t_heap *heap)
{
	t_elem	ret;

	ret = heap->arr[1];
	
}


