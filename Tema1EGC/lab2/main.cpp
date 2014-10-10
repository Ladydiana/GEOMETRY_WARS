#include "Framework/DrawingWindow.h"
#include "Framework/Visual2D.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include "Framework/Star.h"
#include "Framework/Asteroid.h"
#include "Framework/Spaceship.h"
#include "Framework/Hero.h"
#include "Framework/Gun.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <windows.h>
#include <Windows.h>
#include <mmsystem.h>
#include <math.h>


// This is C++. const is better than define
const double PI = 3.14159265358979323846;

using namespace std;

Visual2D *v2d1;
Rectangle2D *cadru, *scRect;
Text *scoreh, *livesh, *score, *lives, *game_over, *win, *lvl, *lvlh;
Gun *gun;
Hero *circle;
Star *star1, *star2, *star3, *star4, *star5, *star6;
Asteroid *ast1, *ast2, *ast3, *ast4, *ast5;
Spaceship *ufo1;

vector <Star*> stelute;
vector <Asteroid*> asteroizi;

int scor=0, vieti, contor, r, i, nivel=1;
double pasx, pasy, speed, pas_ufox, pas_ufoy, speed_ufo=2, velocity, gx,gy;
bool changed, is_hit, over, is_on, new_game, is_won;


//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{
	
	v2d1 = new Visual2D(0,0,DrawingWindow::width,DrawingWindow::height,0,0,DrawingWindow::width,DrawingWindow::height);  
	addVisual2D(v2d1);
	
	// Adaugare cadre pt teren, status (scor, vieti, etc) si obiecte
	vieti = 3;
	velocity=1;
	changed = false;
	is_hit =  false;
	is_on = false;
	over = false;
	new_game = false;
	is_won=false;
	contor = 0;
	speed=5/velocity;
	pasx=0;
	pasy=0;
	pas_ufox=0;
	pas_ufoy=0;
	//speed_ufo=3;
	srand(time(NULL));
	
	// Adding objects
	cadru = new Rectangle2D(Point2D(100,100),300,300,Color(1,1,1), false);
	addObject2D(cadru);
	scRect = new Rectangle2D(Point2D(100,400),300,20,Color(1,1,1), false);
	addObject2D(scRect);
	circle=new Hero(Point2D(250,250), 10, Color(1,0,0));
	addObject2D(circle);
	ufo1 = new Spaceship(Point2D(369,300), 15, Color(1,1,1), false);
	addObject2D(ufo1);
	star1 = new Star(Point2D(150,200), 40, Color(1,1,0), false); 
	addObject2D(star1);
	stelute.push_back(star1);
	star2 = new Star(Point2D(330,150), 25, Color(0.8,0.8,0), false); 
	addObject2D(star2);
	stelute.push_back(star2);
	star3 = new Star(Point2D(372,372), 15, Color(1,1,0), false); 
	addObject2D(star3);
	stelute.push_back(star3);
	star4 = new Star(Point2D(172, 350), 10, Color(1,1,0), false); 
	addObject2D(star4);
	stelute.push_back(star4);
	star5 = new Star(Point2D(343, 310), 20, Color(1,1,1), false); 
	addObject2D(star5);
	stelute.push_back(star5);
	ast1 = new Asteroid(Point2D(120,120), 30, Color(0.65,0.65,0.65), true);
	addObject2D(ast1);
	asteroizi.push_back(ast1);
	ast2 = new Asteroid(Point2D(365,220), 20, Color(0.65,0.65,0.65), true);
	addObject2D(ast2);
	asteroizi.push_back(ast2);
	ast3 = new Asteroid(Point2D(126,300), 25, Color(0.65,0.65,0.65), true);
	addObject2D(ast3);
	asteroizi.push_back(ast3);
	ast4 = new Asteroid(Point2D(238,180), 50, Color(0.65,0.65,0.65), true);
	addObject2D(ast4);
	asteroizi.push_back(ast4);
	ast5 = new Asteroid(Point2D(267,340), 40, Color(0.65,0.65,0.65), true);
	addObject2D(ast5);
	asteroizi.push_back(ast5);
	scoreh= new Text("Score:  ", Point2D(110,405), Color(1,1,1),BITMAP_HELVETICA_12);
	addText(scoreh);
	livesh= new Text("Lives:  ", Point2D(340,405), Color(1,1,1),BITMAP_HELVETICA_12);
	addText(livesh);
	score= new Text(to_string(scor), Point2D(150,405), Color(1,1,1),BITMAP_HELVETICA_12);
	addText(score);
	lives= new Text(to_string(vieti), Point2D(375,405), Color(1,1,1),BITMAP_HELVETICA_12);
	addText(lives);
	lvlh= new Text("Nivel ", Point2D(230,85), Color(1,1,1),BITMAP_HELVETICA_12);
	addText(lvlh); 
	lvl= new Text(to_string(nivel), Point2D(260,85), Color(1,1,1),BITMAP_HELVETICA_12);
	addText(lvl);
	game_over= new Text("GAME_OVER", Point2D(180,425), Color(1,1,1),BITMAP_TIMES_ROMAN_24);
	win= new Text("WON", Point2D(230,425), Color(1,1,1),BITMAP_TIMES_ROMAN_24);
	gun= new Gun(Point2D(250, 250),10,Color(1,0,0), true);
	addObject2D(gun);
}


