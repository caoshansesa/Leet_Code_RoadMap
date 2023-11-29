#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValid(char *s) {
  int len = strlen(s);
  if ((strstr(s, "[") != NULL && strstr(s, "]") != NULL) ||
      (strstr(s, "(") != NULL && strstr(s, ")") != NULL) ||
      (strstr(s, "{") != NULL && strstr(s, "}") != NULL)) {

    return true;
  } else {
    return false;
  }
}

int main() {
  char input[] = "a(bcd{e}";
  bool result = isValid(input);
  printf("%d\n", result);
}
