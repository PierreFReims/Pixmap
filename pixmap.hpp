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
    Pixmap(int const largeur, int const hauteur);
    Pixmap(int const largeur, int const hauteur, int const couleur_fond);
    Pixmap(Pixmap const &  pix);
    ~Pixmap(); 

    void convertir_en_gris();
    void effacer(pixel const fond);
    pixel * obtenir_pixels(Pixmap const & pix);
    int get_largeur();
    int get_hauteur();
    pixel * obtenir_pixels();
    void blit_on_texture_centered(SDL_Texture* const texture, int const texture_lar, int const texture_hau);
    void blit_on_texture(SDL_Texture* const texture, int const x1, int const y1);
};

#endif
