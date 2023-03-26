# Klient

## Popis funkčnosti:

    - Úkolem klienta je připojit ne server na port, daný vstupním parametrem, na localhost (127.0.0.1) a 
    poslat mu zprávu, kterou dostane jako druhý parametr. Následně bude od serveru očekávat odpověď ve 
    formě převrácené zprávy. Poté se ze serveru odpojí.

## Implementace:
    
    - Klient je implementován jako jednovláknová aplikace v jazyce C++. Pro spojení se serverem je využito rozhraní 
    BSD socketů. Pro sestavení je použit nástroj make.

    - Aplikace se skládá z jedné třídy, představující klienta. Ve vstupní funkci main se předají vstupní parametry 
    programu nově vytvořenému objektu Client. Následně se nad ním zavolá metoda pro samotný běh, kde se nastaví 
    potřebné parametry pro spojení, které se následně naváže. Klient se připojí na server. Samotná obsluha klineta 
    probíhá v nově vzniklém vlákně. Klient se připojí na server a pošle mu zprávu, před kterou přidá do jednoho znaku 
    délku zprávy. Následně od serveru očekává odpověď ve stejném formátu, jen převrácený obsah zprávy. Nakonec prvede 
    validaci odpovědi. Během konverzace se serverem klient reaguje na výpadky na straně serveru.

## Vstupní parametry:

    - Port: číslo od 1 do 65535
    - Zpráva: nepřerušený řetězec o délce maximálně 255 znaků

    