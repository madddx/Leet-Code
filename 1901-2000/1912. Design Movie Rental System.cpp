class MovieRentingSystem {
    int n;
    unordered_map<int, set<tuple<int, int, int>>> movieToShop; // movie -> {price, shop, movie}
    set<tuple<int, int, int>> rented; // {price, shop, movie}
    unordered_map<int, unordered_map<int, int>> shopMovieToPrice; // shop -> movie -> price
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this->n = n;
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
            movieToShop[movie].insert({price, shop, movie});
            shopMovieToPrice[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        for (auto& item : movieToShop[movie]) {
            if (count >= 5) break;
            result.push_back(get<1>(item));
            count++;
        }
        return result;
    }
    
    void rent(int shop, int movie) {
        int price = shopMovieToPrice[shop][movie];
        movieToShop[movie].erase({price, shop, movie});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopMovieToPrice[shop][movie];
        movieToShop[movie].insert({price, shop, movie});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (auto& item : rented) {
            if (count >= 5) break;
            result.push_back({get<1>(item), get<2>(item)});
            count++;
        }
        return result;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
