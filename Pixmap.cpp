#include <iostream>
#include "pixmap.hpp"

Pixmap::Pixmap(){
  largeur = -1;
  hauteur = -1;
  donnees = nullptr;
  avec_alpha = false;
}
Pixmap::Pixmap(const int largeur, const int hauteur){
  this->largeur = largeur;
  this->hauteur = hauteur;
  this->donnees = new pixel[largeur * hauteur];
  this->avec_alpha = false;
}
Pixmap::~Pixmap(){
  delete[] donnees;
}
void Pixmap::convertir_en_gris(){
  std::cout << "Convertion en gris ..." << std::endl;
}

int main(int argc, char **argv ){
  (void)argc;
  (void)argv;
 
  std::cout << "Hello World" << std::endl;

  //Pixmap
  Pixmap p;
  p.convertir_en_gris();
  return 0;
}