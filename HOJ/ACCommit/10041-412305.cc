#include <cstdio>
#include <cstring>
#include <cctype>

const int SIZE = 12000;
char word[][10] = {"ENCRYPT ", "DECRYPT ", "CIPHER "};

int ntoa[26], aton[26];

void setDefault() {
    for (int i=0; i<26; ++i)
        ntoa[i] = aton[i] = i;
}
void setEmpty() {
    memset (ntoa, -1, sizeof(ntoa));
    memset (aton, -1, sizeof(aton));
}

bool strStart (char *str, char *tag) {
    for (int i=0; tag[i]; ++i)
        if (toupper(str[i])!=tag[i]) return false;
    return true;
}

void crypt (char *ss, bool en) {
    int pre, next, tn;
    bool lower;
    pre = aton[0];
    for (int i=0; ss[i]; ++i )
    if (isalpha(ss[i])) {
        lower = islower(ss[i]);
        tn = toupper(ss[i])-\'A\';
        tn = aton[tn];
        if (en) {
            next = (26+tn-pre)%26;
            pre = tn;
        }else {
            next = (pre+tn)%26;
            pre = next;
        }
        ss[i] = ntoa[next]+\'A\'+(lower?32:0);
    }else pre = aton[0];
}

bool setCipher (char *ss) {
    setEmpty();
    int a;
    for (int i=0, x=0; ss[i]; ++i)
    if (isalpha(ss[i])) {
        a = toupper(ss[i])-\'A\';
        if (aton[a]==-1) {
            aton[a] = x;
            ntoa[x] = a;
            ++x;
        }else return false;
    }
    for (int i=0; i<26; ++i)
        if (ntoa[i]==-1||aton[i]==-1) return false;
    return true;
}

char str[SIZE];
int main() {
    setDefault();
    while (gets(str)) {
        if (strStart (str, word[0])) {
            crypt (str+8, 1);
            printf ("RESULT: %s\n", str+8);
        }else if (strStart (str, word[1])) {
            crypt (str+8, 0);
            printf ("RESULT: %s\n", str+8);
        }else if (strStart (str, word[2])) {
            if (setCipher(str+7)) {
                printf ("Good cipher. Using ");
                for (int i=0; i<26; ++i)
                    putchar (ntoa[i]+\'A\');
                printf (".\n");
            }else {
                setDefault();
                puts ("Bad cipher. Using default.");
            }
        }else puts ("Command not understood.");
    }
}
