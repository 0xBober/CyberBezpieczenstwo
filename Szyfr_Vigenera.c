#include <stdio.h>
#include <string.h>

void encryptVigenere(char plaintext[], char key[], char ciphertext[]) {//funckja szyfrująca
    int textLen = strlen(plaintext); //podajemy długość tekstu
    int keyLen = strlen(key); //podajemy długość klucza
    
    for (int i = 0; i < textLen; i++) {//wchodzimy w pętlę aby odczytać każdy znak
        char plainChar = plaintext[i]; //przypisujemy znak z tekstu do zmiennej
        char keyChar = key[i % keyLen]; //przypisujemy znak z klucza do zmiennej 
                
        if (plainChar >= 'A' && plainChar <= 'Z') { //sprawdzamy czy znak jest wielką literą
            ciphertext[i] = ((plainChar - 'A') + (keyChar - 'A')) % 26 + 'A'; //szyfrujemy znak
        } else if (plainChar >= 'a' && plainChar <= 'z') { //sprawdzamy czy znak jest małą literą
            ciphertext[i] = ((plainChar - 'a') + (keyChar - 'a')) % 26 + 'a';//szyfrujemy znak
        } else {
            ciphertext[i] = plainChar;//jeśli znak nie jest literą to go zostawiamy
        }
    }
    ciphertext[textLen] = '\0';//dodajemy znak końca napisu
}

void decryptVigenere(char ciphertext[], char key[], char plaintext[]) { //funkcja deszyfrująca
    int textLen = strlen(ciphertext); //podajemy długość tekstu
    int keyLen = strlen(key);//podajemy długość klucza
    
    for (int i = 0; i < textLen; i++) {//wchodzimy w pętlę aby odczytać każdy znak
        char cipherChar = ciphertext[i];//przypisujemy znak z tekstu do zmiennej
        char keyChar = key[i % keyLen];//przypisujemy znak z klucza do zmiennej
        
        if (cipherChar >= 'A' && cipherChar <= 'Z') {//sprawdzamy czy znak jest wielką literą
            plaintext[i] = ((cipherChar - 'A') - (keyChar - 'A') + 26) % 26 + 'A';//deszyfrujemy znak
        } else if (cipherChar >= 'a' && cipherChar <= 'z') {//sprawdzamy czy znak jest małą literą
            plaintext[i] = ((cipherChar - 'a') - (keyChar - 'a') + 26) % 26 + 'a';//deszyfrujemy znak
        } else {
            plaintext[i] = cipherChar;//jeśli znak nie jest literą to go zostawiamy
        }
    }
    plaintext[textLen] = '\0';//dodajemy znak końca napisu
}

int main() {
    char plaintext[256];
    char key_1[256];
    char ciphertext[256];
    char key_2[256];
    char decryptedtext[256];

    int choice;
    while (1) { // wchodzimy w pętlę aby program działał do momentu wybrania opcji 3
        printf("Wybierz opcje:\n1. Szyfrowanie\n2. Deszyfrowanie\n3. Wyjscie\n");
        scanf("%d", &choice);
        getchar(); // usuwamy znak nowej linii z bufora

        if (choice == 1) {
            printf("Prosze wprowadzic tekst do zaszyfrowania: ");
            gets(plaintext); //pobieramy tekst od użytkownika

            printf("Prosze wprowadzic klucz do szyfrowania: ");
            gets(key_1); //pobieramy klucz od użytkownika

            encryptVigenere(plaintext, key_1, ciphertext);//funckja szyfrująca
            printf("Encrypted text: %s\n", ciphertext);//zwracamy zaszyfrowany tekst
        } else if (choice == 2) {
            printf("Prosze wprowadzic tekst do odszyfrowania: ");
            gets(ciphertext); //pobieramy tekst od użytkownika

            printf("Prosze wprowadzic klucz do deszyfrowania: ");
            gets(key_2); //pobieramy klucz od użytkownika

            decryptVigenere(ciphertext, key_2, decryptedtext); //funckja deszyfrująca
            printf("Decrypted text: %s\n", decryptedtext);//zwracamy odszyfrowany tekst
        } else if (choice == 3) {
            break; // zakonczenie programu
        } else {
            printf("Nieprawidlowy wybor.\n"); //komunikat o błędzie
        }
    }

    return 0;
}

/*To jest Notatka dla nie

Szyfr Vigenère'a jest rozwinięciem szyfru Cezara i stanowił przez wiele lat znaczący krok naprzód w dziedzinie kryptografii. Jednak, podobnie jak jego prostszy odpowiednik, z perspektywy współczesnej został uznany za złamany.

Na czym polega jego działanie?

    Klucz: Zamiast jednego stałego przesunięcia dla wszystkich liter, szyfr Vigenère'a wykorzystuje klucz, który jest powtarzanym słowem lub zdaniem.
    Tablica Vigenère'a: To specjalna tabela, która umożliwia szyfrowanie. Każdy wiersz w tej tablicy odpowiada szyfrowi Cezara z innym przesunięciem.
    Szyfrowanie: Pierwsza litera tekstu jawnego jest szyfrowana za pomocą pierwszej litery klucza, druga litera tekstu jawnego za pomocą drugiej litery klucza itd. Gdy dojdziemy do końca klucza, zaczynamy od początku.

Dlaczego szyfr Vigenère'a był uważany za bezpieczny?

    Zmienny klucz: Dzięki użyciu klucza, który zmienia się co literę, szyfr Vigenère'a był znacznie trudniejszy do złamania niż szyfr Cezara.
    Powtarzający się wzór: Jednakże, powtarzający się wzór klucza mógł być wykorzystany do analizy częstotliwości liter, co ułatwiało kryptoanalizę.

Dlaczego szyfr Vigenère'a nie jest już bezpieczny?

    Metody statystyczne: Rozwój kryptoanalizy pozwolił na opracowanie skutecznych metod statystycznych do złamania szyfru Vigenère'a, nawet dla bardzo długich kluczy.
    Komputery: Komputery znacznie przyspieszyły proces łamania szyfrów, czyniąc szyfr Vigenère'a przestarzałym.

Podsumowanie

Szyfr Vigenère'a był kiedyś uważany za bardzo bezpieczny, ale rozwój kryptografii i pojawienie się komputerów sprawiły, że został złamany. Choć ma on znaczenie historyczne, współcześnie nie jest już stosowany do zabezpieczania informacji.

*/