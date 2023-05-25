#include <stdio.h>

int get_card_value(char card) {
    if (card >= '2' && card <= '9') {
        return card - '0';
    } else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K') {
        return 10;
    } else if (card == 'A') {
        return 11;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hand>\n", argv[0]);
        return 1;
    }

    int total = 0;
    int num_aces = 0;

    for (int i = 0; argv[1][i] != '\0'; i++) {
        int value = get_card_value(argv[1][i]);
        total += value;

        if (value == 11) {
            num_aces++;
        }

        while (total > 21 && num_aces > 0) {
            total -= 10;
            num_aces--;
        }
    }

    printf("Hand: %s\n", argv[1]);
    printf("Total points: %d\n", total);

    return 0;
}
