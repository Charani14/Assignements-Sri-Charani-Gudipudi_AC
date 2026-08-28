#include <iostream>
using namespace std;

struct Layout1
{
    char c1;
    int i;
    char c2;
};

struct Layout2
{
    int i;
    char c1;
    char c2;
};

int main()
{
    cout << "Size of Layout1 : "
         << sizeof(Layout1) << " bytes" << endl;

    cout << "Size of Layout2 : "
         << sizeof(Layout2) << " bytes" << endl;

    /*
    STRUCT PADDING EXPLANATION
    ===========================

    1. Why can the sizes differ?

       Both structures contain the same members:
           char, int, char

       But the members are arranged in a different order.

       Layout1:
           char c1
           int i
           char c2

       Layout2:
           int i
           char c1
           char c2

       The compiler follows alignment rules for each data type.
       Because the order is different, the compiler may need
       different amounts of padding.

    2. What is padding?

       Padding means extra unused bytes added by the compiler
       between or after structure members.

       An int commonly requires 4-byte alignment.

       In Layout1, after the first char, the compiler may add
       3 padding bytes before the int so that the int starts
       at a suitable memory address.

       Example:

       Layout1:

       char     padding     int       char
        1 byte   3 bytes    4 bytes   1 byte
       ----------------------------------------
                    Total may be 12 bytes

       The compiler may also add padding at the end so that
       the complete structure has the correct alignment.

    3. Why does member order matter?

       Changing the order of members can change the amount
       of padding and therefore change sizeof(struct).

       This is important when defining:

       - Network packet headers
       - Hardware register maps
       - Binary file formats
       - Memory-mapped structures

       In these situations, the exact position of each member
       in memory can be important.

       Therefore, changing the member order can change the
       memory layout and may cause incorrect communication
       with hardware or other systems.
    */

    return 0;
}