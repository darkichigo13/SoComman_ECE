#ifndef ALLEGRO_PERSO_H_INCLUDED
#define ALLEGRO_PERSO_H_INCLUDED

// dimension fenetre
#define WINDOH 800
#define WINDOL 600


#define NIMAGE 25

// dimension d'une image
#define PICTH 30
#define PICTL 30

// sol terre
#define solTerreX 0
#define solTerreY 0

// mur 1
#define mur1X 31
#define mur1Y 0

// caisse
#define caisseX 0
#define caisseY 31

// mur 2
#define mur2X 0
#define mur2Y 62

// sol sable
#define solSableX 155
#define solSableY 31

// casse win
#define caseWinX 155
#define caseWinY 62

// annimZ :
#define anniZ1X 31
#define anniZ1Y 31

#define anniZ2X 62
#define anniZ2Y 31

#define anniZ3X 93
#define anniZ3Y 31

#define anniZ4X 124
#define anniZ4Y 31

// annimQ :
#define anniQ1X 31
#define anniQ1Y 62

#define anniQ2X 62
#define anniQ2Y 62

#define anniQ3X 93
#define anniQ3Y 62

#define anniQ4X 124
#define anniQ4Y 62

// annimS :
#define anniS1X 62
#define anniS1Y 0

#define anniS2X 93
#define anniS2Y 0

#define anniS3X 124
#define anniS3Y 0

#define anniS4X 155
#define anniS4Y 0


BITMAP ** initTabBitmap ();


#endif // ALLEGRO_PERSO_H_INCLUDED
