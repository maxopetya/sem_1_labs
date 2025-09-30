void first_neg(int* input, int size) {
    for (int i = 0; i < size; ++i) {
        if (input[i] < 0) {
            for (int j = i; j < size - 1; ++j) {
                input[j] = input[j + 1];
            }
            size--;
            return;
        }
    }
}

void last_even(int* input, int size) {
    for (int i = size- 1; i >= 0; --i) {
        if (input[i] % 2 == 0) {
            for (int j = i; j < size - 1; ++j) {
                input[j] = input[j + 1];
            }
            size--;
            return;
        }
    }

}