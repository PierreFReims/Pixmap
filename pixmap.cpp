#include <iostream>
#include "pixmap.hpp"

Rectbox::Rectbox()
{
  x1 = y1 = x2 = y2 = -1;
}
void Rectbox::setter(const int x1, const int y1, const int x2, const int y2)
{
  setter(x1,y1 , x2 , y2);
}
Pixmap::Pixmap() 
{
  this->largeur = -1;
  this->hauteur = -1;
  this->donnees = nullptr;
  this->avec_alpha = false;
}
Pixmap::Pixmap(const int largeur, const int hauteur)
{
  this->largeur = largeur;
  this->hauteur = hauteur;
  this->donnees = new pixel[largeur * hauteur];
  this->avec_alpha = false;
  std::cout << "Constructeur à deux paramètres appelé." << std::endl;
}
//Pixmap::Pixmap(const int largeur, const int hauteur, const int couleur_fond);
Pixmap::Pixmap(const Pixmap & pix)
{
  this->largeur = pix.largeur;
  this->hauteur = pix.hauteur;
  this->avec_alpha = pix.avec_alpha;
  this->donnees = new pixel[largeur * hauteur];
  for (int i = 0; i < largeur * hauteur; i++)
  {
    donnees[i] = pix.donnees[i];
  }
}
Pixmap::~Pixmap()
{
  delete[] donnees;
  std::cout << "Destructeur appelé sur une pixmap de taille " << this->largeur << " x " << this->hauteur << std::endl;
}
void Pixmap::convertir_en_gris()
{
  std::cout << "Conversion en gris" << std::endl;
}
pixel* Pixmap::obtenir_pixels()
{
  return donnees;
}
int Pixmap::get_largeur()
{
  return largeur;
}

//g++ pixmap.cpp test.cpp -o pix.out $(pkg-config --cflags --libs sdl2) && ./pix.out
//g++ -g -DDEBUG -W -Wall -Wextra -O3 pixmap.cpp test.cpp -o pix.out $(pkg-config --cflags --libs sdl2) && ./pix.out