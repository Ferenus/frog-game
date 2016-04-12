///
/// \brief The TypeOfCell enum Typy komórek na mapie.
///
enum TypeOfCell {trawa, woda, asfalt, zabaNaTrawie};
///
/// \brief The OrderDirection enum Kierunki, w jakich mogą poruszać się obiekty ruchome oraz orientacja komórek na mapie.
///
enum OrderDirection {gora, dol, lewo, prawo, nic};

struct S_Point {
    int x;
    int y;
};
