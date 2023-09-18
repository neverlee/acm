//10211-Booklet Printing.cpp
#include <cstdio>

int main() {
	int n;
	while (scanf ("%d", &n ), n) {
		printf ("Printing order for %d pages:\n", n);
		int ie, is;
		ie = (n/4+(n%4?1:0))*4;
		is = 1;
		for( int i=1; is<ie; ++i ) {
			printf ("Sheet %d, front: ", i);
			if (ie<=n) printf ("%d, %d\n", ie, is );
			else printf ("Blank, %d\n", is);
			++is; --ie;
			if (is<=n) {
				printf ("Sheet %d, back : ", i);
				if (ie<=n) printf ("%d, %d\n", is, ie);
				else printf ("%d, Blank\n", is);
			}
			++is; --ie;
		}
	}
}
