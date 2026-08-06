#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent an item with its value and weight
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items by their value-to-weight ratio in descending order
bool compareItems(const Item& a, const Item& b) {
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB; // Higher ratio comes first
}

// Function to calculate the maximum value possible for the Fractional Knapsack
double getFractionalKnapsackValue(int W, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    for (const auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        } else {
            double fraction = (double)W / item.weight;
            totalValue += item.value * fraction;
            break; // The knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    
    std::cout << "Enter the number of items: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid number of items." << std::endl;
        return 1;
    }

    std::cout << "Enter the maximum capacity of the knapsack: ";
    if (!(std::cin >> W) || W < 0) {
        std::cerr << "Invalid knapsack capacity." << std::endl;
        return 1;
    }

    std::vector<Item> items(n);
    std::cout << "\nEnter the value and weight for each item:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Item " << (i + 1) << " (Value Weight): ";
        std::cin >> items[i].value >> items[i].weight;
        
        // Input validation to prevent division by zero or negative weights
        if (items[i].value < 0 || items[i].weight <= 0) {
            std::cerr << "Error: Weight must be positive and value cannot be negative." << std::endl;
            return 1;
        }
    }

    // Calculate the maximum fractional knapsack value
    double maxValue = getFractionalKnapsackValue(W, items);
    
    std::cout << "\n-----------------------------------------" << std::endl;
    std::cout << "Maximum value attainable = " << maxValue << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    return 0;
}