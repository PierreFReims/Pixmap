#include <iostream>
#include </usr/local/include/SDL2/SDL.h>
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
void  Pixmap::init(const int largeur, const int hauteur)
{
  this->largeur = largeur;
  this->hauteur = hauteur;
  this->donnees = new pixel[largeur * hauteur];
  this->avec_alpha = false;
}
Pixmap::Pixmap(const int largeur, const int hauteur)
{
  init(largeur, hauteur);
  std::cout << "Constructeur à deux paramètres appelé." << std::endl;
}
Pixmap::Pixmap(const int largeur, const int hauteur, const int couleur_fond)
{
  init(largeur, hauteur);
  effacer(couleur_fond);
  std::cout << "Constructeur à trois paramètres appelé." << std::endl;
}
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
void Pixmap::blit_on_texture_centered(SDL_Texture* texture, const int texture_lar, const int texture_hau)
{
  int x1 = (texture_lar - largeur) / 2;
  int y1 = (texture_hau - hauteur) / 2;
  blit_on_texture(texture, x1,y1);
}
void Pixmap::blit_on_texture(SDL_Texture* texture,int x1, int y1)
{
  SDL_Rect rect = {x1,y1, largeur, hauteur};
  SDL_UpdateTexture(texture, &rect, donnees, largeur * sizeof(Uint32));
}
void Pixmap::effacer(const pixel fond)
{
  for (int i = 0; i < largeur * hauteur; i++)
  {
    donnees[i] = fond;
  }
  
}
int Pixmap::get_largeur()
{
  return largeur;
}
int Pixmap::get_hauteur()
{
  return hauteur;
}

//g++ pixmap.cpp test.cpp -o pix.out $(pkg-config --cflags --libs sdl2) && ./pix.out
//g++ -g -DDEBUG -W -Wall -Wextra -O3 pixmap.cpp test.cpp -o pix.out $(pkg-config --cflags --libs sdl2) && ./pix.out