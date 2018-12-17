#ifndef LINES_H
#define LINES_H

/*Type definition for the linked list node storing the text*/

struct line {
  char *str;  //string storing the content of the line
  struct line *next;
};

struct line* read_lines(struct line* text,int field);
void write_lines(struct line* text);
void delete_list(struct line* text);

#endif
