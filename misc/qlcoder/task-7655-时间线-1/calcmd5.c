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
	char buffer[9999];
	char target[9999];
	for (int i=0; i < 6666666; ++i) {
	// for (int i=0; i < 3; ++i) {
		fgets(buffer, 8888, stdin);
		int len = strlen(buffer);
		buffer[len-1] = '\0';
		md5str(buffer, target);
		printf("%s\n", target);
	}
	return 0;
}