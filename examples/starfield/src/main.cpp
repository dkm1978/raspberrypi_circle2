#include "proteus.h" // incuding SDL files and some additiona functions.
#include "stars.h"

/*
*
* To close application press ALT+F4 xD
*
*/


int main(int argc, char *argv[])
{
    initSDL(1920, 1080, "Raotating stars :)");
    stars_main(1920,1080);
    return 0;
}