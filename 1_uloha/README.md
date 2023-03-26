# 1. úloha semestarání práce

## Název: TCP klient/server

## Popis
- Implementujte vícevláknový TCP server, který bude poslouchat na portu zadaném z
příkazové řádky. Jeho úkolem je od klienta přijmout řetězec o maximální délce 255
znaků a poslat jej zpět klientovi obrácený (např. ABCD → DCBA). Délka řetězce se v
obou případech nachází v prvním bytu zprávy.

## Server

### Popis funkčnosti:

- Úkolem serveru je přijímat klienty na portu, daném vstupním parametrem, na localhostu (127.0.0.1) a 
přečíst od nich zprávu, kterou obrátí a následně ji pošle zpět. Poté klienta odpojí. Dále je zapotřebí, aby 
byly klienti zpracováni v jednotlivých vláknech.

### Implementace:

- Server je implementován jako vícevlákonová aplikace v jazyce C++. Pro spojení s klientem je využito rozhraní 
BSD socketů. Pro sestavení je použit nástroj make.

- Aplikace se skládá z jedné třídy, představující server. Ve vstupní funkci main se předají vstupní parametr 
programu nově vytvořenému objektu Server. Následně se nad ním zavolá metoda pro samotný běh, kde se nastaví 
parametry pro spojení, které se následně naváže. Klient pošle zprávu, před kterou přidá do jednoho znaku délku 
zprávy. Následně serveru zpracuje přijatou zprávu a připraví ji na odeslání zpět. Podle prvního znaku zprávy pozná, 
jak dlouhá zpráva je. Následně zbytek zprávy obrátí. Tuto zprávu server pošle zpět. Tímto konverzace s klientem 
končí a server ukončí spojení. Server si udržuje pole vláken. Průběžně zavírá ukončená vlákna. Takto je možné
připojit najednou několik set klientů.

### Vstupní parametry:

- Port: číslo od 1 do 65535

## Klient

### Popis funkčnosti:

- Úkolem klienta je připojit ne server na port, daný vstupním parametrem, na localhost (127.0.0.1) a 
poslat mu zprávu, kterou dostane jako druhý parametr. Následně bude od serveru očekávat odpověď ve 
formě převrácené zprávy. Poté se ze serveru odpojí.

### Implementace:

- Klient je implementován jako jednovláknová aplikace v jazyce C++. Pro spojení se serverem je využito rozhraní 
BSD socketů. Pro sestavení je použit nástroj make.

- Aplikace se skládá z jedné třídy, představující klienta. Ve vstupní funkci main se předají vstupní parametry 
programu nově vytvořenému objektu Client. Následně se nad ním zavolá metoda pro samotný běh, kde se nastaví 
potřebné parametry pro spojení, které se následně naváže. Klient se připojí na server. Samotná obsluha klineta 
probíhá v nově vzniklém vlákně. Klient se připojí na server a pošle mu zprávu, před kterou přidá do jednoho znaku 
délku zprávy. Následně od serveru očekává odpověď ve stejném formátu, jen převrácený obsah zprávy. Nakonec prvede 
validaci odpovědi. Během konverzace se serverem klient reaguje na výpadky na straně serveru.

### Vstupní parametry:

- Port: číslo od 1 do 65535
- Zpráva: nepřerušený řetězec o délce maximálně 255 znaků

