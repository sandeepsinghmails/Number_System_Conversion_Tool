/* 
 * Author: Sandeep Singh
 * Date  : Oct 27, 2012
 * 
 * Copyright 2012 Sandeep Singh (sandeepsinghmails@gmail.com)
 *
 * This file is part of Number System Conversion Tool.
 * Number System Conversion Tool is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Number System Conversion Tool is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Volume Controller. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 30

long int powerfunc ( int base, 
					 int power);

long int convert_to_decimal (char *array,
							 int base);

void convert_from_dec_to_anybase(long int decimal_no, 
								 int divisor);

int main()
{
	char num_to_convert[SIZE];

	int base_system;
	int target_system;

	long int decimal_no;

	printf ("\nEnter the Number to Convert: ");
	scanf  ("%s", num_to_convert);

	printf ("\nEnter the Current Number System (2 for Bin, 10 for Dec, 8 for Oct, 16 for Hex): ");
	scanf  ("%d", &base_system);

	printf ("\nEnter the Target System (2 for Bin, 10 for Dec, 8 for Oct, 16 for Hex): ");
	scanf   ("%d", &target_system);

	if (base_system==10)
	{
		decimal_no = atoi(num_to_convert); 
		convert_from_dec_to_anybase(decimal_no, target_system); 
	}
	else 
	{
		if (target_system==10)
		{
			decimal_no = convert_to_decimal(num_to_convert, base_system);
			printf ("\nDecimal Number = %ld\n", decimal_no);
		}
		else
		{
			decimal_no = convert_to_decimal(num_to_convert, base_system);
			convert_from_dec_to_anybase(decimal_no, target_system); 
		}
	}

	return 0;
}

long int convert_to_decimal (char *array,
						int base)
{
	long int decimal_numb = 0;
	int power = 0;
	int counter=0;
	int length;

	length = strlen(array);

	while (length-1-counter>=0)
	{
		if (base==16)
		{
			switch(array[length-1-counter])
			{
				case 'A':
				{
					decimal_numb = decimal_numb+10*powerfunc(base, power);
					counter++;
					power++;
					break;
				}
				case 'B':
				{
					decimal_numb = decimal_numb+11*powerfunc(base, power);
					counter++;
					power++;
					break;
				}
				case 'C':
				{
					decimal_numb = decimal_numb+12*powerfunc(base, power);
					counter++;
					power++;
					break;
				}
				case 'D':
				{
					decimal_numb = decimal_numb+13*powerfunc(base, power);
					counter++;
					power++;
					break;
				}
				case 'E':
				{
					decimal_numb = decimal_numb+14*powerfunc(base, power);
					counter++;
					power++;
					break;
				}
				case 'F':
				{
					decimal_numb = decimal_numb+15*powerfunc(base, power);
					counter++;
					power++;
					break;
				}
				default:
				{
					decimal_numb = decimal_numb+(array[length-1-counter++]-'0')*powerfunc(base, power);
					power++;
				}
			}
		}
		else
		{
			decimal_numb = decimal_numb+(array[length-1-counter++]-'0')*powerfunc(base, power);
			power++;
		}
	}

	return decimal_numb;
}

void convert_from_dec_to_anybase(long int decimal_no, 
								 int 	  divisor)
{
	int quotient;
	int remainder;

	int top = -1;

	int array [SIZE];

	int counter;

	memset (array, -1, SIZE);

	while (decimal_no!=1 && decimal_no!=0 && (decimal_no>=divisor))
	{
		counter = 1;
		while (divisor*counter<=decimal_no)
		{
			counter++;
		}

		remainder = decimal_no%(divisor*(counter-1));
		quotient  = counter-1;					  /* 'quotient' is used -- just for clarity */
		decimal_no    = quotient;

		/* PUSH Number on Stack */
		if (top<=SIZE)
		{
			array[++top] = remainder;
		}
	}

		/* PUSH Last Leftover Digit on Stack */
		if (top<=SIZE)
		{
			array[++top] = decimal_no;
		}

	printf ("\nEquivalent Number in Base %d is:\n\n", divisor);
	/* Pop & Print Items from Stack */
	while (top!= -1)
	{
		/* For Hexadecimal Numbers */
		if ((divisor==16)&&(array[top]>9)&&(array[top]<16))
		{
			switch (array[top])
			{
				case 10:
				{
						printf ("A");
						top--;
						break;
				}
				case 11:
				{
						printf ("B");
						top--;
						break;
				}
				case 12:
				{
						printf ("C");
						top--;
						break;
				}
				case 13:
				{
						printf ("D");
						top--;
						break;
				}
				case 14:
				{
						printf ("E");
						top--;
						break;
				}
				case 15:
				{
						printf ("F");
						top--;
						break;
				}
				/* Default case is NOT required here, since we have a strict range check */
			}

		}
		else
		{
			printf ("%d", array[top--]);
		}
	}
	printf ("\n\n");
}


long int powerfunc ( int base, 
					 int power)
{
	long int temp =1;

	if (power==0)
	{
		return 1;
	}
	else if (power==1)
	{
		return base;
	}

	while (power--)
	{
		temp *= base;
	}

	return temp;
}
