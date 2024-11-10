import copy

def dec_to_bin(liczba):
    # przetwarzanie liczby na wartość binarną
    binary = []
    while liczba != 0:
        if liczba % 2 == 1:
            liczba = (liczba-1)/2
            binary.append('1')
        else:
            liczba = liczba/2
            binary.append('0')

    # dodanie zer do uzyskania 8-bitowej reprezentacji
    while(len(binary) < 8):
        binary.append('0')

    binary.reverse()
    binary_str = ''.join(map(str, binary))

    return binary_str

def bit_count_1_f(table):
    # liczenie bitów na pozycjach parzystych
    wynik = 0
    for i in range(0, len(table), 2):
        if(table[i] == '1'):
            wynik += 1
    return wynik

def bit_count_2_f(table):
    # liczenie bitów na określonych pozycjach
    wynik = 0
    indexy_do_sprawdzenia = [1, 2, 5, 6, 9, 10, 13, 14, 17, 18]
    for i in indexy_do_sprawdzenia:
        if i < len(table) and table[i] == '1':
            wynik += 1
    return wynik

def bit_count_4_f(table):
    # liczenie bitów na określonych pozycjach
    wynik = 0
    indexy_do_sprawdzenia = [3, 4, 5, 6, 11, 12, 13, 14, 19, 20]
    for i in indexy_do_sprawdzenia:
        if i < len(table) and table[i] == '1':
            wynik += 1
    return wynik

def bit_count_8_f(table):
    # liczenie bitów na określonych pozycjach
    wynik = 0
    indexy_do_sprawdzenia = [7, 8, 9, 10, 11, 12, 13, 14]
    for i in indexy_do_sprawdzenia:
        if i < len(table) and table[i] == '1':
            wynik += 1
    return wynik

def bit_count_16_f(table):
    # liczenie bitów na określonych pozycjach
    wynik = 0
    indexy_do_sprawdzenia = [16, 17, 18, 19, 20]
    for i in indexy_do_sprawdzenia:
        if i < len(table) and table[i] == '1':
            wynik += 1
    return wynik

def kod_hemminga(text_bin):
    # podział tekstu binarnego na części 16-bitowe i 8-bitowe
    czesci_16 = len(text_bin)//16
    czesci_8 = (len(text_bin) % 16) // 8
    suma_czesci = czesci_16 + czesci_8
    suma_kontrolna = []

    if(czesci_16 == 0):
        suma_kontrolna.append(list(text_bin))
    else:
        for i in range(0, czesci_16):
            suma_kontrolna.append(list(text_bin[i*16:(i+1)*16]))

        if(czesci_8 == 1):
            print(f"debug append listy:{list(text_bin[(czesci_16*16):])}") #debug
            suma_kontrolna.append(list(text_bin[czesci_16*16:]))

    print(f"Debug sumy kontrolnej po złąćzeniu{suma_kontrolna}") #debug
    # dodanie pustych bitów, które będą nadpisane
    for i in range(0, suma_czesci):
        if(len(suma_kontrolna[i]) == 16):
            for j in range(0, 5):
                suma_kontrolna[i].insert((2**j)-1, " ")
        else:
            for j in range(0, 3):
                suma_kontrolna[i].insert((2**j)-1, " ")
    
    #print(suma_kontrolna) #debug
    # obliczanie bitów kontrolnych
    for i in range(0, suma_czesci):
        if(len(suma_kontrolna[i]) == 21):
            suma_kontrolna[i][0] = "0" if(bit_count_1_f(suma_kontrolna[i]) % 2 == 0) else "1"
            suma_kontrolna[i][1] = "0" if(bit_count_2_f(suma_kontrolna[i]) % 2 == 0) else "1"
            suma_kontrolna[i][3] = "0" if(bit_count_4_f(suma_kontrolna[i]) % 2 == 0) else "1"
            suma_kontrolna[i][7] = "0" if(bit_count_8_f(suma_kontrolna[i]) % 2 == 0) else "1"
            suma_kontrolna[i][15] = "0" if(bit_count_16_f(suma_kontrolna[i]) % 2 == 0) else "1"
        else:
            suma_kontrolna[i][0] = "0" if(bit_count_1_f(suma_kontrolna[i]) % 2 == 0) else "1"
            suma_kontrolna[i][1] = "0" if(bit_count_2_f(suma_kontrolna[i]) % 2 == 0) else "1"
            suma_kontrolna[i][3] = "0" if(bit_count_4_f(suma_kontrolna[i]) % 2 == 0) else "1"

    return suma_kontrolna

