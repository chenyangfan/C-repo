/*Main function
 *Parameter: argc: number of argument
 *           argv: arguments that contain the number of fields to be skipped 
 *   when comapring lines  return value: 0
 */

int main(int argc,char* argv[]) {
  struct line* text=NULL;       //head of the list storing lines of text
  int field = 0;        // number of field to be skipped

  /* Check whether correct command-line arguments are supplied */
  if(argc > 2 )
    usage();

  if(argc >1 ){
    if(strlen(argv[1] ! =1)
       usage();
      

    if(strlen(argv[1]) != 1 || argv[1][0] < '0' || argv[1][0] > '9')
       usage();

       field=argv[1][0] - '0';
  }

    /* read and output lines */
    text = read_lines(text, field);

    write_lines(text);

    delete_list(text);

    return  0;
  }


  /*A helper function that prints the syntax of using this tool and exit
   *Parameter: none
   *Return value: none
   */

  void usage() {
    printf(" Usage: unique [field(1-9)] \n");
    exit(EXIT_FAILURE);
  }
