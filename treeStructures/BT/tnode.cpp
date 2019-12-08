#include "tnode.h"

std::ostream& operator<<(std::ostream& ostr, tnode * curr)
{
    ostr << curr->value;
    return ostr;
}
