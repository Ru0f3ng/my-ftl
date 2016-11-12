/*
** ftl.h for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 10:07:48 2016 LIU Laurent
** Last update Sat Nov 12 12:50:59 2016 LIU Laurent
*/

# ifndef __FTL_H__
# define __FTL_H__
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct		s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}			t_freight;

typedef struct	s_container
{
  int		nb_elem;
  t_freight	*first;
  t_freight	*last;
}		t_container;

typedef struct	s_navigation_tools
{
  char		*system_state;
  int		sector;
  int		evade;
}		t_navigation_tools;

typedef struct	s_ftl_drive
{
  char		*system_state;
  int		energy;
}		t_ftl_drive;

typedef struct	s_weapon
{
  char		*system_state;
  int		damage;
}		t_weapon;

typedef struct	s_enemy
{
  int		life;
  int		damage;
}		t_enemy;

typedef	struct		s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
  t_enemy		*enemy;
}			t_ship;

typedef struct	s_repair_command
{
  char		*string;
  int		(*ptr)(t_ship *ship);
}		t_repair_command;

typedef struct	s_actions
{
  char		*nom_action;
  void		(*ptr)(t_ship *ship);
}		t_actions;

void		intro();
void		my_putchar(char c);
int		powmax(int n);
void		my_put_nbr(int n);
int		my_rand(int n);
int		my_strlen(const char *str);
void		my_putstr(const char *str);
void		my_putstr_color(const char *color, const char *str);
int		my_strcmp(const char *s1, const char *s2);
char		*my_strdup(const char *str);
char		*readline(void);
t_ship		*create_ship();
t_freight	*create_freight();
int		create_enemy(t_ship *ship);
int		add_weapon_to_ship(t_ship *ship);
int		add_ftl_drive_to_ship(t_ship *ship);
int		add_navigation_tools_to_ship(t_ship *ship);
int		add_container_to_ship(t_ship *ship);
void		add_freight_to_container(t_ship *ship, t_freight *freight);
void		del_freight_from_container(t_ship *ship, t_freight *freight);
void		get_bonus(t_ship *ship);
void		ftl_drive_system_check(t_ship *ship);
void		navigation_tools_system_check(t_ship *ship);
void		weapon_system_check(t_ship *ship);
void		system_control(t_ship *ship);
int		ftl_drive_system_repair(t_ship *ship);
int		navigation_tools_system_repair(t_ship *ship);
int		weapon_system_repair(t_ship *ship);
int		system_repair(t_ship *ship);
int		boucle_jeu(t_ship *ship);
int		jump(t_ship *ship);
int		test_entry(char *entry, t_ship *ship);
void		aff_stats(t_ship *ship);
void		aff_help();
void		attack_enemy(t_ship *ship);
void		enemy_attack(t_ship *ship);
void		detect(t_ship *ship);
void		enemy_break_system(t_ship *ship);
# endif
