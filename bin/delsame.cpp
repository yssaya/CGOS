#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// 444011|2018-07-06 01:12|DancingWhale5|Aya793d_524_ro_2k|B+Time
// 444034|2018-07-06 02:37|Maru-3.3.2raw-0g|DancingWhale5|W+Time

const char *pSame[][8] = {
 { "LZ","lz","Leela","ELF",NULL },
 { "kata","Kata","KG","k40b","k160","Ka",NULL },
 { "Zen",NULL },
 { "CrazyStone","CS",NULL },
 { "Rnz","rn","Rn",NULL },
 { "Aya",NULL },
 { "myCtest",NULL },
 { "AQ",NULL },
 { "Dirichlet",NULL },
 { "CGI",NULL },
 { "DCNN-",NULL },
 { "Odin",NULL },
 { NULL }
};

int main()
{
	FILE *fp = fopen("digest.txt","r");
	if ( fp==NULL ) exit(0);
	FILE *fp2 = fopen("digest2.txt","w");
	if ( fp2==NULL ) exit(0);
	int all = 0,sum = 0;
	for ( ;; ) {
		char buf[256];
		char buf2[256];
		if ( fgets( buf, 256, fp ) == NULL ) break;	// EOF
		all++;
		if ( strstr(buf,"+Time") ) continue;
		strcpy(buf2,buf);

		char *p0 = strstr(buf,"|");
		if ( p0==NULL ) exit(0);
                char *p1 = strstr(p0+1,"|");
                if ( p1==NULL ) exit(0);
                char *p2 = strstr(p1+1,"|");
                if ( p2==NULL ) exit(0);
		*p1 = 0;
		*p2 = 0;

		int del = 0;
		for (int i=0;;i++) {
			if ( pSame[i][0] == NULL ) break;
			int found = 0;
			for (int j=0;;j++) {
				const char *p = pSame[i][j];
				if ( p==NULL ) break;
				if ( strstr(p1+1,p) ) { found++; break; }
			}
                        for (int j=0;;j++) {
                                const char *p = pSame[i][j];
                                if ( p==NULL ) break;
				if ( strstr(p2+1,p) ) { found++; break; }
                        }
			if ( found >= 2 ) { del = 1; break; }
		}
		if ( del ) continue;

		fprintf(fp2,"%s",buf2);
		sum++;
	}
	printf("sum=%d,all=%d\n",sum,all);
	return 0;
}


