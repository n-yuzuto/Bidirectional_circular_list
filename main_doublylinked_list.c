#include <stdio.h>
#include <stdlib.h>
#include "doublylinked_list.h"
int main(void) {
  Cell *head = CreateCell(0, true);
  Cell *elem;
  Cell *new_cell1, *new_cell2, *new_cell3, *new_cell4; 
  new_cell1 = CreateCell(2, false);
  new_cell2 = CreateCell(1, false);
  new_cell3 = CreateCell(5, false);
  InsertNext(head, new_cell1);
  InsertNext(head, new_cell2);
  InsertPrev(head, new_cell3);
  WriteToFile(head);
  int array[3];
  WriteToArray(head, array, 3);
  Display(head);
  elem = SearchCell(head, 2);
  new_cell4 = CreateCell(3, false);
  InsertNext(elem, new_cell4);
  Display(head);
  elem = SearchCell(head, 5);
  DeleteCell(elem);
  Display(head);
  elem = SearchCell(head, 2);
  DeleteCell(elem);
  Display(head);
  elem = SearchCell(head, 1);
  DeleteCell(elem);
  Display(head);
  ReadFromArray(head, array, 3);
  Display(head);
  ReadFromFile(head);
  Display(head);
  return EXIT_SUCCESS;
}
