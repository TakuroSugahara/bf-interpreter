#include <stdio.h>
#include <string.h>

void display(int output[]) {
  for (int i = 0; i < 256; i++) {
    if (output[i] == '\0') {
      break;
    }
    printf("%c", output[i]);
  }
}

int main() {
  int pointer = 0, ouput_index = 0;
  int memory[256], output[256];
  char bf[256];

  // brainf**kのコードを受け取る
  scanf("%s", bf);

  printf("↓\n");

  for (int i = 0; i < strlen(bf); i++) {
    switch (bf[i]) {
      case '+':
        memory[pointer]++;
        break;
      case '-':
        memory[pointer]--;
        break;
      case '>':
        pointer++;
        break;
      case '<':
        pointer--;
        break;
      case '[':
        if (memory[pointer] != 0) {
          continue;
          break;
        }
        for (int j = i; j < strlen(bf); j++) {
          if (bf[j] == ']') {
            i = j; // ']までジャンプ'
            break;
          }
        }
        break;
      case ']':
        for (int j = i; j > 0; j--) {
          if (bf[j] == '[') {
            i = j - 1; // '[までジャンプ'
            break;
          }
        }
        break;
      case ',':
        memory[pointer] = getchar();
        break;
      case '.':
        output[ouput_index] = memory[pointer];
        output[ouput_index + 1] = '\0';
        ouput_index++;
        break;
      default:
        printf("エラーーー");
        break;
    }
  }

  display(output);

  return 0;
}
