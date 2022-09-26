#include <stdio.h>
#include <stdlib.h>

struct SeqString {
    int MAXNUM;
    int n;
    char *c;
};
typedef struct SeqString * PSeqString;

//空的，最大长度为 m 的 string
PSeqString createNullStr_seq (int m) {
    PSeqString pstr = (PSeqString) malloc (sizeof (struct SeqString));
    if (pstr != NULL) {
        pstr -> c = (char*) malloc (sizeof (char) * m);
        if (pstr -> c != NULL) {
            pstr -> n = 0;
            pstr -> MAXNUM = m;
            return pstr;
        }
        else free(pstr);
    }
    printf ("out of space\n");
    return NULL;
}

//i 开始取 j 个
PSeqString subStr_seq (PSeqString s, int i, int j) {
    PSeqString s1;
    s1 = createNullStr_seq (j);
    if (s1 == NULL) return NULL;
    if (i > 0 && i <= s -> n && j > 0) {
        if (s -> n < i + j - 1) j = s -> n - i + 1;
        for (int k = 0; k < j; k ++ )
            s1 -> c[k] = s -> c[i + k - 1];
        s1 -> n = j;
    }
    return s1;
}



int main () {
    return 0;
}