//functia care permite animatia
void DrawingWindow::onIdle()
{
	// Daca jocul e castigat trecem la niv urmator si marim viteza ufo
	// Scorul se pastreaza
	if(is_won){
		speed_ufo+=0.3;
		++nivel;
	}

	if(over){
		nivel=1;
		speed_ufo=2;
	}

	if(new_game)
		init();

	// daca e necesar un nou nivel sau reinceperea jocului
	if(over||is_won){
		Sleep(1000);
		for(i=stelute.size()-1; i>=0; i--){
			DrawingWindow::removeObject2D(stelute[i]);
			stelute.pop_back();
		}
		for(i=asteroizi.size()-1; i>=0; i--){
			DrawingWindow::removeObject2D(asteroizi[i]);
			asteroizi.pop_back();
		}
		DrawingWindow::removeObject2D(gun);
		DrawingWindow::removeObject2D(circle);
		DrawingWindow::removeObject2D(ufo1);
		DrawingWindow::removeObject2D(scRect);
		DrawingWindow::removeObject2D(cadru);
		removeText(game_over);
		removeText(win);
		removeText(lives);
		removeText(livesh);
		removeText(score);
		removeText(scoreh);
		removeText(lvl);
		removeText(lvlh);
		new_game = true;
		over=false;
		is_won=false;
		DrawingWindow::removeVisual2D(v2d1);
	}

	//daca arma e activata
	if(is_on==true){
		gun->color= Color(1,0,0);
		velocity=2;
		// gx si gy sunt coord aproximative ale centrului armei
		// folosite la coliziuni
		gx= ((gun->points.at(0)->x+gun->points.at(2)->x)/2 + gun->points.at(1)->x)/2;
		gy= ((gun->points.at(0)->y+gun->points.at(2)->y)/2 + gun->points.at(1)->y)/2;
	}

	else{
		gun->color= Color(0,0,0);
		velocity=1;
	}

	// daca se schimba ceva legat de scor sau vieti afisam
	if(changed==true || is_hit==true){
		removeText(score);
		removeText(lives);
		if(scor<0)
			scor=0;		//evitam scoruri negative
		score= new Text(to_string(scor), Point2D(150,405), Color(1,1,1),BITMAP_HELVETICA_12);
		addText(score);
		lives= new Text(to_string(vieti), Point2D(375,405), Color(1,1,1),BITMAP_HELVETICA_12);
		addText (lives);
		changed = false;
		is_hit = false;

		// daca nu mai avem vieti setam over pe true si asteptam urmatoarul frame 
		// ca sa se modifice fereastra si datele
		if(vieti==0){
			addText(game_over);
			over = true;
		}

		// daca nu mai avem obiecte setam over pe true si asteptam urmatoarul frame 
		// ca sa se modifice fereastra si datele
		if(stelute.size()==0 && asteroizi.size()==0 && vieti!=0){
			addText(win);
			is_won = true;
		}
	}

	
	// Twinkle twinkle little star folosind un contor ce creste la fiecare frame afisat 
	// + deathmatch - scorul creste automat in functie de timpul in care jucatorul e alive
	++contor;
	if(contor%100==0) {
		++scor;
		changed=true;
	}
	if(contor%1000==0){
		for(i=stelute.size()-1; i>=0; --i){
			if(i%2==0)
				stelute[i]->color=  Color(0.184, 0.184, 0.309);
			else
				stelute[i]->color= Color(0.196, 0.6, 0.8);
			stelute[stelute.size()-1]->color = Color (0.8, 0.8, 0);
		}

		contor=1;
		changed= true;
		for(i=stelute.size()-1; i>=0; --i){
			Transform2D::loadIdentityMatrix();
			Transform2D::translateMatrix(-stelute[i]->centru->x, -stelute[i]->centru->y);
			Transform2D::scaleMatrix(1/1.8,1/1.8);
			Transform2D::translateMatrix(stelute[i]->centru->x, stelute[i]->centru->y);
			Transform2D::applyTransform(stelute[i]);
			Transform2D::loadIdentityMatrix();
			stelute[i]->lungime/=1.7;
		}

	}
	else if(contor%600==0){
		for(i=stelute.size()-1; i>=0; --i){
			if(i%2==0)
				stelute[i]->color= Color(0.196, 0.6, 0.8);  
			else
				stelute[i]->color= Color(0.184, 0.184, 0.309);
			stelute[0]->color= Color(1,1,1); 
		}
	}
	else if(contor%500==0){
		for(i=stelute.size()-1; i>=0; --i){
			if(i%2==0)
				stelute[i]->color= Color(0.56, 0.56, 0.73);  
			else
				stelute[i]->color= Color(0.8, 0.7, 0.3);
		}
		for(i=stelute.size()-1; i>=0; --i){
			Transform2D::loadIdentityMatrix();
			Transform2D::translateMatrix(-stelute[i]->centru->x, -stelute[i]->centru->y);
			Transform2D::scaleMatrix(1.8,1.8);
			Transform2D::translateMatrix(stelute[i]->centru->x, stelute[i]->centru->y);
			Transform2D::applyTransform(stelute[i]);
			Transform2D::loadIdentityMatrix();
			stelute[i]->lungime*=1.7;
		}
	}
	else if(contor%300==0){
		for(i=stelute.size()-1; i>=0; --i){
			if(i%2==0)
				stelute[i]->color= Color(0.419, 0.137, 0.556);  
			else
				stelute[i]->color= Color(0.372, 0.623, 0.623);
		}
	}
	

	// UFO moving randomly
	r= rand()%4;
		if( (r==0) && (ufo1->centru->x - ufo1->lungime > 100) ){
			pas_ufox = pas_ufox - speed_ufo;
			ufo1->centru->x = (float)(ufo1->centru->x - speed_ufo);
			Transform2D::loadIdentityMatrix();
			Transform2D::translateMatrix(pas_ufox,pas_ufoy);
			Transform2D::applyTransform(ufo1);
		}
		else if( (r==1) && (ufo1->centru->x + ufo1->lungime < 400) ){
			pas_ufox = pas_ufox + speed_ufo;
			ufo1->centru->x = ufo1->centru->x + speed_ufo;
			Transform2D::loadIdentityMatrix();
			Transform2D::translateMatrix(pas_ufox,pas_ufoy);
			Transform2D::applyTransform(ufo1);
		}
		else if( (r==2) && (ufo1->centru->y - ufo1->lungime > 100) ){
			pas_ufoy = pas_ufoy - speed_ufo;
			ufo1->centru->y = ufo1->centru->y - speed_ufo;
			Transform2D::loadIdentityMatrix();
			Transform2D::translateMatrix(pas_ufox,pas_ufoy);
			Transform2D::applyTransform(ufo1);
		}
		else if( (r==3) && (ufo1->centru->y + ufo1->lungime < 400) ){
			pas_ufoy = pas_ufoy + speed_ufo;
			ufo1->centru->y = ufo1->centru->y + speed_ufo;
			Transform2D::loadIdentityMatrix();
			Transform2D::translateMatrix(pas_ufox,pas_ufoy);
			Transform2D::applyTransform(ufo1);
		}

	// Coliziuni
	for(i=asteroizi.size()-1; i>=0; --i){
		if( ((abs(asteroizi[i]->centru->x - circle->centru->x)) < asteroizi[i]->lungime + circle->lungime) &&
			(abs(asteroizi[i]->centru->y - circle->centru->y) < asteroizi[i]->lungime + circle->lungime)
			){
			vieti--;
			asteroizi[i]->color= Color(0,0,0);
			asteroizi[i]->fill=false;
			DrawingWindow::removeObject2D(asteroizi[i]);
			asteroizi.erase(asteroizi.begin()+i);
			scor-=1000;
			is_hit = true;
			changed = true;
			break;
		}
	}
	for(i=stelute.size()-1; i>=0; --i){
		if( ((abs(stelute[i]->centru->x - circle->centru->x)) < stelute[i]->lungime/2 + circle->lungime) &&
			(abs(stelute[i]->centru->y - circle->centru->y) < stelute[i]->lungime/2 + circle->lungime)
			){
			vieti--;
			stelute[i]->color= Color(0,0,0);
			DrawingWindow::removeObject2D(stelute[i]);
			stelute.erase(stelute.begin()+i);
			scor-=500;
			is_hit = true;
			changed = true;
			break;
		}
	}

	// Coliziuni cu arma
	if(is_on==true){
		for(i=asteroizi.size()-1; i>=0; --i){
			if( ((abs(asteroizi[i]->centru->x - gx)) < asteroizi[i]->lungime + circle->lungime/3) &&
				(abs(asteroizi[i]->centru->y - gy) < asteroizi[i]->lungime + circle->lungime/3)
				){
				scor+=500;
				asteroizi[i]->color= Color(0,0,0);
				asteroizi[i]->fill=false;
				DrawingWindow::removeObject2D(asteroizi[i]);
				asteroizi.erase(asteroizi.begin()+i);
				changed = true;
				break;
			}
		}
		for(i=stelute.size()-1; i>=0; --i){
			if( ((abs(stelute[i]->centru->x - gx)) < stelute[i]->lungime/2 + circle->lungime/3) &&
				(abs(stelute[i]->centru->y - gy) < stelute[i]->lungime/2 + circle->lungime/3)
				){
				stelute[i]->color= Color(0,0,0);
				DrawingWindow::removeObject2D(stelute[i]);
				stelute.erase(stelute.begin()+i);
				scor+=1000;
				changed = true;
				break;
			}
		}
	}


	// Coliziunea cu UFO
	// if u get hit by a UFO u die
	if( (circle->centru->x-ufo1->centru->x < circle->lungime+ ufo1->lungime) &&
		(circle->centru->y-ufo1->centru->y < circle->lungime+ ufo1->lungime) &&
		(circle->centru->x-ufo1->centru->x >= 0) &&
		(circle->centru->y-ufo1->centru->y >= 0)
		){
		vieti=0;
		is_hit= true;
	}
	else if( (ufo1->centru->x-circle->centru->x < circle->lungime+ ufo1->lungime) &&
		(circle->centru->y-ufo1->centru->y < circle->lungime+ ufo1->lungime) &&
		(ufo1->centru->x-circle->centru->x >= 0) &&
		(circle->centru->y-ufo1->centru->y >= 0)
		){
		vieti=0;
		is_hit= true;
	}
	else if( (ufo1->centru->x-circle->centru->x < circle->lungime) &&
		(ufo1->centru->y-circle->centru->y < circle->lungime) &&
		(ufo1->centru->x-circle->centru->x >= 0) &&
		(ufo1->centru->y-circle->centru->y >= 0)
		){
		vieti=0;
		is_hit= true;
	}
	else if( (circle->centru->x-ufo1->centru->x < circle->lungime) &&
		(ufo1->centru->y-circle->centru->y < circle->lungime) &&
		(circle->centru->x-ufo1->centru->x >= 0) &&
		(ufo1->centru->y-circle->centru->y >= 0)
		){
		vieti=0;
		is_hit= true;
	}

}

