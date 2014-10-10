NUME:	Culincu Diana Cristina
IDE:	Visual Studio C++
SO:		Windows 7


-----------------------------------------------------------------------------------------
MOD DE UTILIZARE
Tastatura:	-a- move left
		-s- move down
		-d- move right
		-w- move up
		-q- move diagonala stanga sus
		-e- move diagonala dreapa sus
		-z- move diagonala stanga jos
		-x- move diagonala dreapta jos
		-SPACEBAR- activare/dezactivare arma
		-mouse left button- rotire arma stanga
		-mouse right button-rotire arma dreapta

-----------------------------------------------------------------------------------------
INAMICI
		-the asteroid- static 
			     - la lovire scor -100 si vieti-1
		-the star    - twinkles (isi mareste si micsoreaza dimensiunea)
			     - la lovire scor -50 si vieti-1
		-the UFO     - se misca random prin cadrul de joc
			     - daca te prinde e game over

-----------------------------------------------------------------------------------------
SCOR SI VIETI
	Jocul implementeaza strategia de deathmatch, adica scorul creste in functie
de cat timp supravietuiesti.
	La lovirea unui inamic pierzi o viata (exceptie face nava spatiala care te face
sa-ti pierzi toate vietile) si puncte.  La inceputul jocului ai 3 vieti.
	La lovirea cu arma a unui inamic (exceptie ufo) castigi puncte.
	Scorul si vietile apar intr-un cadru separat deasupra cadrului de joc.
	Nivelul apare dedesuptul cadrului de joc.

-----------------------------------------------------------------------------------------
FISIERE si MODIFICARI ADUSE FISIERELOR DE LA LABORATOR 
	Adaugari:	-Asteroid.h- pentru crearea de inamici asteroizi
			-Spaceship.h- pentru crearea de inamici nave spatiale
			-Star.h- pentru crearea de inamici stele
			-Hero.h- pentru crearea caracterului playable
			-Gun.h- pentru arma
	Modificari:	-in Object2D.h am adaugat un punct Point2D care retine mereu 
			coordonatele de centru ale oricarui obiect (folosit la coliziuni)
			-in Object2D.h am adaugat o variabila de tipul double care 
			retine lungimea/raza obiectului (folosit la coliziuni)

-----------------------------------------------------------------------------------------
IMPLEMENTARE
	Jocul se desfasoara intr-un ambient muzical :)
	Jocul are mai multe nivele.
	Miscarea cu arma activata se face de 2x mai incet.
	Inamicii stele si asteroizi sunt retinuti fiecare intr-un vector <tip_inamic> pentru o
mai buna gestionare a acestora (mai usor de parcurs un vector de obiecte decat sa scrii cod pentru
fiecare obiect in parte).
	Stelele se maresc si micsoreaza si isi schimba culoarea. Pentru acest lucru am folosit un
contor care creste odata cu numarul de frame-uri (si se reseteaza la 1000). Modificarile se fac in
functie de valoarea contorului la momentul respectiv (300, 500, 1000, etc.). 
	Ozn-ul se misca random. In fiecare frame avem o variabila r random%4 in functie de care se
alege automat directia de translatie.
	Coliziunile au fost rezolvate prin arie si anume: avand punctul de centru al obictelor
si lungimea acestora, am verificat daca cele doua arii au puncte comune (daca distanta dintre 
coordonatele lor de centru este mai mica decat suma lungimilor lor). In cazul stelelor lungimea
se mareste si micsoreaza in functie de scalarea stelei la momentul respectiv. Pentru ozn coliziunile
sunt putin diferite, astfel incat se verifica ca mai sus numai in partea superioara (cadranul 
trigonometric I si II), pentru partea inferioara fiind de ajuns numai ca distanta dintre punctele de
centru e mai mica decat lungimea eroului. 
	Coliziunea cu cadrul de joc se face intr-un mod similar.
	Cand lovesti un obiect pierzi scor si viata si obiectul respectiv explodeaza. La coliziune 
obiectul cu care se loveste e scos din vectorul la care e afiliat si dispare.
	Cand nu mai ai vieti se afiseaza "Game over", ecranul ingheata si dupa jocul re-incepe de la
primul nivel.
	Cand nivelul e castigat se afiseaza "Won", ecranul ingheata si dupa se trece la nivelul urmator.
	Nivelele sunt structurate in functie de viteza ozn-ului. Cu cat creste nivelul cu atat creste
si viteza ufo.
	Scorul se pastreaza pe parcursul nivelelor.
	Pentru mai multe detalii a se consulta comentariile din cod.

-----------------------------------------------------------------------------------------
BONSURI
	-muzica
	-nivele
	-aspectul jocului

-----------------------------------------------------------------------------------------
DIFICULTATI
	Functia PlaySound nu poate sa redea mai multe sunete in acelasi timp.
	Am incercat sa fac ozn-ul mult mai complicat dpdv grafic (ca o nava spatiala), dar in momentul
 in care trebuia sa se miste partea de jos nu translata cum trebuie (nu am reusit sa-mi dau seama de ce).
	Am incercat sa fac arma sa se roteasca pe key left si key right dar nu am putut deoarece acestea
erau codate pe taste pe care le folosisem deja. (de exemplu 'd' si key left).	