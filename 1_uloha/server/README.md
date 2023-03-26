# Server

## Popis funkčnosti:

    - Úkolem serveru je přijímat klienty na portu, daném vstupním parametrem, na localhostu (127.0.0.1) a 
    přečíst od nich zprávu, kterou obrátí a následně ji pošle zpět. Poté klienta odpojí. Dále je zapotřebí, aby 
    byly klienti zpracováni v jednotlivých vláknech.

## Implementace:

    - Server je implementován jako vícevlákonová aplikace v jazyce C++. Pro spojení s klientem je využito rozhraní 
    BSD socketů. Pro sestavení je použit nástroj make.

    - Aplikace se skládá z jedné třídy, představující server. Ve vstupní funkci main se předají vstupní parametr 
    programu nově vytvořenému objektu Server. Následně se nad ním zavolá metoda pro samotný běh, kde se nastaví 
    parametry pro spojení, které se následně naváže. Klient pošle zprávu, před kterou přidá do jednoho znaku délku 
    zprávy. Následně serveru zpracuje přijatou zprávu a připraví ji na odeslání zpět. Podle prvního znaku zprávy pozná, 
    jak dlouhá zpráva je. Následně zbytek zprávy obrátí. Tuto zprávu server pošle zpět. Tímto konverzace s klientem 
    končí a server ukončí spojení. Server si udržuje pole vláken. Průběžně zavírá ukončená vlákna. Takto je možné
    připojit najednou několik set klientů.

## Vstupní parametry:

    - Port: číslo od 1 do 65535
    