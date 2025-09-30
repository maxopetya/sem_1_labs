#include <limits>
#include <vector>
#include <algorithm>
#include <iostream>

std::pair<float, float> MinMax(const std::vector<float>& v) {
    if (v.empty()) {
        float min = std::numeric_limits<float>::lowest();
        float max = std::numeric_limits<float>::max();
        return std::make_pair(min,max);
    }
    else {
        std::vector<float> temp = v;
        std::sort(temp.begin(), temp.end());
        float min = temp[0];
        float max = temp[temp.size()-1];
        return std::make_pair(min,max);
    }
}

int main() {
    std::vector<float> v = {1.1};
    auto result = MinMax(v);
    std::cout << result.first << " " << result.second << std::endl;
}