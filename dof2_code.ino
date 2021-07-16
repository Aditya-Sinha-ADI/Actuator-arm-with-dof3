
#include <Servo.h>
#define pi 3.14159265358979323846
Servo servo1;
Servo servo2;
double pos1=0;
double pos2=0;
double angular_speed=100; //degree per second
int dp;
int pot_pin1=A0;
int pot_pin2=A1;
int pot1_value;
int pot2_value;
double x;
double y;
void setup()
{
  Serial.begin(9600);
  servo1.attach(9, 500, 2500);
  servo2.attach(10, 500, 2500);
  servo1.write(pos1);
  servo2.write(pos1);
  delay(15);

}

void loop()
{
  pot1_value = analogRead(pot_pin1);
  pot2_value = analogRead(pot_pin2);
  x = map(pot1_value, 0, 1023, 0, 200000);
  y = map(pot2_value, 0, 1023, 0, 200000);
  double alpha,theeta2,theeta1;
  x=x/100000;
  y=y/100000;
  if(4>=((x*x)+(y*y)))
     {//yoblock
  
    
    alpha= acos((2-(x*x)-(y*y))/2);
    theeta2= pi-alpha;    
    theeta1 = atan(y/x)+atan(sin(theeta2)/(1+cos(theeta2)));
    
    
    theeta1=(180/pi)*theeta1;
    
    theeta2=(180/pi)*theeta2;
  	delay(15);
    Serial.print("Current coordinate-(");
  	Serial.print(x, DEC);
    Serial.print(", ");
  	Serial.print(y, DEC);
    Serial.println(" )");
    Serial.print("theeta1: ");
    Serial.println(theeta1, DEC);
    Serial.print("theeta2: ");
    Serial.println(theeta2, DEC);
  
       
	double time=1/angular_speed;
    time=time*1000;
    
    if(theeta2<=pos2)//expand,ie,angle2 decrease
    {
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
    
    
    }
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
    }//yoblock
  else 
     {
       Serial.println("INAPPROPRIATE COORDINATES");
    	delay(15);
     }
  

  delay(1000);
}






