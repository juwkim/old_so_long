/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwkim <juwkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:34:40 by juwkim            #+#    #+#             */
/*   Updated: 2022/12/28 13:40:46 by juwkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void	*mlx_init(void);
/*
**  needed before everything else.
**  return (void *)0 if failed
*/

/*
** Basic actions
*/

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

/*
** Image stuff
*/

void	*mlx_new_image(void *mlx_ptr, int width, int height);
/*
**  return void *0 if failed
*/

int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
			int x, int y);

/*
** dealing with Events
*/

int		mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop(void *mlx_ptr);

/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/

int		mlx_string_put(void *mlx_ptr, void *win_ptr, \
	int x, int y, int color, char *string);
void	*mlx_png_file_to_image(void *mlx_ptr, char *file, \
						int *width, int *height);

int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int		mlx_hook(void *win_ptr, int x_event, int x_mask, \
	int (*funct)(), void *param);

int		mlx_mouse_hide(void);
int		mlx_mouse_show(void);
int		mlx_mouse_move(void *win_ptr, int x, int y);
int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

int		mlx_do_key_autorepeatoff(void *mlx_ptr);
int		mlx_do_key_autorepeaton(void *mlx_ptr);
int		mlx_do_sync(void *mlx_ptr);

# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD		2
# define MLX_SYNC_WIN_CMD_COMPLETED	3

int		mlx_sync(int cmd, void *param);

int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif /* MLX_H */
