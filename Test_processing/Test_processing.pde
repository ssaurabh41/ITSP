PFont f;
PImage img;
int wid=60,hei=50;
boolean Wover=false,Aover=false,Sover=false,Dover=false,Eover=false,Qover=false,Zover=false,Cover=false,Xover=false,manover=false,autover=false;
boolean wpressed=false,apressed=false,spressed=false,dpressed=false,qpressed=false,epressed=false,zpressed=false,cpressed=false,xpressed=false,manpressed=false,autpressed=false;
boolean aut=false;
color c1=255;
int i=0;
char written='x';

import processing.serial.*;
Serial myPort; 

int previnByte=0,newinByte=0;        // Data received from the serial port

void setup()
{
  String portName = Serial.list()[0];
  print(Serial.list());
   myPort = new Serial(this, portName, 9600);// Create object from Serial class
  
  size(800,602);
//printArray(PFont.list());
  f = createFont("batman.ttf",45,true);
  textFont(f);
  
  textAlign(CENTER, CENTER);  
  img=loadImage("phoenix.jpg");
  

}
void draw()
{
  
update(mouseX, mouseY);

//------------------------------------------------------- 
background(img);
//---------------/-FOR W----/-----------/--------

if(Wover || wpressed){
fill(0,0,0,0);
stroke(0);
}
else{
fill(0);
stroke(244,235,210);
}
rect(390-10,450+5,wid,wid-5);  
//----------/-------FOR S--/----------------------/------  

if(Sover || spressed){
fill(0,0,0,0);
stroke(0);
}
else
{
fill(0);
stroke(244,235,210);
}
rect(390-10,520+5,wid,wid-5);  
//----------/-----FOR A--/----------------------/------

if(Aover || apressed){
fill(0,0,0,0);
stroke(0);
}
else
{
stroke(76,216,214);  
fill(0);
}
rect(320-10,520+5,wid,wid-5);   
//----------/------FOR D---/----------------------/------

if(Dover || dpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
fill(0);
stroke(230,161,5);
}
rect(460-10,520+5,wid,wid-5);  

//----------/-----FOR X--/----------------------/------

if(Xover || xpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
stroke(76,216,214);  
fill(0);
}
rect(141,520+5,wid,wid-5);  
//-----------------------------------------------LEFT HANDS------------------------------------------------------------
if(Qover || qpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
fill(0);
stroke(76,216,214);
}
rect(100+60,182+70,wid,wid);

if(Zover || zpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
fill(0);
stroke(76,216,214);
}
rect(100+60,288+40,wid,wid);
//-----------------------------------------------RIGHT HANDS------------------------------------------------------------
if(Eover || epressed){
fill(0,0,0,0);
stroke(0);
}
else
{
fill(0);
stroke(230,161,5);
}
rect(640-60,182+70,wid,wid); 

if(Cover || cpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
fill(0);
stroke(230,161,5);
}
rect(640-60,288+40,wid,wid); 
//----------/--------------/----------------------/------
//----------/-----FOR mode 1-MANUAL mode-/----------------------/------

if(manover || manpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
stroke(76,216,214);  
fill(0);
}
rect(351-50,128,wid+30,wid-5); 
//----------/-----FOR mode 2--AUTOMATED mode/----------------------/------

if(autover || autpressed){
fill(0,0,0,0);
stroke(0);
}
else
{
stroke(230,161,5);  
fill(0);
}
rect(448-35,128,wid+30,wid-5); 
//---------------------------------+++++++++++++--------
textSize(60);
fill(255);
text("BIPED INTERFACE",400,50);
//------------------TEXT---------------------------//
textSize(25);
fill(0);
 text("Forward",413,445);

textSize(45);
if((mousePressed==false && Wover==false)||(mousePressed==true && Wover==false)||(mousePressed==true && Wover==true)||(wpressed==true))
fill(255);
else if(mousePressed==false && Wover==true)
fill(0);
text('W',390-10+2+wid/2,450+wid/2);
 //---------------------------------------------
textSize(25);
fill(0);
 text("Turn\nLeft",267,552);
textSize(45);

if((mousePressed==false && Sover==false)||(mousePressed==true && Sover==false)||(mousePressed==true && Sover==true)||(spressed==true))
fill(255);
else if(mousePressed==false && Sover==true)
fill(0);
 text('S',390+3-10+wid/2,520+wid/2);
 //-----------------------------------------------
 textSize(25);
 fill(0);
 text("Backward",413,588);
 textSize(45);
 if((mousePressed==false && Aover==false)||(mousePressed==true && Aover==false)||(mousePressed==true && Aover==true)||(apressed==true))
fill(255);
else if(mousePressed==false && Aover==true)
fill(0);
 text('A',320+3-10+wid/2,520+wid/2);
  //-----------------------------------------------
 textSize(25);
 fill(0);
 text("Turn\nRight",556,547);
 textSize(45);
 if((mousePressed==false && Dover==false)||(mousePressed==true && Dover==false)||(mousePressed==true && Dover==true)||(dpressed==true))
fill(255);
else if(mousePressed==false && Dover==true)
fill(0);
 text('D',460+4-10+wid/2,520+wid/2);
 //-----------------------------------------------
 textSize(25);
 fill(0);
 text("Stop",141+30,525+64);
 textSize(45);
 if((mousePressed==false && Xover==false)||(mousePressed==true && Xover==false)||(mousePressed==true && Xover==true)||(xpressed==true))
fill(255);
else if(mousePressed==false && Xover==true)
fill(0);
 text('X',141+wid/2+1,520+5+wid/2-5);
 //----------------------Left hand-------------------------
 textSize(25);
 fill(255);
 text("Left\nhand",86,308);
 
 if((mousePressed==false && Qover==false)||(mousePressed==true &&Qover==false)||(mousePressed==true &&Qover==true)||(qpressed==true))
fill(255);
else if(mousePressed==false &&Qover==true)
fill(0);
textSize(55);
 text('Q',100+60+wid/2+3,182+70-5+wid/2);
 
if((mousePressed==false && Zover==false)||(mousePressed==true &&Zover==false)||(mousePressed==true && Zover==true)||(zpressed==true))
fill(255);
else if(mousePressed==false && Zover==true)
fill(0);
textSize(55);
 text('Z',100+60+wid/2+3,288+40-5+wid/2);
 //---------------------Right hand--------------------------
textSize(25);
fill(255);
 text("Right\nhand",727,308); 
 
if((mousePressed==false && Eover==false)||(mousePressed==true && Eover==false)||(mousePressed==true && Eover==true)||(epressed==true))
fill(255);
else if(mousePressed==false && Eover==true)
fill(0);
textSize(55);
text('E',640-60+wid/2+3,182-5+70+wid/2);
 
if((mousePressed==false && Cover==false)||(mousePressed==true && Cover==false)||(mousePressed==true && Cover==true)||(cpressed==true))
fill(255);
else if(mousePressed==false && Cover==true)
fill(0);
textSize(55);
text('C',640-60+wid/2+3,288-5+40+wid/2);
   //--------------------Modes text---------------------------
 textSize(25);
 fill(255);
 
 text("Robot mode:",300,112);
 text(((aut)?"Auto":"Manual"),490,112);
 textSize(20);
fill(255);

 text("1\nAuto",351-30+wid/2,128-5+wid/2);
 
 textSize(20);
fill(255);

 text("2\nManual",448-15+wid/2,128-5+wid/2);
 //--------------------------------------------------
 textSize(25);
 /*
 if(previnByte!=newinByte)
 {
 
 print(newinByte);
newinByte=previnByte;
}

*/

if(written=='1' || written=='2')
{
  fill(255);
  textSize(25);
 text("Press X",700,585); 
}

if((mousePressed==true && Wover==true)||wpressed==true)
{
  
  if(written!='w' && written=='x')
  {
 written='w';
 myPort.write(written);
  }
}else
if((mousePressed==true && Sover==true)||spressed==true)
{
 if(written!='s' && written=='x')
  {
 written='s';
 myPort.write(written);
  }
}else
if((mousePressed==true && Aover==true)||apressed==true)
{
  if(written!='a' && written=='x')
  {
 written='a';
 myPort.write(written);
  }
}else
if((mousePressed==true && Dover==true)||dpressed==true)
{
 if(written!='d' && written=='x')
  {
 written='d';
 myPort.write(written);
  }
}else
if((mousePressed==true && Qover==true)||qpressed==true)
{
  if(written!='q' && written=='x')
  {
 written='q';
 myPort.write(written);
  }
}else
if((mousePressed==true && Eover==true)||epressed==true)
{
  if(written!='e' && written=='x')
  {
 written='e';
 myPort.write(written);
  }
}else
if((mousePressed==true && Zover==true)||zpressed==true)
{
 if(written!='z' && written=='x')
  {
 written='z';
 myPort.write(written);
  }
}else

if((mousePressed==true && Cover==true)||cpressed==true)
{
 if(written!='c' && written=='x')
  {
 written='c';
 myPort.write(written);
  }
}else

if((mousePressed==true && Xover==true)||xpressed==true)
{
  if(written!='x')
{
 written='x';
 myPort.write(written);
}
}else

if((mousePressed==true && autover==true)||autpressed==true)
{
    if(written!='1')
{
 written='1';
 myPort.write(written);
 aut=true;
}
 
}else

if((mousePressed==true && manover==true)||manpressed==true)
{
     if(written!='2')
{
 written='2';
 myPort.write(written);
 aut=false;
}
}
fill(255);
textSize(28);
text("Command Received:", 360, 230);
text( (char)newinByte,560,230);


}
void update(int x, int y)
{
  if(overRect(390,450+5,wid,hei))
  {Wover=true;}else 
   if(overRect(390,520+5,wid,hei))
  {Sover=true;}else
   if(overRect(320,520+5,wid,hei))
  {Aover=true;}else
   if(overRect(460,520+5,wid,hei))
  {Dover=true;}
  else
  {
    Wover=false;
    Aover=false;
    Sover=false;
    Dover=false;
    
  }
 if(overRect(100+60,182+70,wid,wid))
  {Qover=true;}else
  if(overRect(640-60,182+70,wid,wid))
  {Eover=true;}else
  if(overRect(100+60,288+40,wid,wid))
  {Zover=true;}else
  if(overRect(640-60,288+40,wid,wid))
  {Cover=true;}else
  if(overRect(141,520+5,wid,wid-5))
  {Xover=true;}else
  if(overRect(351-50,128,wid+30,wid-5))
  {autover=true;}else
  if(overRect(448-35,128,wid+30,wid-5))
  {manover=true;}
  else
  {
    Qover=false;
    Eover=false;
    Zover=false;
    Cover=false;
    Xover=false;
    autover=false;
    manover=false; 
  }
 
 
}
 void keyPressed()
 {
   if(key=='w' || key=='W')
   {
   wpressed=true;
   
//myPort.write('w');
   }else
if(key=='a' || key=='A')
   {
     apressed=true;
   //myPort.write('a');
   }else
  if(key=='s' || key=='S')
   {
     spressed=true;
   //myPort.write('s');
   }else
  if(key=='d' || key=='D')
   {
   dpressed=true;
   //myPort.write('d');
   } else
  if(key=='q' || key=='Q')
   {
   qpressed=true;
   //myPort.write('q');
   } else
  if(key=='e' || key=='E')
   {
   epressed=true;
   //myPort.write('e');
   }  else
   if(key=='z' || key=='Z')
   {
   zpressed=true;
   //myPort.write('z');
   }
    else
   if(key=='c' || key=='C')
   {
   cpressed=true;
   //myPort.write('c');
   }   else
   if(key=='x' || key=='X')
   {
   xpressed=true;
   //myPort.write('c');
   }   else
   if(key=='1')
   {
   autpressed=true;
   //myPort.write('c');
   }   else
   if(key=='2')
   {
   manpressed=true;
   //myPort.write('c');
   }  
}
void keyReleased()
{
 wpressed=apressed=spressed=dpressed=qpressed=epressed=zpressed=cpressed=xpressed=autpressed=manpressed=false;
}
/*
void mousePressed()
{
 print(" "+mouseX+" "+mouseY); 
}
*/
boolean overRect(int x, int y, int width, int height)  
{
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}

void serialEvent(Serial myPort) {
  
  newinByte = myPort.read();
}
