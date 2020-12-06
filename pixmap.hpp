#ifndef __PIXMAP_HPP__
#define __PIXMAP_HPP__
#include <iostream>

typedef uint8_t pixcmp;
typedef uint32_t pixel;


class Pixmap{
  private:
    int largeur;
    int hauteur;
    pixel* donnees;
    bool avec_alpha;
  public:
    Pixmap();
    Pixmap(const int largeur, const int hauteur);
    Pixmap(const int largeur, const int hauteur, const int couleur_fond);
    Pixmap(const Pixmap & pix);
    ~Pixmap();

    void convertir_en_gris();
};
#endif

