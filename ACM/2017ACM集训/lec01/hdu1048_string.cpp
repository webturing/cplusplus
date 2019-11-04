/**
Sample Input

START
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT

Sample Output

IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE

http://acm.hdu.edu.cn/showproblem.php?pid=1048
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main() {
  char a[1000], b[1000];
  int i;
  while (gets(a)) {
    if (strcmp(a, "START") == 0)
      memset(b, 0, sizeof(b));
    else if (strcmp(a, "END") == 0)
      cout << b;
    else if (strcmp(a, "ENDOFINPUT") == 0)
      break;
    else {
      for (i = 0; a[i] != 0; i++) {
        if (isapha(a[i])) {
          if (a[i] + 21 > 90)
            b[i] = a[i] - 5;
          else
            b[i] = a[i] + 21;
        } else
          b[i] = a[i];
      }
    }
  }
  return 0;
}