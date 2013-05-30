#include <stdio.h>
#include <stdint.h>

#define SWAP_BYTES(x) ((x << 8) | ((x >> 8) & 0xFF))

int is_big_endian()
{
    union
    {
	    int16_t i;
	    char thechar[sizeof(int16_t)];
	    //uint32_t ind;
    } x = {0x0102};
    //printf ("x.thechar[0]=%d\n", x.thechar[0]);
    //printf ("x.thechar[1]=%d\n", x.thechar[1]);

    return x.thechar[0] == 1;
}

int main(int argc, char **argv)
{
	short val;
	char *p_val;
	p_val = (char *) &val;

    p_val[0] = 0x12;
    p_val[1] = 0x34;
 
    if (!is_big_endian()) {
	    val = SWAP_BYTES(val);
    }

	printf("%x\n", val);    
	return 0;
}
