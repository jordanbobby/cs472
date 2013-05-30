#include <stdio.h>
#include <stdint.h>

#if __BYTE_ORDER__ != __ORDER_BIG_ENDIAN__
#define IS_BIG_ENDIAN 1
#else
#define IS_BIG_ENDIAN 0
#endif
#define SWAP_BYTES(x) ((x << 8) | ((x >> 8) & 0xFF))

int main(int argc, char **argv)
{
	short val;
	char *p_val;
	p_val = (char *) &val;

    p_val[0] = 0x12;
    p_val[1] = 0x34;
 
    if (IS_BIG_ENDIAN) {
       printf("%x\n", val);
		
    } else {
	    val = SWAP_BYTES(val);
	    printf("%x\n", val);
	    
    }
    
	return 0;
}

