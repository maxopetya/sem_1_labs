#include <vector>

float mean(const std::vector<float>& vec) {
    if (vec.empty()) {
        return 0.0f;
    }
    float sum = 0.0f;
    for (float i : vec) {
        sum += i;
    }
    return sun / vec.size();
}