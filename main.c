#include <stdio.h>
#include <stdlib.h>

long fvco, fosc, fx;
int option = 0;

int main(int argc, char** argv) {
	long r, b, a;
	printf("LMX2306 PLL paramater values finder V1.0 Luigi Findanno 2020\n");
	printf("enter the desidered VCO frequency (Hz) ");
	scanf("%ld", &fvco);
	printf("enter the reference oscillator frequency (Hz) ");
	scanf("%ld", &fosc);	
	// use the bruteforce
	for(r = 3; r <= 16383; r++){
		for(b = 3; b <= 8191; b++){
			for(a = 0; a <= b; a++){
				if (a == 8) break;
				fx = ((8 * b) + a) * fosc / r;
				
				if (fx == fvco){
					option++;
					printf("Option %d\n", option);
					printf("B = %ld\n",b);
					printf("A = %ld\n",a);
					printf("R = %ld\n",r);
					
				}
			}
		}
	}
	printf("End");
	return 0;
}
