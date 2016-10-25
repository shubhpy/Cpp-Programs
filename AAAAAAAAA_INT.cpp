char	             1 byte	       -128 to 127 or 0 to 255
unsigned char	     1 byte	        0 to 255
signed char	         1 byte	       -128 to 127
int	                 2 or 4 bytes  -32,768 to 32,767 or -2,147,483,648 to 2,147,483,647
unsigned int	     2 or 4 bytes	0 to 65,535 or 0 to 4,294,967,295
short	             2 bytes	   -32,768 to 32,767
unsigned short	     2 bytes	    0 to 65,535
long	             4 bytes	   -2,147,483,648 to 2,147,483,647
unsigned long	     4 bytes	    0 to 4,294,967,295

Data Type             Memory (bytes)          Range                      Format Specifier
short int                   2          -32,768 to 32,767                       %hd
unsigned short int          2           0 to 65,535                            %hu
unsigned int                4           0 to 4,294,967,295                     %u
int                         4          -2,147,483,648 to 2,147,483,647         %d
long int                    4          -2,147,483,648 to 2,147,483,647         %ld
unsigned long int           4           0 to 4,294,967,295                     %lu
long long int               8          -(2^63) to (2^63)-1                     %lld
unsigned long long int      8           0 to 18,446,744,073,709,551,615        %llu
signed char                 1          -128 to 127                             %c
unsigned char               1           0 to 255                               %c
float                       4                                                  %f
double                      8                                                  %lf
long double                 12                                                 %Lf
