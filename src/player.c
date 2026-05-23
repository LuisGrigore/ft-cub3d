#include "../include/config.h"
#include "../include/game.h"
#include <math.h>

void	init_player(t_player *player, t_player_config config)
{
	player->x = config.starting_x;
	player->y = config.starting_y;
	player->angle = config.starting_angle;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	player_key_press(int keycode, void *player_ptr)
{
	t_player	*player;

	player = (t_player *)player_ptr;
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_left = true;
	if (keycode == D)
		player->key_right = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	player_key_release(int keycode, void *player_ptr)
{
	t_player	*player;

	player = (t_player *)player_ptr;
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_left = false;
	if (keycode == D)
		player->key_right = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	move_player(t_player *player)
{
	const int	speed = 3;
	const float	angle_speed = 0.03f;
	const float	collision_distance = 20.0f;
	float		cos_angle;
	float		sin_angle;
	float		new_x;
	float		new_y;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	if (player->key_up)
	{
		new_x = player->x + cos_angle * speed;
		new_y = player->y + sin_angle * speed;
		if (new_x > collision_distance && new_x < (15 * 64 - collision_distance)
			&& new_y > collision_distance && new_y < (10 * 64
				- collision_distance))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (player->key_down)
	{
		new_x = player->x - cos_angle * speed;
		new_y = player->y - sin_angle * speed;
		if (new_x > collision_distance && new_x < (15 * 64 - collision_distance)
			&& new_y > collision_distance && new_y < (10 * 64
				- collision_distance))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (player->key_left)
	{
		new_x = player->x + sin_angle * speed;
		new_y = player->y - cos_angle * speed;
		if (new_x > collision_distance && new_x < (15 * 64 - collision_distance)
			&& new_y > collision_distance && new_y < (10 * 64
				- collision_distance))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
	if (player->key_right)
	{
		new_x = player->x - sin_angle * speed;
		new_y = player->y + cos_angle * speed;
		if (new_x > collision_distance && new_x < (15 * 64 - collision_distance)
			&& new_y > collision_distance && new_y < (10 * 64
				- collision_distance))
		{
			player->x = new_x;
			player->y = new_y;
		}
	}
}
