#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
#define lcd PORTD
  void lcd_command(unsigned char cmd)
{
lcd= cmd&0xF0;
lcd|= 0b00000100;
_delay_ms(1);
lcd&= 0xF0;
_delay_ms(1);
lcd= (cmd<<4)& 0xF0;
lcd|= 0b00000100;
_delay_ms(1);
lcd&= 0xF0;
_delay_ms(1);
}

void lcd_data(unsigned char da)
{
lcd= da&0xF0;
lcd|= 0b00000101;
_delay_ms(1);
lcd&= 0xF1;
_delay_ms(1);
lcd= (da<<4)&0xF0;
lcd|= 0b00000101;
_delay_ms(1);
lcd&= 0xF1;
_delay_ms(1);
}

void lcd_init()
{
lcd_command(0x02);
lcd_command(0x28);
lcd_command(0x0c);
lcd_command(0x06);
}
void lcd_string (unsigned char *str)
{
 char i=0;
   while( str[i]!='\0')
   { lcd_data(str[i]);
   i++;
   }
   }
   void lcd_number(unsigned int value)  // to print the ascaii value for 3 digits with decrement
     { 
	    lcd_command(0x04);
	    unsigned int a=0;
	    a= value % 10;
		lcd_data(a+48);
		value= value/10;
		a= value%10;
		lcd_data(a+48);
		value = value/10;
		a= value%10;
		lcd_data(a+48);
		lcd_command(0x06);
      }
	  


  void main()

{  unsigned char ch[10];
  DDRD= 0xff;
  lcd_init();
  while(1)
  {
    lcd_command(0x80);
	
	lcd_string("ascii => real");
        
		                            
              
  

         for(int i=0; i<=300; i++)
		   {  lcd_command(0xc2);
		      lcd_number(i);

	         lcd_command(0xc9);
	         lcd_data(i);
			 _delay_ms(100);
	        }
			
   }
}
    
