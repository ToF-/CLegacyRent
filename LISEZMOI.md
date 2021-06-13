Notre programme reçoit des offres de trading et calcule le revenu maximum qui peut être réalisé avec ces ordres.

Nous ne savons pas comment il fonctionne, mais nous pouvons vous dire qu'il fonctionne bien.

Voici un exemple:

Si vous entrez ces données dans l'application,
```
1
4
TOPSTABS 0 5 100
DOESCLAN 3 7 140
MAZYCART 6 9 70
CODECOAT 7 9 80
```

Alors le résultat sera:
```
180
```
Parce que:
- TOPSTABS et DOESCLAN ne sont pas compatibles (TOPSTABS se termine au temps 5, donc DOESCLAN ne peut pas être retenu au temps 3).
- DOESCLAN constitue une meilleure offre que TOPSTABS, à 140 au lieu de 100.
- mais DOESCLAN se terminant à 3+7=10 ne permet pas à MAZYCART ou CODECOAT de démarrer, donc le revenu total serait seulement 140.
- MAZYCART peut démarrer juste au moment où TOPSTABS se termine, donc le chiffre d'affaire total pourrait être de 100+70: 170.
- CODECOAT peut démarrer après que TOPSTABS se termine, et dépasse MAZYCART avec 80, donc le chiffre d'affaire peut être: 180.

Par conséquent le chiffre d'affaire total est: 180.

Bien sûr, dans la vraie vie, nous utilisons notre programme sur des données bien plus volumineuses. Ci-joint un fichier en provenance de la production (`largedata.dat`).

Nous aimerions que vous changiez le code de 3 manières différentes:

- Améliorez la maintenabilité du code. Un consultant a audité le code et l'a déclaré "inmaintenable", en particulier, "il n'y a pas de tests unitaires", et c'est la raison pour laquelle à chaque fois que nous avons essayé de faire évoluer ce programme, des incidents en production s'ensuivaient.

- Optimisez le programme. A l'heure actuelle il est un peu trop lent à traiter nos gros volumes de données. Nous aimerions qu'il traite un ensemble de données volumineux en disons, moins d'une demi-seconde.

- Faites en sorte que le programme affiche les ordres qui sont sélectionnés, au lieu d'affichier seulement le chiffre d'affaire total. Par exemple, en traitant le fichier de l'exemple ci-dessus, le programme afficherait l'identifiant de l'ordre, le montant de l'ordre, et le chiffre d'affaire obtenu jusqu'ici. 

```
TOPSTABS 100 100
CODECOAT  80 180
```
