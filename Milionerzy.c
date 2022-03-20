#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include "C:\Users\user\source\repos\Milionerzy\Milionerzy\k.h"

typedef char* String;
typedef enum { TRUE = 1, FALSE = 0 } bool;
bool litera;
char* wynik;
String b;
int tab, pomoc;
int suma = 0;
char* fgets(char* str, int num, FILE* stream);
int los[76];
int i = 0;
time_t start, end;
int liczba123;
int d, dx, dxx, dxxx;
struct a {
	int numer_pytania;
	String str1;
	String poprawna_odpowiedz;
	String wygrana;
};

char c;
void czyszczenie_bufora()
{
	while ((c = getchar()) != '\n');
}

int litera_odpowiedzi() {
		while (b != 'A' && b != 'B' && b != 'C' && b != 'D' && b != '8' && b != '9' && b!= '7') {
			printf("\nNiepoprawna litera podaj odpowiedz jeszcze raz: ");
			scanf("%s", &b);
			litery_f();
	}
	return b;
}
int litera_odpowiedzi_pytanie9() {
	while (b != 'A' && b != 'B' && b != 'C' && b != 'D' && b != '8') {
		printf("\nNiepoprawna litera podaj odpowiedz jeszcze raz: ");
		scanf("%s", &b);
		litery_f();
	}
	return b;
}
int litera_odpowiedzi_pytanie8() {
	while (b != 'A' && b != 'B' && b != 'C' && b != 'D' && b != '9') {
		printf("\nNiepoprawna litera podaj odpowiedz jeszcze raz: ");
		scanf("%s", &b);
		litery_f();
	}
	return b;
}
int litera_odpowiedzi_pytanie_brak() {
	while (b != 'A' && b != 'B' && b != 'C' && b != 'D') {
		printf("\nNiepoprawna litera podaj odpowiedz jeszcze raz: ");
		scanf("%s", &b);
		litery_f();
	}
	return b;
}
int litery_f()
{
	litera = islower(b) == 0 ? FALSE : TRUE;
	if (litera == TRUE)
	{
		wynik = toupper(b);
		b = wynik;
		fflush(stdin);
	}
}
int czas_przerwa()
{
	time(&start);
	do time(&end); while (difftime(end, start) <= 2.5);
	system("cls");
}
int losowanie_pytania()
{
	srand(time(NULL));
	for (int i = 0; i < 76; i++) {     // wypelniamy
		los[i] = i;
	}

	for (int i = 0; i < 76; i++) {    // losujemy
		int temp = los[i];
		int randomIndex = rand() % 76;

		los[i] = los[randomIndex];
		los[randomIndex] = temp;
	}
}
void niepoprawna()
{
		printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
		czas_przerwa();
}