def sprawdzenie_sume_kontrolna():
    # sprawdzenie sumy kontrolnej
    text = input("Prosze wprowadzić wartość do sprawdznia:")
    text_table = []
    text_table_str = ""
    
    # Cut the input into chunks of 21 bits
    for i in range(0, len(text), 21):
        text_table.append(list(text[i:i+21]))

    print(f"debug 1:{text_table}") #debug
    print(f"debug 2:{len(text_table)}") #debug
    print(f"debug 3:{len(text_table[0])}") #debug
    print(f"debug 4:{len(text_table[1])}") #debug

    text_table_copy = copy.deepcopy(text_table)
    
    for i in range(0, len(text_table)):
        if(len(text_table[i]) == 21):
        #    test_table.append(text_table[i][0], text_table[i][1], text_table[i][3], text_table[i][7], text_table[i][15])
            text_table[i].pop(15)
            text_table[i].pop(7)
            text_table[i].pop(3)
            text_table[i].pop(1)
            text_table[i].pop(0)
        else:
        #    test_table.append(text_table[i][0], text_table[i][1], text_table[i][3])
            text_table[i].pop(3)
            text_table[i].pop(1)
            text_table[i].pop(0)

    print(f"debug:{len(text_table[0])}") #debug
    print(f"debug:{len(text_table[1])}") #debug

    for i in range(0, len(text_table)):
        text_table_str += ''.join(map(str, text_table[i]))

    print(f"debug:{text_table_str}") #debug

    test_table = kod_hemminga(text_table_str)

    suma_kontrolna_21bit = "['K', 'K', 'B', 'K', 'B', 'B', 'B', 'K', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'K', 'B', 'B', 'B', 'B', 'B']"
    suma_kontrolna_11bit = "['K', 'K', 'B', 'K', 'B', 'B', 'B', 'K', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'K']"

    if(test_table == text_table_copy):
        print("Suma kontrolna jest poprawna")
    else:
        print("Suma kontrolna jest niepoprawna")
        print(f"Oryginalna suma kontrolna: \t{text_table_copy}")
        print(f"Suma kontrolna po sprawdzeniu: \t{test_table}")
        print(f"BITY: \t\t\t\t[{suma_kontrolna_21bit if len(text_table_copy[0]) == 21 else suma_kontrolna_11bit}]")
    

def tworzenie_sumy_kontrolnej():
    text = input("Prosze wprowadzić text:")
    text_bin = ''

    # zmiana każdego znaku na wartość binarną 8-bitową
    for i in range(0, len(text)):
        text_bin = text_bin + dec_to_bin(ord(text[i]))
    #print(text_bin) #debug
    text_convert = kod_hemminga(text_bin)

    new_text_bin = ""

    # łączenie wszystkich części w jeden ciąg binarny
    for i in range(0,len(text_convert)):
        for j in text_convert[i]:
            new_text_bin += j

    print(new_text_bin) #print zakodoawnej wartości wzorem heminga


def __main__():
    while True:
        input_user = input("Wybierz opcje: 1 - Kodowanie, 2 - Sprawdzenie Poprawność Kodu, 0 - Wyjście\n")        
        match input_user:
            case "1":
                tworzenie_sumy_kontrolnej()
            case "2":
                sprawdzenie_sume_kontrolna()
            case "0":
                print("Do zobaczenia!")
                exit()
            case _:
                print("Niepoprawna opcja")

__main__()
