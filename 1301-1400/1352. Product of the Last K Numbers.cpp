class ProductOfNumbers {
public:
    vector<int> pre{1};
    ProductOfNumbers() {}

    void add(int num) {
        if (num != 0) {
            pre.push_back(num * pre.back());
        } else {
            pre.clear();
            pre.push_back(1);
        }
    }

    int getProduct(int k) {
        return k < pre.size() ? pre.back() / pre[pre.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
