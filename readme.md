# Příklad 2
## Vlastní datový typ struktury

Vycházejte z předchozího programu a proveďte následující úpravy:

* Strukturu Person rozšiřte o ukazatel na další strukturu person (další osobu v seznamu).
* Zadefinujte tyto funkce:
  * funkce pro alokování paměti, která vrací ukazatel na alokovanou strukturu
  * funkce pro načtení jednotlivých položek struktury 
  * funkce pro vyhledání nejstarší osoby 
  * funkce pro vyhledání nejmladší osoby 
  * funkce pro dealokování paměti všech záznamů

Hlavní funkci main upravte tak, aby použila nadefinované funkce. Místo pole osob bude použit spojový seznam osob.