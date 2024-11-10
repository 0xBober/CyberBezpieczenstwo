#include <stdio.h>
#include <string.h> // biblioteka do obsługi napisów, strlen zwraca długość napisu

void caesarCipher(char tekst[], int przesuniecie) { //działamy na wartościach w ASCII dlatego możemy używać modulo 26
    for (int i = 0; i < strlen(tekst); i++) { // wchodzimy w pętlę aby odczytać każdy znak, strlen zwraca dlugosc napisu
        if (tekst[i] >= 'A' && tekst[i] <= 'Z') { // sprawdzamy czy znak jest wielką literą
            tekst[i] = (tekst[i] - 'A' + przesuniecie) % 26 + 'A'; // przesuwamy znak o przesuniecie
        } else if (tekst[i] >= 'a' && tekst[i] <= 'z') { // sprawdzamy czy znak jest małą literą
            tekst[i] = (tekst[i] - 'a' + przesuniecie) % 26 + 'a'; // przesuwamy znak o przesuniecie
        }
    }
}

void caesarDecipher(char tekst[], int przesuniecie) {//działamy na wartościach w ASCII dlatego możemy używać modulo 26
    for (int i = 0; i < strlen(tekst); i++) {// wchodzimy w pętlę aby odczytać każdy znak
        if (tekst[i] >= 'A' && tekst[i] <= 'Z') {//sprawdzamy czy znak jest wielką literą
            tekst[i] = (tekst[i] - 'A' - przesuniecie + 26) % 26 + 'A'; //przesuwamy znak o przesuniecie w odwrotną stronę
        } else if (tekst[i] >= 'a' && tekst[i] <= 'z') {//sprawdzamy czy znak jest małą literą
            tekst[i] = (tekst[i] - 'a' - przesuniecie + 26) % 26 + 'a';//przesuwamy znak o przesuniecie w odwrotną stronę
        }
    }
}

int main() {
    char text[100];
    int shift;
    int choice;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Encode\n");
        printf("2. Decode\n");
        printf("3. Exit\n");
        printf("Twoj wybor: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        printf("Enter the text: ");
        scanf(" %[^\n]s", text); // pobieramy tekst od użytkownika

        printf("Enter the shift: ");
        scanf("%d", &shift); // pobieramy przesunięcie od użytkownika

        if (choice == 1) {
            caesarCipher(text, shift); // szyfrujemy tekst
            printf("Encrypted text: %s\n", text); //zwracamy zaszyfrowany tekst
        } else if (choice == 2) {
            caesarDecipher(text, shift); // deszyfrujemy tekst
            printf("Decrypted text: %s\n", text); //zwracamy odszyfrowany tekst
        } else {
            printf("Nie poprawny wybor. Sproboj ponownie.\n");
        }
    }

    return 0;
}

/*
Szyfr Cezara to jedna z najprostszych technik szyfrowania. Działa na zasadzie przesunięcia każdej litery w alfabecie o określoną, stałą liczbę miejsc.

Jak to działa?

    Wybieramy klucz: Jest to liczba, o którą przesuniemy każdą literę. Na przykład, jeśli klucz wynosi 3, to literę "A" zastąpimy literą "D", "B" literą "E" itd.
    Szyfrowanie: Każdą literę w oryginalnym tekście przesuwamy o wybraną liczbę miejsc w alfabecie. Jeśli dojdziemy do końca alfabetu, "zawijamy" się na początek.
    Deszyfrowanie: Aby odczytać zaszyfrowany tekst, wykonujemy odwrotną operację – przesuwamy każdą literę o liczbę miejsc równą wartości klucza, ale w przeciwnym kierunku.

Przykład:

Jeśli chcemy zaszyfrować słowo "KOTA" z kluczem 3, otrzymamy:

    K -> M
    O -> R
    T -> W
    A -> D

Zaszyfrowane słowo to więc "MRWD".

Dlaczego szyfr Cezara nie jest już bezpieczny?

Szyfr Cezara jest bardzo łatwy do złamania, zwłaszcza przy użyciu komputera. Istnieje tylko 25 możliwych kluczy dla alfabetu łacińskiego, więc złamanie takiego szyfru to kwestia sprawdzenia każdej z możliwości.

Zastosowanie szyfru Cezara:

Chociaż szyfr Cezar nie jest już używany do zabezpieczania ważnych informacji, to nadal może być przydatny jako proste ćwiczenie do nauki podstaw kryptografii.
*/