int sum(int* array, const unsigned int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int sq_sum(int* array, const unsigned int size) {
    int square_sum = 0;
    for (int i = 0; i < size; i++) {
        square_sum += array[i] * array[i];
    }
    return square_sum;
}

int sumsix(int* array, const unsigned int size) {
    int sum_six = 0;
    if (size < 6) {
        for (int i = 0; i < size; i++) {
            sum_six += array[i];
        };
    }
    else {
        for (int i = 0; i < 6; i++) {
            sum_six += array[i];
        }
    }
    return sum_six;
}

int sumk1k2(int* array, const unsigned int size, const int k1, const int k2) {
    int sum_k1k2 = 0;
    if (size < k1) {
        return 0;
    }
    if (size < k2) {
        for (int i = k1 - 1; i < size; i++) {
            sum_k1k2 += array[i];
        }
    }
    else {
        for (int i = k1 - 1; i < k2; i++) {
            sum_k1k2 += array[i];
        }
    }
    return sum_k1k2;
}

float mean(int* array, const unsigned int size) {
    int summa = 0;
    if (size == 0) {
        return 0;
    }
    for (int i = 0; i < size; i++) {
        summa += array[i];
    }
    float mean = summa / size;
    return mean;
}

int mean1k2(int* array, const unsigned int size, int k1, int k2) {
    float mean_k1k2 = sumk1k2(array, size, k1, k2) / (k2 - k1 + 1);
    return mean_k1k2;
}


