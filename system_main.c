/*
** main_system.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 22:08:44 2016 LIU Laurent
** Last update Sat Nov 12 12:53:03 2016 LIU Laurent
*/

#include "ftl.h"

static const t_actions	menu[] =
  {
    {"attack", attack_enemy},
    {"detect", detect},
    {"getbonus", get_bonus},
    {"controlsystem", system_control},
    {"stats", aff_stats}, 
    {"help", aff_help},
    {NULL, NULL}
  };

int	test_entry(char *entry, t_ship *ship)
{
  int	i;
  int	j;
  int	test;

  i = 0;
  j = 0;
  test = 1;
  while ((menu[i].nom_action != NULL) && (j == 0))
    {
      if (my_strcmp(entry, "repairsystem") == 0)
	{
	  test = system_repair(ship);
	  j = 1;
	}
      else if (my_strcmp(entry, "jump") == 0)
	{
	  test = jump(ship);
	  j = 1;
 	}
      else if (my_strcmp(entry, menu[i].nom_action) == 0)
	{
	  menu[i].ptr(ship);
	  j = 1;
	}
      i++;
      if (test == 0)
	return (0);       
    }
  if (j == 0)
    my_putstr_color("red", "commande inconnue!...NOOB!\n");
  return (0);
}

int		boucle_jeu(t_ship *ship)
{
  char		*entry;

  while ((ship->hull > 0) &&
	 (ship->navigation_tools->sector < 10) &&
	 (ship->ftl_drive->energy > 0))
    {
      my_putstr_color("blue", "oui, sensei~>");
      entry = readline();
      test_entry(entry, ship);
      if (ship->enemy != NULL)
	{
	  enemy_attack(ship);
	}
    }
  if (ship->hull == 0 || ship->ftl_drive->energy == 0)
    my_putstr_color("yellow", "sorry you have lost...LOSER\n");
  else if (ship->navigation_tools->sector == 10)
    my_putstr_color("yellow", "You are the king of the galaxy!*clap* *clap*\n");
  return (0);
}
