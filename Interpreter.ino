#include <MDTape.h>

const int stpos = 1, inpos = 3, nxstpos = 5, outpos = 7, dirpos = 9;
//state, input, pointing (next), output and direction char position on the string (row)

const String MDT[] = {
  "(0,0,0,0,>)", //0
  "(0,1,0,1,>)", //1
  "(0,2,0,2,>)", //2
  "(0,3,0,3,>)", //3
  "(0,4,0,4,>)", //4
  "(0,5,0,5,>)", //5
  "(0,6,0,6,>)", //6
  "(0,7,0,7,>)", //7
  "(0,8,0,8,>)", //8
  "(0,9,0,9,>)", //9
  "(0,-,1,-,<)", //10
  "(0,=,0,=,>)", //11
  "(1,1,2,0,<)", //12
  "(1,2,2,1,<)", //13
  "(1,3,2,2,<)", //14
  "(1,4,2,3,<)", //15
  "(1,5,2,4,<)", //16
  "(1,6,2,5,<)", //17
  "(1,7,2,6,<)", //18
  "(1,8,2,7,<)", //19
  "(1,9,2,8,<)", //20
  "(1,0,1,9,<)", //21
  "(1,=,4,=,>)", //22
  "(1,-,6,=,<)", //23
  "(2,0,2,0,<)", //24
  "(2,1,2,1,<)", //25
  "(2,2,2,2,<)", //26
  "(2,3,2,3,<)", //27
  "(2,4,2,4,<)", //28
  "(2,5,2,5,<)", //29
  "(2,6,2,6,<)", //30
  "(2,7,2,7,<)", //31
  "(2,8,2,8,<)", //32
  "(2,9,2,9,<)", //33
  "(2,-,3,=,<)", //34
  "(2,=,3,=,<)", //35
  "(3,-,0,1,>)", //36
  "(3,0,0,1,>)", //37
  "(3,1,3,0,<)", //38
  "(4,9,4,9,>)", //39
  "(4,-,5,-,<)", //40
  "(5,9,5,-,<)", //41
  "(5,=,7,-,<)", //42
  "(6,-,6,0,>)", //43
  "(6,=,4,=,>)"  //44
};
int MDTlength = 45;
int stbeg = 0;                        //state beginning
char input[] = "10";                  //input string
char cell = input[0];          //selected cell value
char first_state = MDT[0].charAt(stpos);    //actual state
MDTape tape;                          // 

void setup() {
  Serial.begin(9600);
  tape.begin(input, first_state);                       //initialize LiquidCrystal library
  Serial.println("Started Screen");
  Serial.println("tape:");
  Serial.println(tape.tape);            //print out tape
  Serial.print("state:");
  Serial.print(tape.state);
  Serial.print("  cursor:");
  Serial.println(tape.curs);
  Serial.println("/////////////////////");
}

String search_input(){
  int i = stbeg;
  while(MDT[i].charAt(stpos)==tape.state && cell!=MDT[i].charAt(inpos)){ //while state=current state and cell=tuple input
    i++;
  }
  Serial.print("new tuple position: ");
  Serial.println(i);
  if (MDT[i].charAt(stpos)!=tape.state){
    return "";
  }
  return MDT[i];
}

int search_state(char nextstate){
  int i = 0;
  while(i<MDTlength && MDT[i].charAt(stpos)!=nextstate){ //*******
    i++;
  }
  Serial.print("nextstate position: ");
  Serial.println(i);
  if (i==MDTlength){
    return 0;         //means nextstate is the final state
  }
  stbeg = i;          //sets position for next state search
  return 1;
}

void loop() {
  delay(500);
  Serial.println("tape:");
  Serial.println(tape.tape);            //print out tape
  Serial.print("state:");
  Serial.print(tape.state);
  Serial.print("  cursor:");
  Serial.println(tape.curs);
  String row = search_input();      //returns next tuple based on input (cell) and current state
  Serial.print("tuple:");
  Serial.println(row);
  if (row!=""){
    char output = row.charAt(outpos);
    if (output != cell){
      tape.chvalue(output);
    }
    char dir = row.charAt(dirpos);
    switch(dir){
      case '>': 
        cell = tape.right(); 
        break;
      case '<': 
        cell = tape.left(); 
        break;
      case '-': 
        break;
      default: 
        return;
    }
    char nextstate = row.charAt(nxstpos);
    if (row.charAt(stpos)!=nextstate){    //********
      if (search_state(nextstate)==0){    //changes 'stbeg' with the first occurance of the 'nextstate'
        return;
      }else{
        tape.change_state(nextstate);     //updates tape.state and prints the new state on screen
      }
    }
    Serial.print("output:");
    Serial.print(output);
    Serial.print("  nextstate:");
    Serial.print(nextstate);
    Serial.print("  cell:");
    Serial.print(cell);
    Serial.print("  direction:");
    Serial.println(dir);
  }else{
    Serial.println("error: missing row :[");
    return;
  }
}
