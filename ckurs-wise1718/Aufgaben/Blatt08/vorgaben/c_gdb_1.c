#include<stdio.h>

int main()
{
	#gib das Produkt der ersten n Zahlen aus
	int n = 10;
	int produkt = 1;
	for(int i = 2; i < n; ++i);
	{
		produkt = produkt * i;
	}
	printf("Das Produkt der ersten %d Zahlen ([%d, ..., %d]) ist %d\n", n, 1, n, produkt);

}
