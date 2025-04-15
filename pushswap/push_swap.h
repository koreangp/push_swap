/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pscala <pscala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:53:47 by pscala            #+#    #+#             */
/*   Updated: 2024/02/15 15:38:39 by pscala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				nbr;
	int				pos;
	int				target_n;
	int				price;
	int				target_pos;

	struct s_node	*next;
	struct s_node	*prev;

}					t_node;

int					main(int ac, char **av);
void				init_a(t_node **a, char **av, int s);
void				add_back(t_node **a, t_node *new_node);
t_node				*new_node_init(int num);
t_node				*get_last_node(t_node *a);
int					doublons(t_node *a, int num);
int					is_int_max(char *str);
int					is_num(char *str);
int					is_sorted(t_node *a);
void				rotate(t_node **stack);
void				rev_rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);
void				push(t_node **dest, t_node **src);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);
void				swap(t_node **a);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				add_front(t_node **stack, t_node *new_node);
void				stack_free(t_node **a);
void				sort(t_node **a, t_node **b);
void				error(t_node **a, char **str, int s);
void				sort3(t_node **a);
int					list_count(t_node *a);
void				algo(t_node **a, t_node **b);
void				good(void);
void				bad(void);
void				baddd(void);
int					get_pos(t_node **a, int num);
void				free_split(char **str, int s);
void				new_algo(t_node **a, t_node **b);
int					smallest(t_node *a);
int					biggest(t_node *a);
int					lower(int x, int y);
int					higher(int x, int y);
int					smallest_pos(t_node *a);
void				move_capital(t_node **a, t_node **b, t_node *current);
void				move_communist1(t_node **a, t_node **b, t_node *current);
void				move_communist2(t_node **a, t_node **b, t_node *current);
void				move_communist(t_node **a, t_node **b, t_node *current);
void				push_cheapest(t_node **a, t_node **b, int cheapest);
int					new_calc_price(t_node **a, t_node **b, t_node *current);
int					calc_cheapest(t_node **a, t_node **b);
int					capitalist(t_node **a, t_node **b, t_node *current);
int					communist(t_node **a, t_node **b, t_node *current);
void				ra_loop(t_node **a);
void				rra_loop(t_node **a);
int					calc_moyenne(t_node *a);
#endif
