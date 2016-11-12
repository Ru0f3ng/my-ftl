/*
** ennemy.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Thu Nov 10 15:13:01 2016 LIU Laurent
** Last update Sat Nov 12 12:49:49 2016 LIU Laurent
*/

#include "ftl.h"

int	jump(t_ship *ship)
{
  int	rand;
  int	test;

  if (ship->enemy != NULL)
    my_putstr_color("red", "n'essaye pas de fuir petit misérable~\n");
  else
    {
      ship->ftl_drive->energy--;
      ship->navigation_tools->sector++;
      my_putstr_color("green", "Vous êtes arrivés au secteur ");
      my_put_nbr(ship->navigation_tools->sector);
      my_putstr("\n");
      rand = my_rand(10);
      if (rand == 1 || rand == 2 || rand == 3)
	{
	  test = create_enemy(ship);
	  if (test == 0)
	    return (0);
	}
    }
  return (1);
}

int		create_enemy(t_ship *ship)
{
  t_enemy	*enemy;
  static int	stored_life = 20;
  static int	stored_damage = 10;

  enemy = malloc(sizeof(*ship));
  if (ship == NULL)
    return (0);
  my_putstr_color("red", "[SYSTEM DETECT] : nouvel ennemi détecté, ");
  my_putstr_color("red", "il nous attaque!\n"); 
  enemy->life = stored_life;
  enemy->damage = stored_damage;
  ship->enemy = enemy;
  stored_life = stored_life * 1.5;
  stored_damage = stored_damage * 1.5;
  return (1);
}

void		enemy_attack(t_ship *ship)
{
  int		rand;

  my_putstr_color("magenta", "L'ennemi essaye de vous attaquer!\n");
  my_putstr("\n");
  my_putstr_color("magenta", "L'ennemi essaye de vous attaquer!\n");
  my_putstr_color("cyan", "[ENNEMI SUPERMÉCHANT] :\n");
  my_putstr_color("magenta", " | life :");
  my_put_nbr(ship->enemy->life);
  my_putstr_color("magenta", "\n | damage :");
  my_put_nbr(ship->enemy->damage);
  my_putstr("\n");
  rand = my_rand(100);
  if (ship->navigation_tools->evade < rand)
    {
      ship->hull -= ship->enemy->damage;
      my_putstr_color("red", "vous avez été touché!! ouch!!! vous avez mal!\n");
      enemy_break_system(ship);
    }
  else
    my_putstr_color("green", "vous avez esquivé! GG PRO!\n");
}

void	enemy_break_system(t_ship *ship)
{
  int	rand;

  rand = my_rand(5);
  if (rand == 1)
    {
      rand = my_rand(3);
      if (rand == 1)
	{
	  free(ship->ftl_drive->system_state);
	  ship->ftl_drive->system_state = my_strdup("offline");
	  my_putstr_color("red", "[CRITICAL HIT] : ftl_drive is broken!\n");
	}
      else if (rand == 2)
	{
	  free(ship->weapon->system_state);
	  ship->weapon->system_state = my_strdup("offline");
	  my_putstr_color("red", "[CRITICAL HIT] : our weapon is broken!\n");
	}
      else
	{
	  free(ship->navigation_tools->system_state);
	  ship->navigation_tools->system_state = my_strdup("offline");
	  my_putstr_color("red", "[CRITICAL HIT] : navigation_tools are ");
	  my_putstr_color("red", "broken!\n");
	}
    }
}
