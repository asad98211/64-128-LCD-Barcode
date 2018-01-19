#include <U8glib.h>  
U8GLIB_ST7920_128X64_1X u8g(6, 5, 4 ,7); //Enable, RW, RS, RESET  
char num_bits [20][8]={"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011","1110010","1100110","1101100","1000010","1011100","1001110","1010000","1000100","1001000","1110100"};

void drawBarCode(char *number){
  int i,j,k;
  for(i=0;i<17;i++){
    u8g.drawLine(i, 0, i, 60);
  }
  for(i=0,j=0;i<95;i++){
//    printf("%d",i);
    if(i<3){
       if(i%2==1){
//         printf("a");
         u8g.drawLine(i+17, 0, i+17, 60);
       }
    }
    else if(i>43&&i<50){
      if(i%2==1){
//         printf("c");
        u8g.drawLine(i+17, 0, i+17, 60);
      }
    }
    else if(i>91){
      if(i%2==1){
//         printf("e");
        u8g.drawLine(i+17, 0, i+17, 60);
      }
    }
    else{
      if(i<=43){
        for(k=0;k<7;k++,i++){
          if(num_bits[number[j]-'0'][k]=='0'){
//            printf("b");
              u8g.drawLine(i+17, 0, i+17, 60);
          }
//          else{
//            printf("0");
//          }
        }
        j++;
        i=2+j*7;
      }
      else{
        for(k=0;k<7;k++,i++){
          if(num_bits[number[j]-'0'+10][k]=='0'){
//
//            printf("d");
              u8g.drawLine(i+17, 0, i+17, 60);
          }
//          else{
//            printf("0");
//          }
        }
        j++;
        i=7+j*7;
      }
//      printf("\n");
    }
//    newLine(i);
  }
  for(i=112;i<129;i++){
    u8g.drawLine(i, 0, i, 60);
  }
}
void draw(){
  drawBarCode("000022089012");
}

void setup() {
//  Serial.begin(9600);
}

void loop() {
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  delay(1000);
}
