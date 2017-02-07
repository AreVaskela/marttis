# marttis
Tollanen pikku peli, jostain pitää GitHub ura aloittaa

Tuollainen simppeli peli, jota tietokone pelaa virheettömästi.

QtCreator 4.2.1 (Qt 5.8.0 64bit) projektin voi avata suoraan, Qt kannattaa laittaa myös PATHiin.

Standalonen saa kun Qt:n tekemässä releasessa laittaa: "windeployqt .\release\" käyttää exeä release kansiosta.

1. Players are arranged in a ring. Let the first player be 1, and the last N,
   clockwise. Player 1 starts the game.

The game with 8 players:

     (1)
 (8)     (2)
(7)       (3)
 (6)     (4)
     (5)


2. In each turn of the game, the player in turn calls out the number one greater
   than the previous player. Then the turn passes to the next player. The
   called out numbers start from 1 and are consequtive natural numbers.

4. The game starts clockwise: first player 1, then 2 etc.

5. If the called out number has more than 1 digits, and all of the digits are
   the same (such as 11, 33, or 444), the game direction changes AFTER such
   number is called out. Example: if player 2 called 10, player 3 called 11,
   player 2 will call 12.

6. Whenever the called out number satisfies at least one of the following conditions:
        a. divisible by 7
        b. contains 7 as one of its digits
        c. the sum of the digits is seven
   The player will call "Martti Suosalo" instead of the number. The number is
   still incremented. A number (such as 77) may both change the direction and be
   called "Martti Suosalo"

7. The game ends, when someone violates some rule. The loser has to down a drink!
