#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "LibMd5.h"


int md5str(char *buffer, char *target)
{
    Md5Context      md5Context;
    MD5_HASH        md5Hash;
    uint16_t        i;

    Md5Initialise( &md5Context );
    Md5Update( &md5Context, buffer, (uint32_t)strlen(buffer) );
    Md5Finalise( &md5Context, &md5Hash );

    for( i=0; i<sizeof(md5Hash); i++ )
    {
        sprintf( target+i*2, "%02x", md5Hash.bytes[i] );
    }

    return 0;
}


int main()
{
	static char buffer[6666666*33+100];
	static char target[9999999];
    for (int i=0; i < 6666666; ++i) {
	// for (int i=0; i < 66666; ++i) {
        if (i > 0) { buffer[i*33-1] = '-'; }
		fgets(buffer+i*33, 8888888, stdin);
        buffer[i*33+32] = '\0';
	}
    md5str(buffer, target);
    // printf("%s\n", buffer);
    printf("%s\n", target);
	return 0;
}