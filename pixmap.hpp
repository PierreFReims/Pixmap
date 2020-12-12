#ifndef __PIXMAP_HPP__
#define __PIXMAP_HPP__

typedef uint8_t pixcmp;
typedef uint32_t pixel;
struct Rectbox
{
  int x1,y1,x2,y2;
  Rectbox();
  Rectbox(const int x1, const int y1, const int x2, const int y2);
  void setter(const int x1, const int y1, const int x2, const int y2);
};

class Pixmap
{
private:
  int largeur;
  int hauteur;
  pixel * donnees;
  bool avec_alpha;
  void init(const int largeur, const int hauteur);
public:
  Pixmap();
  Pixmap(const int largeur, const int hauteur);
  Pixmap(const int largeur, const int hauteur, const int couleur_fond);
  Pixmap(const Pixmap & pix);
  ~Pixmap();

  void convertir_en_gris();
  void effacer(const pixel fond);
  pixel* obtenir_pixels();
  void blit_on_texture_centered(SDL_Texture* texture, const int texture_lar, const int texture_hau);
  void blit_on_texture(SDL_Texture* texture, const int x1,const int y1);
  int get_largeur();
  int get_hauteur();
};

#endif
