#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>
#include <algorithm>

template<typename Container> 
void runTest(int len, int trials){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2 * len);
    auto start = std::chrono::high_resolution_clock::now();
    
    for(int i = 0; i < trials; ++i) {
        Container c;

        for(int j = 0; j < len; ++j) {
            c.push_back(dis(gen));
        }

        int x = 0;
        while(!c.empty()) {
            if constexpr (std::is_same_v<Container, std::list<int>>) {
                c.remove_if([x](int n){ return n == x; });
            } else if constexpr (std::is_same_v<Container, std::vector<int>>) {
                c.erase(std::remove_if(c.begin(), c.end(), [x](int n){ return n == x; }), c.end());
            }
            ++x;
        }
    }
        
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << "Time taken: " << duration.count() << " microseconds" << "\n";
}

int main(int argc, char** argv) {
    
    if(argc != 3){
        std::cout << "Usage: program sequence_length number_of_trials" << "\n";
        return -1;
    }

    int len = atoi(argv[1]);
    int trials = atoi(argv[2]);
    
    std::cout << "Running test on list with length: " << len << " and trials: " << trials << "\n";
   
    runTest<std::list<int>>(len,trials);
   
    std::cout << "Running test on vector with length: " << len << " and trials: " << trials << "\n";

    runTest<std::vector<int>>(len,trials);

    return 0;
}