//functia care se apeleaza la redimensionarea ferestrei
void DrawingWindow::onReshape(int width,int height)
{
	v2d1->poarta(0,0,width,height); 
}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	speed=5/velocity;
	switch(key)
	{
		case 27 :			//ESC to quit
			exit(0);
			break;
		case 32:			//spacebar ca sa activam arma
			if(is_on==true)
				is_on = false;
			else
				is_on = true;
			break;
		
		case 'a': 
			if(circle->centru->x - circle->lungime > 100){
				pasx = pasx - speed;
				circle->centru->x=circle->centru->x-speed;
				gun->centru->x= gun->centru->x-speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(-speed,0);
				Transform2D::applyTransform(gun);
				
			}
			break; 
		case 's':
			if(circle->centru->y - circle->lungime > 100){
				pasy = pasy - speed;
				circle->centru->y=circle->centru->y -speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(0,-speed);
				Transform2D::applyTransform(gun);
			}
			break;
		case 'd':
			if(circle->centru->x + circle->lungime < 400)
				{
				pasx = pasx + speed;
				circle->centru->x=circle->centru->x+speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(speed,0);
				Transform2D::applyTransform(gun);
			}
			break;
		case 'w':
			if(circle->centru->y + circle->lungime < 400){
				pasy = pasy + speed;
				circle->centru->y=circle->centru->y +speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(0,speed);
				Transform2D::applyTransform(gun);
			}
			break;
		case 'e':
			if( (circle->centru->x + circle->lungime < 400) && 
				(circle->centru->y + circle->lungime < 400) 
				){
				pasx = pasx + speed;
				pasy = pasy + speed;
				circle->centru->x=circle->centru->x + speed;
				circle->centru->y=circle->centru->y + speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(speed,speed);
				Transform2D::applyTransform(gun);
			}
			break;
		case 'q':
			if( (circle->centru->x - circle->lungime > 100) && 
				(circle->centru->y + circle->lungime < 400) 
				){
				pasx = pasx - speed;
				pasy = pasy + speed;
				circle->centru->x=circle->centru->x - speed;
				circle->centru->y=circle->centru->y + speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(-speed,speed);
				Transform2D::applyTransform(gun);
			}
			break;
		case 'z':
			if( (circle->centru->x - circle->lungime > 100) && 
				(circle->centru->y - circle->lungime > 100) 
				){
				pasx = pasx - speed;
				pasy = pasy - speed;
				circle->centru->x=circle->centru->x - speed;
				circle->centru->y=circle->centru->y - speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(-speed,-speed);
				Transform2D::applyTransform(gun);
			}
			break;
		case 'x':
			if( (circle->centru->x + circle->lungime < 400) && 
				(circle->centru->y - circle->lungime > 100) 
				){
				pasx = pasx + speed;
				pasy = pasy - speed;
				circle->centru->x=circle->centru->x + speed;
				circle->centru->y=circle->centru->y - speed;
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(pasx,pasy);
				Transform2D::applyTransform(circle);
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(speed,-speed);
				Transform2D::applyTransform(gun);
			}
			break;
		
	}
}


//functia care defineste ce se intampla cand se da click pe mouse
// aici rotirea armei
void DrawingWindow::onMouse(int button,int state,int x, int y)
{
	if(is_on)
		switch (button){ 
			case GLUT_LEFT_BUTTON:
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(-circle->centru->x, -circle->centru->y);
				Transform2D::rotateMatrix(0.25);
				Transform2D::translateMatrix(circle->centru->x, circle->centru->y);
				Transform2D::applyTransform(gun);
				Transform2D::loadIdentityMatrix();
				break;
			case GLUT_RIGHT_BUTTON:
				Transform2D::loadIdentityMatrix();
				Transform2D::translateMatrix(-circle->centru->x, -circle->centru->y);
				Transform2D::rotateMatrix(-0.25);
				Transform2D::translateMatrix(circle->centru->x, circle->centru->y);
				Transform2D::applyTransform(gun);
				Transform2D::loadIdentityMatrix();
				break;
		}
}




int main(int argc, char** argv)
{
	
	//playing background sound (sound taken from youtube)
	PlaySound(TEXT("space.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP | SND_LOOP);

	//creare fereastra
	DrawingWindow dw(argc, argv,500, 500, 200, 100, "Tema 1 EGC");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();

	return 0;

}