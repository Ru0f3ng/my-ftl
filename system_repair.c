/*
** system_repair.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 13:42:21 2016 LIU Laurent
** Last update Sat Nov 12 12:52:42 2016 LIU Laurent
*/

#include "ftl.h"

static const t_repair_command	tab[] =
  {
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {NULL, NULL}
  };

int	ftl_drive_system_repair(t_ship *ship)
{
  free(ship->ftl_drive->system_state);
  ship->ftl_drive->system_state = NULL;
  my_putstr_color("yellow", "reparation du reacteur en cours...\n");
  if (ship->ftl_drive->system_state == NULL)
    {
      ship->ftl_drive->system_state = my_strdup("online");
      my_putstr_color("green", "reparation termine! systeme reacteur OK!\n");
      return (1);
    }
  else
    my_putstr_color("red", "les reparations du reacteur ont echoue...NOOB!\n");
  return (0);
}

int	navigation_tools_system_repair(t_ship *ship)
{
  free(ship->navigation_tools->system_state);
  ship->navigation_tools->system_state = NULL;
  my_putstr_color("yellow", "reparation du systeme de ");
  my_putstr_color("yellow", "navigation en cours...\n");
  if (ship->navigation_tools->system_state == NULL)
    {
      ship->navigation_tools->system_state = my_strdup("online");
      my_putstr_color("green", "reparation termine! ");
      my_putstr_color("green", "systeme de navigation OK!\n");
      return (1);
    }
  else
    {
      my_putstr_color("red", "les reparations des outils ");
      my_putstr_color("red", "de navigations ont echoue...NOOB!");
    }
  return (0);
}

int	weapon_system_repair(t_ship *ship)
{
  free(ship->weapon->system_state);
  ship->weapon->system_state = NULL;
  my_putstr_color("yellow", "reparation du systeme d'armement en cours...\n");
  if (ship->weapon->system_state == NULL)
    {
      ship->weapon->system_state = my_strdup("online");
      my_putstr_color("green", "reparation termine! systeme d'armement OK!\n");
      return (1);
    }
  else
    {
      my_putstr_color("red", "les reparations du systeme ");
      my_putstr_color("red", "d'armement ont echoue\n...NOOB!");
    }
  return (0);
}
    
int	system_repair(t_ship *ship)
{
  char	*entry;
  int	i;

  my_putstr_color("magenta", "repair_system~>");
  entry = readline();
  i = 0;
  while (i < 4)
    {
      if (my_strcmp(entry, tab[i].string) == 0)
	{
	  if (tab[i].ptr(ship) == 1)
	    return (1);
	  else
	    {
	      my_putstr_color("red", "[SYSTEM FAILURE] : ");
	      my_putstr_color("red", "le lecteur de commande ");
	      my_putstr_color("red", "est bloque...NOOB!\n");
	      return (0);
	    }
	}
      i++;
    }
  my_putstr_color("red", "[SYSTEM FAILURE] : commande inconnue...NOOB!\n");
  return (0);
}
