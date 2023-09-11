//10031-篝火晚会.cpp
#include <cstdio>
#include <cstring>

const int SIZE = 50000;

int nea[SIZE], neb[SIZE], circle[SIZE], ud[SIZE];
int amount;

bool init() {
	scanf ("%d", &amount);
	for (int i=0; i<amount; ++i) {
		scanf ("%d%d", nea+i, neb+i);
		nea[i]-=1; neb[i]-=1;
	}
	memset (ud, 0, sizeof(ud));
	circle[0] = 0;
	ud[0] = 1;
	for (int i=1, k=0; i<amount; ++i) {
		if ( ud[ nea[k] ] == 0 ) {
			ud[ nea[k] ] = 1;
			circle[i] = nea[k];
			k = nea[k];
		}else if ( ud[ neb[k] ] == 0 ) {
			ud[ neb[k] ] = 1;
			circle[i] = neb[k];
			k = neb[k];
		}else return false;
	}
	return true;
}

void deal() {
	nea[0] = neb[0] = 0;
	for (int i=1; i<amount; ++i) {
		nea[i] = (circle[i]-i+amount)%amount;
		neb[i] = (circle[amount-i]-i+amount)%amount;
	}
	memset (ud, 0, sizeof(ud));
	memset (circle, 0, sizeof(circle));
	for (int i=0; i<amount; ++i) {
		++ud[ nea[i] ];
		++circle[ neb[i] ];
	}
	int im=0;
	for (int i=0; i<amount; ++i) {
		if (ud[i]>im) im = ud[i];
		if (circle[i]>im) im = circle[i];
	}
	printf ("%d\n", amount-im);
}

int main() {
	int in;
	scanf ("%d", &in);
	while (in--) {
		if (init())
			deal();
		else puts("-1");
	}
}
