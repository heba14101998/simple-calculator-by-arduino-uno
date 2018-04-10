 #define keynotsympole  !((key=='+')||(key=='-')||(key=='*')||(key=='/')||(key=='c')||(key=='='))
#include<LiquidCrystal.h>
LiquidCrystal Lcd1(8,9,10,11,12,13);
 short colums[4]={3,2,1,0};
short rows[4]={7,6,5,4};
char keypaturn[4][4]=
{{'1','2','3','+'}
,{'4','5','6','-'}
,{'7','8','9','*'}
,{'c','0','=','/'}};
void setup() {
  // put your setup code here, to run once:
for(int i=0;i<=3;i++){
  pinMode(colums[i],1);
   pinMode(rows[i],0);
   digitalWrite(rows[i],1);
    digitalWrite(colums[i],1);}
    Lcd1.begin(2,16);
    Lcd1.clear();
    
}
char scankpd(){
for(int j=0;j<=3;j++){
for(int c=0;c<=3;c++)
{digitalWrite(colums[c],1);}
digitalWrite(colums[j],0);
for(int i=0;i<=3;i++)
{if(!digitalRead(rows[i])){
  return keypaturn[i][j];
}}}
return 0;}
float op(char oper,float fnum,float snum){
  float result;
  switch(oper){
  case'+':
  result=fnum+snum;
  return result;
  break; 
  case'-':
  result=fnum-snum;
  return result; 
  break;
  case'*':
  result=fnum*snum;
  return result; 
  break;
    case'/':
    if(snum!=0)
  {result=fnum/snum;
  return result;}
  else
  {Lcd1.print("error");} 
  break;}}
void loop() {
  // put your main code here, to run repeatedly:
HOME1:
char key='\0';
 float fnum=0;
 float snum=0;
char oper='\0';
Lcd1.clear();
Lcd1.print("0");
HOME2:
 key=scankpd();
if(key){while(scankpd()){ }
 if( keynotsympole)
       {  fnum=fnum*10+int(key)-48;
       Lcd1.clear();
 Lcd1.print(fnum); goto HOME2;}
    
      else{
      switch(key){
        case 'c':goto HOME1; break;
         case '=': Lcd1.clear();Lcd1.print(fnum);
         goto HOME2;  break;
         default:oper =key; Lcd1.print(oper);
home3:
         key=scankpd();
    if(key){while(scankpd()){ }
 if( keynotsympole)     
{  snum=snum*10+int(key)-48;
      Lcd1.clear();
      Lcd1.print(snum);goto home3;}
      else{
         switch(key){
        case 'c':goto HOME1; break;
         case '=' :Lcd1.clear();fnum=op(oper,fnum,snum);  Lcd1.print(fnum);snum=0;goto HOME2; 
          break;
         
         default: Lcd1.clear();fnum=op(oper,fnum,snum);  Lcd1.print(fnum);snum=0;oper=key;goto home3; 
          break;}}}
          else {goto home3;}break;
         }}}
          else {goto HOME2;}}
    