int main() {
	struct a ques_1;
	FILE* pfile;
	pfile = fopen("pytania.txt", "r");
	struct a* tab;
	tab = malloc(sizeof(struct a) * 12);
	srand(time(NULL));
	{
		int w = 0;
		do
		{
			char tak;
			int x = 1;
			int y = 1;
			int o = 1;
			losowanie_pytania();
			printf("Wybierz jedna opcje z podanych: ");
			printf("\n1.Graj\n2.Pomoc\n3.Autor\n4.Wyjscie\n");
			printf("\nPodaj numer: ");
			scanf("%d", &w);
			switch (w)
			{
				system("cls");
			case 1:
				printf("************* WITAJ W GRZE MILIONERZY ************* \n");
				printf("Od wygrania miliona dzieli cie tylko i wylacznie 12 pytan :)\n\n");
				printf("Czy jestes gotowy? (T)\n");
				czyszczenie_bufora();
				scanf("%s", &tak);
				if (tak == 'T' || tak == 't')
				{
					system("cls");
					{
						for (i = 0; i <= 11; i++)
						{
							system("cls");
							fgets(str1[los[i]], 0, "pytania.txt");
							tab[i].numer_pytania = i + 1;
							printf("\033[0;36mJezeli chcesz skorzystac z kola telefon do przyjaciela, wcisnij 7 :)\n");
							printf("Jezeli chcesz skorzystac z kola ratunkowego 50/50, wcisnij 8 :)\n");
							printf("Jezeli chcesz skorzystac z kola ratunkowego pytanie do publicznosci, wcisnij 9 :)\n\033[0m");
							if (i == 0)
								printf("\t\t\t\t\t\t\t\t\t\t\t\x1b[33mAktualna wygrana: 0\n\033[0m");
							else
								printf("\t\t\t\t\t\t\t\t\t\t\t\x1b[33mAktualna wygrana: %s\n\033[0m", wygrana[i - 1]);
							printf("Pytanie nr ");
							printf("%d.\n%s\n", tab[i].numer_pytania, str1[los[i]]);
							printf("Podaj odpowiedz: ");
							scanf("%s", &b);
							litery_f();
							litera_odpowiedzi();
							if (i == 11)
							{
								printf("\n\033[0;36mWygrales milion - 1.000.000 zl!\n");
								printf("\nTo bylo ostanie pytanie.\nDziekuje za gre :)\033[0m");
								czas_przerwa();
								break;
							}
							if (b == poprawna_odpowiedz[los[i]]) {
								czyszczenie_bufora();
								printf("\nTo jest poprawna odpowiedz!\n");
								printf("Przechodzisz dalej!!!\n");
								printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
								printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
								czas_przerwa();
							}
							else if (b == '7') {
								if (o == 1) {
									o++;
									telefon();
									printf("\nPodaj odpowiedz: ");
									scanf("%s", &b);
									litery_f();
									if (b == poprawna_odpowiedz[los[i]]) {
										czyszczenie_bufora();
										printf("\nTo jest poprawna odpowiedz!\n");
										printf("Przechodzisz dalej!!!\n");
										printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
										printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
										czas_przerwa();
									}
									else {
										niepoprawna();
										break;
									}
								}
								else {
									czyszczenie_bufora();
									printf("Nie masz juz dostepnego kola pytanie do przyjaciela.\n");
									printf("\nPodaj odpowiedz: \n");
									scanf("%s", &b);
									litery_f();
									litera_odpowiedzi_pytanie_brak();
									if (b == poprawna_odpowiedz[los[i]]) {
										czyszczenie_bufora();
										printf("Przechodzisz dalej!!!\n");
										printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
										printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
										czas_przerwa();
									}
									else {
										niepoprawna();
										break;
									}
									}
								}
							else if (b == '9')
							{
								if (x == 1) {
									zapasowe();
									x++;
									printf("\nPodaj odpowiedz: ");
									scanf("%s", &b);
									litery_f();
									litera_odpowiedzi();
									if (b == poprawna_odpowiedz[los[i]]) {
										czyszczenie_bufora();
										printf("\nTo jest poprawna odpowiedz!\nPrzechodzisz dalej!!!\n");
										printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
										printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
										czas_przerwa();
									}
									else if (b == '8') {
										if (y == 1)
										{
											y++;
											kolo2();
											if (poprawna_odpowiedz[los[i]] == 'A' || poprawna_odpowiedz[los[i]] == 'B' || poprawna_odpowiedz[los[i]] == 'C' || poprawna_odpowiedz[los[i]] == 'D')
											{
												printf("\nPodaj swoja odpowiedz: ");
												scanf("%s", &b);
												litery_f();
												litera_odpowiedzi_pytanie_brak();
												if (b == poprawna_odpowiedz[los[i]])
												{
													czyszczenie_bufora();
													printf("\nTo jest poprawna odpowiedz!\n");
													printf("Przechodzisz dalej!!!\n");
													printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
													printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
													czas_przerwa();
												}
												else
												{
													printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
													czas_przerwa();
													break;
												}
											}
										}
										else {
											printf("Nie masz juz dostepnego kola pytanie do publicznosci\n");
											printf("\nPodaj odpowiedz: ");
											scanf("%s", &b); 
											if(x == 1)
												litera_odpowiedzi_pytanie8();
											else {
												printf("Nie masz juz dostepnego kola 50/50\n");
												litera_odpowiedzi_pytanie_brak();
											}
											litery_f();
											if (b == poprawna_odpowiedz[los[i]]) {
												czyszczenie_bufora();
												printf("Przechodzisz dalej!!!\n");
												printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
												printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
												czas_przerwa();
											}
											else {
												printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
												czas_przerwa();
												break;
											}
										}
									}
									else {
										printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
										czas_przerwa();
										break;
									}
								}
								else {
									czyszczenie_bufora();
									printf("Nie masz juz dostepnego kola pytanie do publicznosci\n");
									printf("\nPodaj odpowiedz: ");
									scanf("%s", &b);
									litery_f();
									if (y == 1)
										litera_odpowiedzi_pytanie9();
									else {
										printf("Nie masz juz dostepnego kola 50/50\n");
										litera_odpowiedzi_pytanie_brak();
									}
									if (b == poprawna_odpowiedz[los[i]]) {
										czyszczenie_bufora();
										printf("\nTo jest poprawna odpowiedz!\n");
										printf("Przechodzisz dalej!!!\n");
										printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
										printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
										czas_przerwa();
									}
									else if (b == '8') {
										if (y == 1)
										{
											y++;
											kolo2();
											if (poprawna_odpowiedz[los[i]] == 'A' || poprawna_odpowiedz[los[i]] == 'B' || poprawna_odpowiedz[los[i]] == 'C' || poprawna_odpowiedz[los[i]] == 'D')
											{
												printf("\nPodaj swoja odpowiedz: ");
												scanf("%s", &b);
												litery_f();
												if (b == poprawna_odpowiedz[los[i]])
												{
													czyszczenie_bufora();
													printf("\nTo jest poprawna odpowiedz!\n");
													printf("Przechodzisz dalej!!!\n");
													printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
													printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
													czas_przerwa();
												}
												else
												{
													printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
													czas_przerwa();
													break;
												}
											}
										}										
											else {
												printf("Nie masz juz dostepnego kola pytanie do publicznosci\n");
												printf("\nPodaj odpowiedz: ");
												scanf("%s", &b); 
												 litery_f();
												if (x == 1)
													litera_odpowiedzi_pytanie8();
												else {
													printf("Nie masz juz dostepnego kola 50/50\n");
													litera_odpowiedzi_pytanie_brak();
												}
												litery_f();
												if (b == poprawna_odpowiedz[los[i]]) {
													czyszczenie_bufora();
													printf("Przechodzisz dalej!!!\n");
													printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
													printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
													czas_przerwa();
												}
												else {
													printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
													czas_przerwa();
													break;
												}
											}
									}
									else {
										printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
										czas_przerwa();
										break;
									}
								}
							}
							else if (b == '8')
							{
								if (y == 1)
								{
									y++;
									kolo2();
									if (poprawna_odpowiedz[los[i]] == 'A' || poprawna_odpowiedz[los[i]] == 'B' || poprawna_odpowiedz[los[i]] == 'C' || poprawna_odpowiedz[los[i]] == 'D')
									{
										printf("\nPodaj swoja odpowiedz: ");
										scanf("%s", &b);
										litery_f();
										if (b == poprawna_odpowiedz[los[i]])
										{
											czyszczenie_bufora();
											printf("\nTo jest poprawna odpowiedz!\n");
											printf("Przechodzisz dalej!!!\n");
											printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
											printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
											czas_przerwa();
										}
										else if (b == '9') {
											if (x == 1) {
												zapasowe2();
												x++;
												printf("\nPodaj odpowiedz: ");
												scanf("%s", &b);
												litery_f();
												litera_odpowiedzi();
												if (b == poprawna_odpowiedz[los[i]]) {
													czyszczenie_bufora();
													printf("\nTo jest poprawna odpowiedz!\nPrzechodzisz dalej!!!\n");
													printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
													printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
													czas_przerwa();
												}
												else {
													printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
													czas_przerwa();
													break;
												}
											}
										}
										else
										{
											printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
											czas_przerwa();
											break;
										}
									}
								}
								else {
									czyszczenie_bufora();
									printf("Nie masz juz dostepnego kola 50/50\n");
									printf("\nPodaj odpowiedz: ");
									scanf("%s", &b);
									litery_f();
									if (x == 1)
										litera_odpowiedzi_pytanie9();
									else {
										printf("Nie masz juz dostepnego kola pytanie do publicznosci\n");
										litera_odpowiedzi_pytanie_brak();
									}
									if (b == poprawna_odpowiedz[los[i]]) {
										czyszczenie_bufora();
										printf("Przechodzisz dalej!!!\n");
										printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
										printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
										czas_przerwa();
									}
									else if (b == '9') {
										if (x == 1) {
											zapasowe();
											x++;
											printf("\nPodaj odpowiedz: ");
											scanf("%s", &b);
											litery_f();
											litera_odpowiedzi();
											if (b == poprawna_odpowiedz[los[i]]) {
												czyszczenie_bufora();
												printf("\nTo jest poprawna odpowiedz!\nPrzechodzisz dalej!!!\n");
												printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
												printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
												czas_przerwa();
											}
											else {
												printf("\nNiesety to niepoprawna odpowiedz :(\nWracasz do menu!\n\n");
												czas_przerwa();
												break;
											}
										}
										else {
											czyszczenie_bufora();
											printf("Nie masz juz dostepnego kola pytanie do publiczonosci\n");
											printf("\nPodaj odpowiedz: \n");
											scanf("%s", &b);
											if (x == 1)
												litera_odpowiedzi_pytanie8();
											else {
												printf("Nie masz juz dostepnego kola do publicznosci\n");
												litera_odpowiedzi_pytanie_brak();
											}
											litery_f();
											if (b == poprawna_odpowiedz[los[i]]) {
												czyszczenie_bufora();
												printf("Przechodzisz dalej!!!\n");
												printf("\n\033[0;36mOto twoja aktualna wygrana: %s\n\033[0m", wygrana[i]);
												printf("Czas na twoje kolejne - %d pytanie!\n", tab[i].numer_pytania + 1);
												czas_przerwa();
											}
											else {
												niepoprawna();
												break;
											}
										}
									}
									else {
										niepoprawna();
										break;
									}
								}
							}
							else
							{
								niepoprawna();
								break;
							}
						}
					}
					break;
			case 2:
				system("cls");
				printf("Witaj w sekcji pomoc! \n");
				printf("1. Gra polega na odpowiadaniu na pytania \n");
				printf("2. Masz do wyboru cztery odpowiedzi: A B C D\n");
				printf("3. Tylko jedna odpowiedz jest prawidlowa! \n");
				printf("4. Gra zawiera randomizowanych 12 pytan \n");
				printf("5. Kazde kolo ratunkowe mozna wytkorzystac tylko raz w grze!\n");
				printf("6. Kola ratunkowe mozna laczyc \n");
				printf("7. Baw sie dobrze :) \n");
				printf("Powodzenia! \n\n");
				printf("Wcisnij 9, zeby powrocic do menu:\n");
				scanf("%s", &pomoc);
				if (pomoc == 9)
					break;
				break;
			case 3:
				system("cls");
				printf("Created by Dawid Slysz\n\n");
				printf("Wcisnij dowolny klawisz, zeby powrocic do menu:\n");
				scanf("%s", &pomoc);
				if (pomoc == 9)
					break;
				break;
			case 4:
				break;
			default:
				printf("Zly wybor!\n\n");
				break;
				}
				else {
					system("cls");
					break;
				}
			}
		}while (w != 4);
	}
}
int zapasowe(){
	{
		printf("\n");
	{
			int suma = 0;
			int* tab1 = NULL;
			tab1 = malloc(sizeof(int) * 4);
			int n = 4;
			int max;
			int j;
			for (j = 0; j < 3; j++)
			{
				tab1[0] = rand() % 50;
				tab1[1] = rand() % 30;
				tab1[2] = rand() % 20;
			}
			suma = suma + tab1[0] + tab1[1] + tab1[2];
			tab1[3] = 100 - suma;
			max = tab1[0];
			for (j = 0; j < n; j++)
				if (tab1[j] > max)// jesli tak
					max = tab1[j];
			if (poprawna_odpowiedz[los[i]] == 'A')
			{
				if (max > tab1[3]) {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[0], tab1[2], tab1[1], tab1[3]);
				}
				else {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[3], tab1[2], tab1[1], tab1[0]);
				}
			}
			else if (poprawna_odpowiedz[los[i]] == 'B')
			{
				if (max > tab1[3]) {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[3], tab1[0], tab1[1], tab1[2]);
				}
				else {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[0], tab1[3], tab1[1], tab1[2]);
				}
			}
			else if (poprawna_odpowiedz[los[i]] == 'C')
			{
				if (max > tab1[3]) {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[1], tab1[3], tab1[0], tab1[2]);
				}
				else {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[1], tab1[0], tab1[3], tab1[2]);
				}
			}
			else if (poprawna_odpowiedz[los[i]] == 'D')
			{
				if (max > tab1[3]) {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[1], tab1[3], tab1[2], tab1[0]);
				}
				else {
					printf("Widownia wybrala takie oto odpowiedzi: \n");
					printf("A - %i%% B - %i%% C - %i%% D - %i%% ", tab1[1], tab1[0], tab1[2], tab1[3]);
				}
				free(tab1);
				tab1 = NULL;
			}
		}
	}
}

