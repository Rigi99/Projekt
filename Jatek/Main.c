#include "Header.h"
int main()
{
	Palya* palya = createPalya("1szint.txt");
	int valasztas;
	printf("MESTERLOVESZ\n");
	printf("\t1. Uj jatek\n\t2.Szabalyok es iranyitas\n\t3.Kilepes\n");
	scanf("%i", &valasztas);
	while (valasztas != 3) {
		switch (valasztas) {
		case 1:
			system("CLS");
			beolvasPalya("1szint.txt", palya->palya);
			palya = jatekMenet(palya);
			if (palya->b) {
				system("CLS");
				printf("A fegyvert a G jelzi! A lovedekeket l jelzi. Szukseg lesz ra az utolso szinten!\n");
				beolvasPalya("2szint.txt", palya->palya);
				palya = jatekMenet(palya);
			}
			else {
				system("CLS");
				printf("Jatek vege!\n");
				break;
			}
			if (palya->b) {
				system("CLS");
				printf("Gyozd le a BOSSt!\n");
				beolvasPalya("3szint.txt", palya->palya);
				palya = jatekMenetExtra(palya);
			}
			else {
				system("CLS");
				printf("Jatek vege!\n");
				break;
			}
			if (palya->b) {
				system("CLS");
				printf("Jatek teljesitve! Gratulalunk!\n");
				break;
			}
			else {
				system("CLS");
				printf("Jatek vege!\n");
				break;
			}
			break;
		case 2:
			system("CLS");
			kiirSzabalyok();
			break;
		default:
			printf("Hibas parancs!\n");
			break;
		}
		printf("\nMESTERLOVESZ\n");
		printf("\t1. Uj jatek\n\t2.Szabalyok es iranyitas\n\t3.Kilepes\n");
		scanf("%i", &valasztas);
	}
	return -5;
}