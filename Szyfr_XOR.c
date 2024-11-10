#include <stdio.h>
#include <string.h>

void xor_cipher(char input[], char output[], char key[]) { //funkcja szyfrująca i jednocześnie deszyfrująca
    size_t input_len = strlen(input); //pobiernaie długości tekstu
    size_t key_len = strlen(key); //pobiernaie długości klucza

    for (size_t i = 0; i < input_len; i++) { //wchodzimy w pętlę aby odczytać każdy znak
        output[i] = input[i] ^ key[i % key_len]; //szyfrujemy/rozszyfrowujemy znak przy pomocy operacji XOR
    }
    output[input_len] = '\0';//dodajemy znak końca napisu
}

int main() {
    char input[256];
    char key[256];
    char output[256];

    printf("Prosze wprowadzic tekst: ");
    gets(input);

    printf("Prosze podac klucz: ");
    gets(key);
    xor_cipher(input, output, key); //funkcja szyfrująca i jednocześnie deszyfrująca

    printf("Output: %s\n", output);
    //pragne podkreslic ze szyfrowanie slowo HELLO z kluczem K wychodzi  ' ♥♫♦' ale przy urzyciu maly k jest '#.''$' i odszyfrowanie działa poprawnie
    return 0;
}
/*Notatka dla mnie
Szyfr XOR: Prosty, ale skuteczny (jeśli używany właściwie)

Szyfr XOR to jedna z najprostszych, ale jednocześnie bardzo skutecznych metod szyfrowania, o ile spełnione są pewne warunki. Jego działanie opiera się na operacji XOR, która jest podstawową operacją logiczną.
Jak działa szyfr XOR?

    Operacja XOR: XOR (eXclusive OR) to operacja logiczna, która daje wynik "prawda" tylko wtedy, gdy dokładnie jeden z dwóch operandów jest "prawda". W kontekście szyfrowania, operujemy na bitach (zerach i jedynkach).
    Szyfrowanie: Każdy bit tekstu jawnego jest XOR-owany z odpowiednim bitem klucza. Wynik tej operacji to zaszyfrowany bit.
    Deszyfrowanie: Aby odzyskać oryginalny tekst, wykonujemy tę samą operację XOR, używając tego samego klucza. Co ciekawe, operacja XOR jest symetryczna, czyli szyfrowanie i deszyfrowanie odbywa się za pomocą tej samej operacji.
*/

