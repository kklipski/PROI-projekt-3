# PROI: projekt 3

### Treść zadania
Napisać prostą grę na dwóch graczy umożliwiającą toczenie walk w trybie turowym. Każdy z graczy posiada pewną ilość jednostek (łucznicy, wojownicy, rycerze, magowie, jeźdźcy). Każda z jednostek ma swoją specyfikę:
- łucznicy strzelają na pewien dystans
- wojownicy potrafią zadać duże obrażenia, jednak muszą podejść bardzo blisko
- magowie, dzięki atakom obszarowym, sieją spustoszenie na polu bitwy, jednak nie potrafią atakować, gdy jednostka wroga jest obok nich
- jeźdźcy potrafią się bardzo szybko poruszać po polu bitwy (zadane obrażenia są tym większe, im większy dystans zostanie pokonany)

Gracze posiadają X oddziałów podczas bitwy. Każdy oddział składa się z Y jednostek. Każda jednostka ma punkty życia, zasięg i rodzaj ataku, szybkość poruszania się, które są odpowiednio dostosowane do opisu specyfiki jednostek.

Pole bitwy reprezentowane jest poprzez kwadrat o wymiarach NxN. Początkowo stan pola bitwy powinien być wczytywany z pliku. Powinna być również możliwość zapisania stanu gry w dowolnym momencie. Błędy podczas wczytywania oraz zapisywania powinny być wykryte i obsłużone (patrz std:exception).

W projekcie zastosować dziedziczenie do opisu zachowania jednostek, tzn. klasa jednostki zawiera opis cech i zachowań specyficznych dla każdej z nich. Klasa łucznika definiuje atak jako strzał itd.

Do wykonania interfejsu użytkownika można wykorzystać bibliotekę Qt bądź SFML.

Do programu należy dostarczyć również [dokumentację]("Diagram klas + założenia.docx") zawierającą krótki opis techniczny programu (diagram klas, założenia itd.) oraz krótką [dokumentację dla użytkownika]("Opis programu.docx") z opisem programu.

### Źródła
1. [Let's make 16 games in C++: Asteroids] (https://www.youtube.com/watch?v=rWaSo2usU4A)

*Migrated from Bitbucket.*
