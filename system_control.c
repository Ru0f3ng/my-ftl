/*
** system_control.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Wed Nov  9 11:42:08 2016 LIU Laurent
** Last update Sat Nov 12 12:52:20 2016 LIU Laurent
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du reacteur en cours...\n");
  if (my_strcmp(ship->ftl_drive->system_state, "online") == 0)
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "reacteur hors service!...NOOB!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme de navigation");
  my_putstr_color("yellow", "en cours...\n");
  if (my_strcmp(ship->navigation_tools->system_state, "online") == 0)
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    my_putstr_color("red", "systeme de navigation hors service!...NOOB!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr_color("yellow", "verification du systeme d'armement en cours...\n");
  if (my_strcmp(ship->weapon->system_state, "online") == 0)
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    my_putstr_color("red", "systeme d'armement hors service!...NOOB!\n");
}

void	system_control(t_ship *ship)
{ 
  ftl_drive_system_check(ship);
  weapon_system_check(ship);
  navigation_tools_system_check(ship);
}
