
#include <Servo.h>
#define pi 3.14159265358979323846
Servo servo1;
Servo servo2;
Servo servo3;
double pos1=0;
double pos2=0;
double pos3=0;
double angular_speed=50; //degree per second
int dp;
int pot_pin1=A0;
int pot_pin2=A1;
int pot_pin3=A2;
int pot1_value;
int pot2_value;
int pot3_value;
double x;
double y;
double z;
double radius=2;
void setup()
{
  Serial.begin(9600);
  servo1.attach(9, 500, 2500);
  servo2.attach(10, 500, 2500);
  servo3.attach(11, 500, 2500);
  servo1.write(pos1);
  servo2.write(pos1);
  servo3.write(pos1);
  delay(15);
}

void loop()
{//funcopen
  pot1_value = analogRead(pot_pin1);
  pot2_value = analogRead(pot_pin2);
  pot3_value = analogRead(pot_pin3);
  x = map(pot1_value, 0, 1023, 0, 200000);
  y = map(pot2_value, 0, 1023, 0, 200000);
  z = map(pot3_value, 0, 1023, 0, 200000);
  double alpha,theeta2,theeta1,theeta3,x1;
  
  x=x/100000;
  y=y/100000;
  z=z/100000;
  x1=x;
  x= sqrt((x*x)+(z*z));
  
  if(4>=((x*x)+(y*y)))
     {//yoblock
  
    theeta3=atan((z/x1));
    theeta3=theeta3*(180/pi);
    
    
    alpha= acos((2-(x*x)-(y*y))/2);
    theeta2= pi-alpha;    
    theeta1 = atan(y/x)+atan(sin(theeta2)/(1+cos(theeta2)));
    
    
    theeta1=(180/pi)*theeta1;
    
    theeta2=(180/pi)*theeta2;
  	delay(15);
    Serial.print("Current coordinate-(");
  	Serial.print(x1, DEC);
    Serial.print(", ");
  	Serial.print(y, DEC);
    Serial.print(", ");
  	Serial.print(z, DEC);
    Serial.println(" )");
    Serial.print("theeta1: ");
    Serial.println(theeta1, DEC);
    Serial.print("theeta2: ");
    Serial.println(theeta2, DEC);
    Serial.print("theeta3: ");
    Serial.println(theeta3, DEC);
  	
       
	double time=1/angular_speed;
    time=time*1000;
    
    
    if(sqrt((x*x)+(z*z))<=radius)
    {//disco
    if(theeta2<=pos2)//expand,ie,angle2 decrease
    {//dancer
      if(theeta1>pos1)
      	{//woo
    	for(int i=pos1; i<=theeta1;i++)
    		{//....
      			servo1.write(i);
      			delay(time);
    		}//....
    	pos1=theeta1;
  		servo1.write(theeta1);
    	}//woo
    	else
    	{//hmmmm
      		for(int i=pos1; i>=theeta1;i--)
    			{
      				servo1.write(i);
     				delay(time);
    			}
    		pos1=theeta1;
  			servo1.write(theeta1);
    	}//hmmm
    
      	
    	for(int i=pos2; i>=theeta2;i--)
    		{//..
      			servo2.write(i);
      			delay(time);
    		}//..
    	pos2=theeta2;
  		servo2.write(theeta2);
    
    
    }//dancer
    else//contract,ie,theeta2 increase
    {//kooool
     	 
     	for(int i=pos2; i<=theeta2;i++)
    	{
      		servo2.write(i);
      		delay(time);
    	}
    	pos2=theeta2;
  		servo2.write(theeta2);
      	if(theeta1>pos1)
      	{
    		for(int i=pos1; i<=theeta1;i++)
    		{
      			servo1.write(i);
      			delay(time);
    		}
    		pos1=theeta1;
  			servo1.write(theeta1);
    	}
    	else
    	{
      		for(int i=pos1; i>=theeta1;i--)
    			{
      				servo1.write(i);
     				delay(time);
    			}
    		pos1=theeta1;
  			servo1.write(theeta1);
    	}
    }
      //motor3
      if (theeta3>=pos3)
    {
      for(int i=pos3; i<=theeta3; i++)
      {
        servo3.write(i);
      	delay(time);
      }
      pos3=theeta3;
  	  servo3.write(theeta3);
    }
    else
    {
      for(int i=pos3; i>=theeta3;i--)
    	{
      		servo3.write(i);
     		delay(time);
    	}
      pos3=theeta3;
  	  servo3.write(theeta3);
    }
    }//disco
    else
    {//disco2
      if (theeta3>=pos3)
    {
      for(int i=pos3; i<=theeta3; i++)
      {
        servo3.write(i);
      	delay(time);
      }
      pos3=theeta3;
  	  servo3.write(theeta3);
    }
    else
    {
      for(int i=pos3; i>=theeta3;i--)
    	{
      		servo3.write(i);
     		delay(time);
    	}
      pos3=theeta3;
  	  servo3.write(theeta3);
    }
      //
       if(theeta2<=pos2)//expand,ie,angle2 decrease
    {//pooooooooo
      if(theeta1>pos1)
      	{
    	for(int i=pos1; i<=theeta1;i++)
    		{
      			servo1.write(i);
      			delay(time);
    		}
    	pos1=theeta1;
  		servo1.write(theeta1);
    	}
    	else
    	{
      		for(int i=pos1; i>=theeta1;i--)
    			{
      				servo1.write(i);
     				delay(time);
    			}
    		pos1=theeta1;
  			servo1.write(theeta1);
    	}
      	
    	for(int i=pos2; i>=theeta2;i--)
    		{
      			servo2.write(i);
      			delay(time);
    		}
    	pos2=theeta2;
  		servo2.write(theeta2);
    
    
    }//pooo
    else//contract,ie,theeta2 increase
    {
     	 
     	for(int i=pos2; i<=theeta2;i++)
    	{
      		servo2.write(i);
      		delay(time);
    	}
    	pos2=theeta2;
  		servo2.write(theeta2);
      	if(theeta1>pos1)
      	{
    		for(int i=pos1; i<=theeta1;i++)
    		{
      			servo1.write(i);
      			delay(time);
    		}
    		pos1=theeta1;
  			servo1.write(theeta1);
    	}
    	else
    	{
      		for(int i=pos1; i>=theeta1;i--)
    			{
      				servo1.write(i);
     				delay(time);
    			}
    		pos1=theeta1;
  			servo1.write(theeta1);
    	}
    }
    }//disco2
    
    radius=sqrt((x*x)+(z*z));
    }//yoblock
  else 
     {//yipee
       Serial.println("INAPPROPRIATE COORDINATES");
    	delay(15);
     }//yipee
  

  delay(1000);
}//funcclose






