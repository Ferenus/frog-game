#include "c_cell.h"

C_Cell::C_Cell()
{
    typKomorki = new TypeOfCell(asfalt);
    polozenie = new S_Point;
}

C_Cell::~C_Cell()
{
    delete typKomorki;
    delete polozenie;
}

