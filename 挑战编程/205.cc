#include <cstdlib>
#include <cstring>
#include <cstdio>

const int TOTAL=52;
const int SUITS=13;
char value[][10] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
char suit[][10] = { "Clubs", "Diamonds", "Hearts", "Spades" };

char str[100];
int cases, means, card[TOTAL], tmp[TOTAL];
int shuffle[100][54];

int main() {
	int i, j, k;
	scanf( "%d", &cases );
	while( cases-- ) {
		scanf( "%d", &means );
		for( i=0; i<means; ++i )
			for( j=0; j<TOTAL; ++j ) {
				scanf( "%d", shuffle[i]+j );
				--shuffle[i][j];
			}
		for( i=0; i<TOTAL; ++i ) card[i] = i;
		getchar();
		while( gets(str) ) {
			if( str[0]==0 ) break;
			sscanf( str, "%d", &k );
			for( i=0; i<TOTAL; ++i )
				tmp[i] = card[shuffle[k][i]];
			memcpy( card, tmp, TOTAL*sizeof(int) );
			for( i=0; i<TOTAL; ++i )
				printf( "%d ", card[i] );
			printf("\n");
		}
		/*for( i=0; i<TOTAL; i++)
			printf( "%s of %s\n", value[card[i]%SUITS], suit[card[i]/SUITS] );*/
		if( cases ) putchar('\n');
	}
}