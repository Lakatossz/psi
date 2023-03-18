# 1. úloha semestarání práce

## Název: TCP klient/server

## Popis
    - Implementujte vícevláknový TCP server, který bude poslouchat na portu zadaném z
    příkazové řádky. Jeho úkolem je od klienta přijmout řetězec o maximální délce 255
    znaků a poslat jej zpět klientovi obrácený (např. ABCD → DCBA). Délka řetězce se v
    obou případech nachází v prvním bytu zprávy.