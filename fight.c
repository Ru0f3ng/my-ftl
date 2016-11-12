/*
** fight.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Fri Nov 11 15:32:49 2016 LIU Laurent
** Last update Sat Nov 12 12:48:28 2016 LIU Laurent
*/

#include "ftl.h"

void	attack_enemy(t_ship *ship)
{
  if (ship->enemy != NULL)
    {
      if (my_strcmp(ship->weapon->system_state, "online") == 0)
	{
	  ship->enemy->life -= ship->weapon->damage;
	  if (ship->enemy->life <= 0)
	    {
	      free(ship->enemy);
	      ship->enemy = NULL;
	      my_putstr_color("green", "enemy is dead! Yeeeeeeesss!!\n");
	    }
	}
      else
	my_putstr_color("red", "weapon is broken! ... weakling\n");
    }
  else
    my_putstr_color("red", "ya personne... ça va tu t'amuses?\n");
}