int kolo2() {
	srand(time(NULL));
	liczba123 = rand() % 3;
	String kolo[] = { 'B','C','D' };
	String kolo1[] = { 'A','C','D' };
	String kolo2[] = { 'A','B','D' };
	String kolo3[] = { 'A','B','C' };

	d = kolo[liczba123];
	dx = kolo1[liczba123];
	dxx = kolo2[liczba123];
	dxxx = kolo3[liczba123];

	printf("\nUzyles kola 50/50\n");
	printf("System w tym momencie eliminuje dwie niepoprawne odpowiedzi!\n");
	time(&start);
	do time(&end); while (difftime(end, start) <= 2.5);
	if (poprawna_odpowiedz[los[i]] == 'A')
	{
		printf("\nTwoje dwie odpowiedzi to: ");
		printf("%s ", &poprawna_odpowiedz[los[i]]);
		printf("lub ");
		printf("%s ", &d);
		printf("\nWybierz madrze :)");
	}
	else if (poprawna_odpowiedz[los[i]] == 'B')
	{
		printf("\nTwoje dwie odpowiedzi to: ");
		if (dx == 'A')
		{
			printf("%s ", &dx);
			printf("lub ");
			printf("%s ", &poprawna_odpowiedz[los[i]]);
			printf("\nWybierz madrze :)");
		}
		else
		{
			printf("%s ", &poprawna_odpowiedz[los[i]]);
			printf("lub ");
			printf("%s ", &dx);
			printf("\nWybierz madrze :)");
		}
	}
	else if (poprawna_odpowiedz[los[i]] == 'C')
	{
		printf("\nTwoje dwie odpowiedzi to: ");
		if (dxx == 'D')
		{
			printf("%s ", &poprawna_odpowiedz[los[i]]);
			printf("lub ");
			printf("%s ", &dxx);
			printf("\nWybierz madrze :)");
		}
		else
		{
			printf("%s ", &dxx);
			printf("lub ");
			printf("%s ", &poprawna_odpowiedz[los[i]]);
			printf("\nWybierz madrze :)");
		}
	}
	else if (poprawna_odpowiedz[los[i]] == 'D')
	{
		printf("\nTwoje dwie odpowiedzi to: ");
		printf("%s ", &dxxx);
		printf("lub ");
		printf("%s ", &poprawna_odpowiedz[los[i]]);
		printf("\nWybierz madrze :)");
	}
}
int zapasowe2() {
	{
		int suma = 0;
		int* tab1 = NULL;
		tab1 = malloc(sizeof(int) * 2);
		int n = 4;
		int max;
		int j;
		for (j = 0; j < 3; j++)
		{
			tab1[0] = rand() % 50;
		}
		suma = suma + tab1[0];
		tab1[1] = 100 - suma;
		max = tab1[0];
		for (j = 0; j < n; j++)
			if (tab1[j] > max)// jesli tak
				max = tab1[j];
		printf("\nWidownia wybrala takie dwie odpowiedzi:\n");
		if (poprawna_odpowiedz[los[i]] == 'A')
		{
			printf("%s - %i%% ", &poprawna_odpowiedz[los[i]], tab1[1]);
			printf("%s - %i%% ", &d, tab1[0]);
		}
		else if (poprawna_odpowiedz[los[i]] == 'B')
		{
			if (dx == 'A')
			{
				printf("%s - %i%% ", &dx, tab1[0]);
				printf("%s - %i%% ", &poprawna_odpowiedz[los[i]], tab1[1]);
			}
			else
			{
				printf("%s - %i%% ", &poprawna_odpowiedz[los[i]], tab1[1]);
				printf("%s - %i%% ", &dx, tab1[0]);
			}
		}
		else if (poprawna_odpowiedz[los[i]] == 'C')
		{
			if (dxx == 'D')
			{
				printf("%s - %i%% ", &poprawna_odpowiedz[los[i]], tab1[1]);
				printf("%s - %i%% ", &dxx, tab1[0]);
			}
			else
			{
				printf("%s - %i%% ", &dxx, tab1[0]);
				printf("%s - %i%% ", &poprawna_odpowiedz[los[i]], tab1[1]);
			}
		}
		else if (poprawna_odpowiedz[los[i]] == 'D')
		{
			printf("%s - %i%% ", &dxxx, tab1[0]);
			printf("%s - %i%% ", &poprawna_odpowiedz[los[i]], tab1[1]);
		}
				free(tab1);
				tab1 = NULL;
			}
		}
String z;
int telefon() {
	printf("\nPodaj imie do kogo bedziemy dzwonili: ");
		scanf("%s", &z);
		printf("\nWitaj, %s. ", &z);printf("Potrzebujemy twojej pomocy.\nJak myslisz ktora to bedzie odpowiedz? \n");
		printf("%s, zastanawia sie...\n",&z);
		time(&start);
		do time(&end); while (difftime(end, start) <= 2.5);
		if (poprawna_odpowiedz[los[i]] == 'A')
			printf("Mysle, ze to bedzie A.");
		else if (poprawna_odpowiedz[los[i]] == 'B')
			printf("Moim zdaniem bedzie to B.");
		else if (poprawna_odpowiedz[los[i]] == 'C')
			printf("Wydaje mi sie, ze to bedzie C.");
		else if (poprawna_odpowiedz[los[i]] == 'D')
			printf("Mam nadzieje, ze to bedzie D.");
		printf("\n\nDziekujemy, %s. Do uslyszenia kolejnym razem!",&z);
}
