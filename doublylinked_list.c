#include <stdio.h>
#include <stdlib.h>
#include "doublylinked_list.h"
Cell *CreateCell(int d, bool is_head){
    Cell *new_cell = (Cell*)malloc(sizeof(Cell));
    new_cell -> prev = new_cell;
    new_cell -> next = new_cell;
    new_cell -> data = d;
    new_cell -> is_head = is_head;
    printf("new_cell created! but new_cell is still unconnected.\n");
    return new_cell;
}

void InsertNext(Cell *this_cell, Cell *p){
    Cell *next_cell;
    next_cell = this_cell -> next;
    p -> next = next_cell;
    p -> prev = this_cell;
    this_cell -> next = p;
    next_cell -> prev = p;
    printf("Cell connect after this_cell\n ");
}

void InsertPrev(Cell *this_cell, Cell *p){
    Cell *prev_cell;
    prev_cell = this_cell -> prev;
    p -> prev = prev_cell;
    p -> next = this_cell;
    this_cell -> prev = p;
    prev_cell -> next = p;
    printf("Cell connect before this_cell\n ");
}

void DeleteCell(Cell *this_cell){
    Cell *next_cell = this_cell -> next;
    Cell *prev_cell = this_cell -> prev;
    if (this_cell -> is_head == true){
        printf("this_cell is dummy_cell\n");
        exit(EXIT_FAILURE);
    }
    next_cell -> prev = prev_cell;
    prev_cell -> next = next_cell;
    free(this_cell);
}

Cell *SearchCell(Cell *this_cell, int d){
    Cell *search_cell = this_cell -> next;
    if (this_cell -> is_head == false){
        if (this_cell -> data == d){
        return this_cell;
        }
    }
    while (search_cell != this_cell){
        if (search_cell -> is_head == false){
            if (search_cell -> data == d){
                return search_cell;
            }
        }
        search_cell = search_cell -> next;
    }
    return NULL;
}

void Display(Cell *this_cell){
    Cell *move_cell;
    move_cell = this_cell -> next;
    if (this_cell -> is_head == false){
        printf("%d ",this_cell -> data);
    }
    while (move_cell != this_cell){
        if (move_cell -> is_head == false){
            printf("%d ",move_cell -> data);
        }
        move_cell = move_cell -> next;
    }
    printf("\n");
}

void WriteToFile(Cell *this_cell) {
  FILE *outputfile;
  outputfile = fopen("d.txt", "w");
  if (outputfile == NULL){
      printf("cannot open\n");
      exit(1);
  }
  Cell *move_cell;
    move_cell = this_cell -> next;
    if (this_cell -> is_head == false){
        fprintf(outputfile,"%d ",this_cell -> data);
    }
    while (move_cell != this_cell){
        if (move_cell -> is_head == false){
            fprintf(outputfile,"%d ",move_cell -> data);
        }
        move_cell = move_cell -> next;
    }
    printf("\n");
  fclose(outputfile);
}

void WriteToArray(Cell *this_cell, int array[], int size){
    Cell *move_cell;
    move_cell = this_cell -> next;
    if (this_cell -> is_head == false){
        array[0] = this_cell -> data;
    }
    int count = 0;
    while (move_cell != this_cell){
        if (move_cell -> is_head == false){
           array[count] = move_cell -> data;
           count++;
        }
        move_cell = move_cell -> next;
    } 
    int i;
    for ( i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void ReadFromArray(Cell *this_cell, int array[], int size){
    int i;
    for ( i = 0; i < size; i++)
    {
        Cell *new_cell;
        new_cell = CreateCell(array[i], false);
        InsertNext(this_cell, new_cell);
    }
}

void ReadFromFile(Cell *this_cell){
    FILE *inputfile;
    inputfile = fopen("d.txt", "r");
    if (inputfile == NULL){
      printf("cannot open\n");
      exit(1);
  }
  int num;
  while (fscanf(inputfile, "%d", &num)  != EOF)
  {
    Cell *new = CreateCell(num, false);
    InsertNext(this_cell, new);
  }
  fclose(inputfile);
}