#include<stdio.h>

int mystery(unsigned);
int main(){
	unsigned x;
	printf("Dame un numero: \n");
	scanf("%u",&x);
	printf("\nEl resultado es %d \n",mystery(x));
	return 0;
}
int mystery(unsigned bits){
	unsigned i, mask=1<<15, total =0;
        printf("Valor MASK: %d\n",mask);
	for(i=0;i<=16;i++,bits<<=1)
                printf(" bits: %d \n",bits);
		if((bits&mask)==mask)
                    printf(" > bits: %d \n",bits);
			++total;
			
		return total % 2==0 ? 1 : 0 ;
}