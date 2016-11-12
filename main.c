/*
** main.c for  in /home/laurent/piscine/my_FTL/liu_a
** 
** Made by LIU Laurent
** Login   <liu_a@etna-alternance.net>
** 
** Started on  Mon Nov  7 14:39:38 2016 LIU Laurent
** Last update Sat Nov 12 12:50:30 2016 LIU Laurent
*/

#include "ftl.h"

int		main()
{
  t_ship	*ship;

  srand(time(NULL));
  intro();
  ship = create_ship();
  add_weapon_to_ship(ship);
  add_ftl_drive_to_ship(ship);
  add_navigation_tools_to_ship(ship);
  add_container_to_ship(ship);
  boucle_jeu(ship);
  return (0);
}
