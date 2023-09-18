//11067-Phone List.cpp
#include<cstdio>
struct Node {
	char have;
	Node *next[10];
	Node() {
		have=0;
		for( int i=0; i<10; ++i )
			next[i]=NULL;
	}
};
const char END = 64;
class Tree {
private:
	Node *head;
	void Destroy( Node* pos ) {
		for( int i=0; i<10; ++i )
		if( pos->next[i] )
			Destroy( pos->next[i] );
	}
public:
	Tree() {
		head = new Node();
	}
	~Tree() { Destroy( head ); }
	char Add( char *str ) {
		Node *pos=head;
		int k;
		for( int i=0; str[i]; ++i ) {
			k=str[i]-'0';
			if( pos->have&END ) return 0;
			if( pos->next[k]==NULL ) {
				++(pos->have);
				pos->next[k] = new Node();
			}
			pos=pos->next[k];
		}
		if( pos->have>0 ) return 0;
		pos->have |= END;
		return 1;
	}
};
int main(){
	int t, n; scanf( "%ld", &t );
	char flag, str[20];
	while( t-- ) {
		Tree atre;
		scanf( "%ld", &n );
		flag=1;
		while( n-- ) {
			scanf( "%s", str );
			if( flag )
				if( atre.Add( str )==0 ) flag=0;
		}
		if( flag )
			puts( "YES" );
		else puts( "NO" );
	}
    return 0;
}
