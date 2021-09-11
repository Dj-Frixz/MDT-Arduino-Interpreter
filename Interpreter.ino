#include <MDTape.h>

const int stpos = 1, inpos = 3, nxstpos = 5, outpos = 7, dirpos = 9;
//state, input, pointing (next), output and direction char position on the string (row)

const String MDT[] = {
  "(0,0,0,0,>)",
  "(0,1,0,1,>)",
  "(0,2,0,2,>)",
  "(0,3,0,3,>)",
  "(0,4,0,4,>)",
  "(0,5,0,5,>)",
  "(0,6,0,6,>)",
  "(0,7,0,7,>)",
  "(0,8,0,8,>)",
  "(0,9,0,9,>)",
  "(0,-,1,-,<)",
  "(0,=,0,=,>)",
  "(1,1,2,0,<)",
  "(1,2,2,1,<)",
  "(1,3,2,2,<)",
  "(1,4,2,3,<)",
  "(1,5,2,4,<)",
  "(1,6,2,5,<)",
  "(1,7,2,6,<)",
  "(1,8,2,7,<)",
  "(1,9,2,8,<)",
  "(1,0,1,9,<)",
  "(1,=,4,=,>)",
  "(1,-,6,=,<)",
  "(2,0,2,0,<)",
  "(2,1,2,1,<)",
  "(2,2,2,2,<)",
  "(2,3,2,3,<)",
  "(2,4,2,4,<)",
  "(2,5,2,5,<)",
  "(2,6,2,6,<)",
  "(2,7,2,7,<)",
  "(2,8,2,8,<)",
  "(2,9,2,9,<)",
  "(2,-,3,=,<)",
  "(2,=,3,=,<)",
  "(3,-,0,1,>)",
  "(3,0,0,1,>)",
  "(3,1,3,0,<)",
  "(4,9,4,9,>)",
  "(4,-,5,-,<)",
  "(5,9,5,-,<)",
  "(5,=,7,-,<)",
  "(6,-,6,0,>)",
  "(6,=,4,=,>)"
};
int MDTlength = sizeof(MDT);
int stbeg = 0;                        //state beginning
String input = "10";                  //input string
char cell = input.charAt(0);          //selected cell value
char state = MDT[0].charAt(stpos);    //actual state
MDTape tape(input, state);

void setup() {
}

String search_input(char x){
  int i = stbeg;
  while(MDT[i].charAt(stpos)==state && cell!=x){
    i++;
  }
  if (MDT[i].charAt(stpos)!=state){
    return "";
  }
  return MDT[i];
}

int search_state(char x){
  int i = 0;
  while(i<MDTlength && MDT[i].charAt(stpos)!=x){
    i++;
  }
  if (i==MDTlength){
    return 0;
  }
  stbeg = i;
  return 1;
}

void loop() {
  delay(100);
  String row = search_input(cell);
  if (row!=""){
    char output = row.charAt(outpos);
    if (output != cell){
      tape.chvalue(output);
    }
    switch(row.charAt(dirpos)){
      case '>': cell = tape.right(); break;
      case '<': cell = tape.left(); break;
      case '-': break;
      default: return;
    }
    char nextstate = row.charAt(nxstpos);
    if (row.charAt(stpos)!=nextstate){
      if (search_state(nextstate)==0){
        return;
      }else{
        tape.change_state(nextstate);
      }
    }
  }else{
    return;
  }
}
