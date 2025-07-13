Ulmer Simon, Algorithmen und Datenstrukturen

# Aufgabe 3
## Code
``` c
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAXDIRS 30

typedef struct {
	char symbol;
	uint32_t count;
} dir;

int main() {

	char input[8];
	char dirSymbol;
	char lastSymbol = 0;
	dir dirs[MAXDIRS] = {0};
	uint32_t count = 0;
	while (1) {
		scanf(" %s", input);

		if (strcmp(input, "up") == 0) {
			dirSymbol = '^';
		} else if (strcmp(input, "down") == 0) {
			dirSymbol = 'v';
		} else if (strcmp(input, "left") == 0) {
			dirSymbol = '<';
		} else if (strcmp(input, "right") == 0) {
			dirSymbol = '>';
		} else {
			continue;
		}
		
		if (lastSymbol == dirSymbol){
		    dirs[count -1].count++;
		} else{
		    dirs[count].count++;
		    dirs[count].symbol = dirSymbol;
		    count++;
		}
		lastSymbol = dirSymbol;

		char temp = getchar();
		if (temp == '\n' || temp == '\0')
			break;
	}
	
	for (int i = 0; i < count; i++){
	    printf("%c", dirs[i]);
	    if (dirs[i].count != 1)
	        printf("%d", dirs[i].count);
	}
	printf("\n");

}
```

## Probleme im Code
``` c
    printf("%c", dirs[i]);
``` 
Hier wird das `.symbol` nicht angegeben, macht aber keinen unterschied, da sich
`dirs[i]` um einen pointer handelt, welcher auf das Symbol in der Struktur
zeigt.
``` c
typedef struct {
	char symbol; // Als erstes im struct, somit direkt mit dem pointer erreichbar
	uint32_t count;
} dir;
```
-> Also es wird nicht die ganze Struktur ausgegeben, sondern nur das Symbol.

Ausgabe weißt keine Fehler auf, auch mit testen verschiedenster Testcases.

## Getestete Testcases

Eingabe:
```
up up up up up
``` 
Ausgabe:
```
5^ -> Korrekt
``` 

Eingabe:
```
up up right down left
```
Ausgabe:
``` 
^2>v< -> Korrekt
``` 

---

# Aufgabe 5
## Code
``` c
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXLEN 1000
#define MAXWORDS 50

int main() {
	uint32_t count = 0;
	char input[MAXWORDS][MAXLEN];
	for (int i = 0; i < MAXWORDS; i++) {
		scanf(" %s", input[count++]);

		char temp = getchar();
		if (temp == ' ') {
			continue;
		} else {
			break;
		}
	}

	for (int i = count; i >= 0; i--) {
		printf("%s ", input[i]);
	}
}
```
## Probleme im Code
``` c
	for (int i = count; i >= 0; i--) {
		printf("%s ", input[i]);
	}
``` 
Hier wird vom `count` runtergezählt, sollte aber von `count - 1` runtergezählt
werden, da count immer eines höher ist, als die position im Array.
-> Fehlerbehebung wäre, `count -1` zu verwenden.

## Getestete Testcases
Eingabe:
```
word1 (mit und ohne trailing space)
```
Ausgabe:
```
word1 -> Korrekt
```
Eingabe:
```
word1 word2 word3 word4 word5 word6 word7 word8 word9 word10 word11 word12 word13 word14 word15 word16 word17 word18 word19 word20 word21 word22 word23 word24 word25 word26 word27 word28 word29 word30 word31 word32 word33 word34 word35 word36 word37 word38 word39 word40 word41 word42 word43 word44 word45 word46 word47 word48 word49 word50
```
Ausgabe:
```
��;�� word50 word49 word48 word47 word46 word45 word44 word43 word42 word41 word40 word39 word38 word37 word36 word35 word34 word33 word32 word31 word30 word29 word28 word27 word26 word25 word24 word23 word22 word21 word20 word19 word18 word17 word16 word15 word14 word13 word12 word11 word10 word9 word8 word7 word6 word5 word4 word3 word2 word1 
-> Falsch, da undefinierte Werte ausgegeben werden
```

## Schlussfolgerung
Die maximale Anzahl an Wörtern funktioniert nicht, da der count um 1 höher ist,
als die Position im Array.

Ich empfinde die Bewertung von 1/5 Punkte als Funktionalität unverhältnismäßig
streng, da der Code ansonsten korrekt funktioniert und nur ein kleiner Fehler
in der Zählweise vorliegt, der leicht behoben werden kann.

---

# Aufgabe 6
## Code
``` c
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(){
    uint32_t count;
    scanf("%d", &count);
    
    uint32_t jumpList[count];
    for (int i = 0; i < count; i++){
        scanf("%d", &jumpList[i]);
    }
    
    uint32_t pos = 0;
    for (int i = 0; i < count; i++){
        uint32_t nextPos = jumpList[pos];
        if (jumpList[nextPos] == 0){
            printf("true\n");
            return 0;
        }else{
            pos = nextPos;
        }
    }
    
   printf("false\n");
   return -1;
}
```

## Probleme im Code
Keine. Die Benennung der Variablen könnte verbessert werden, aber der Code
macht genau das, was er soll. Die Aufgabenstellung besagt, dass geprüft werden
soll, ob zu Position 0 zurückgesprungen wird, und nicht, ob es irgendwo in
einer Endllosschleife endet.

## Programmablauf
1. Lese die Anzahl der Sprünge ein.
2. Lese die Sprungliste ein.
3. Starte bei der Position 0.
4. Schleife:
    a. Lese den evaluierten Sprung aus der Liste. (gesprungen)
    b. Prüfe, ob mit dem nächsten Sprung die Position 0 erreicht wird.
        i. Wenn ja, gebe "true" aus und beende das Programm.
        ii. Wenn nein, setze die aktuelle Position auf die nächste Position.
    c. Wiederhole die Schleife, bis alle Sprünge durchlaufen sind.

## Getestete Testcases
Eingabe:
```
1
0
```
Ausgabe:
```
true -> Korrekt, springt immer auf 0
```

Eingabe:
```
5
3
4
2
1
0
```
Ausgabe:
```
true -> Korrekt, springt wieder auf Position 0
```

Eingabe:
```
3
1
2
1
```
Ausgabe:
```
false -> Korrekt, springt immer zwischen Position 1 und 2
```

Eingabe:
```
4
1
2
1
0
```
Ausgabe:
```
false -> Korrekt, Position 3 wird nie erreicht
```

