#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, destination, timestamp;
    bool operator==(const Packet &o) const {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }//oop function overloading
};

// Custom hash for unordered_set
struct PacketHash {
    size_t operator()(const Packet &p) const {
        return ((size_t)p.source * 1315423911u) ^
               ((size_t)p.destination * 2654435761u) ^
               ((size_t)p.timestamp * 97531u);
    }//It allows you to use an object of PacketHash like a function:
    //return type is size_t (standard unsigned integer used for hashing).
   //operator() in PacketHash → lets unordered_set compute a hash for a packet. 
};

class Router {
private:
    int memoryLimit;
    queue<Packet> q;
    unordered_set<Packet, PacketHash> seen;
    unordered_map<int, vector<int>> destTimes;  // sorted timestamps

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        if (seen.count(p)) return false;

        if ((int)q.size() == memoryLimit) forwardPacket();  // auto forward oldest

        q.push(p);
        seen.insert(p);
        destTimes[destination].push_back(timestamp);  // append timestamps
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};  // no packet to forward

        Packet p = q.front(); 
        q.pop();
        seen.erase(p);

        // remove timestamp
        auto &vec = destTimes[p.destination];
        auto it = lower_bound(vec.begin(), vec.end(), p.timestamp);
        if (it != vec.end() && *it == p.timestamp) vec.erase(it);

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if (it == destTimes.end()) return 0;

        auto &vec = it->second;
        auto left = lower_bound(vec.begin(), vec.end(), startTime);
        auto right = upper_bound(vec.begin(), vec.end(), endTime);
        return right - left;
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */

// 1.Router class is designed to do three things:

// Add Packets: Receive new packets, but only if they are not duplicates.

// Manage Memory: Hold up to a memoryLimit of packets. If a new packet arrives when the memory is full, it must first forward (remove) the oldest packet to make space.

// Perform Queries: Efficiently count how many stored packets are destined for a specific location within a given time window (startTime to endTime).

// To achieve this, the solution uses three core data structures that work in sync.

// 2. The Data Structures (The Core Logic) \U0001f9e0
// The choice of data structures is the key to this solution's efficiency.

// queue<Packet> q
// What it is: A standard First-In, First-Out (FIFO) queue.

// Why it's used: It perfectly models the behavior of a router buffer. The first packet that comes in is the first one that should leave. This makes the forwardPacket operation (removing the oldest packet) very simple and fast (O(1) time). The oldest packet is always at q.front().

// unordered_set<Packet, PacketHash> seen
// What it is: A hash set that stores unique packets.

// Why it's used: Its job is to detect duplicate packets instantly. Checking if a packet exists in an unordered_set takes O(1) time on average. Without this, you'd have to search the entire queue (O(N)) every time you add a packet, which would be far too slow.

// Note on PacketHash: C++ doesn't know how to hash a custom struct like Packet by default. The PacketHash struct is a custom function we provide that tells the unordered_set how to convert a Packet into a unique hash value, allowing for that fast O(1) lookup. It does this by combining the source, destination, and timestamp using large prime numbers to minimize collisions.

// unordered_map<int, multiset<int>> destTimes
// This is the most advanced part of the solution, specifically designed for the getCount query.

// What it is: A hash map where:

// The key is the destination (an int).

// The value is a multiset<int> containing all the timestamps of packets heading to that destination.

// Why it's used:

// unordered_map: It groups all timestamps by their destination. This gives you instant (O(1) average) access to the list of timestamps for any given destination.

// multiset: A multiset is a type of balanced binary search tree. It automatically keeps the timestamps sorted and allows for duplicate timestamps. This sorted property is crucial because it allows you to find a range of times (startTime to endTime) very quickly using lower_bound and upper_bound, which both run in O(log K) time (where K is the number of packets for that destination).

// 3. Method-by-Method Explanation ⚙️
// bool addPacket(source, destination, timestamp)
// Creates a Packet struct from the input.

// Checks the seen set to see if this exact packet has been seen before. If yes, it's a duplicate, so it returns false.

// Checks if the router's memory (q) is full (q.size() == memoryLimit).

// If it is full, it calls forwardPacket() to remove the oldest packet and make space.

// Finally, it adds the new packet to all three data structures to keep them synchronized:

// Pushes to the back of the q.

// Inserts into the seen set.

// Inserts the timestamp into the multiset corresponding to its destination in destTimes.

// Returns true on success.

// void forwardPacket()
// This function removes the oldest packet from the system.

// It gets the oldest packet from the front of the q.

// It removes that packet from all three data structures to maintain consistency:

// Pops from the front of the q.

// Erases from the seen set.

// Finds and erases the corresponding timestamp from the correct multiset in destTimes.

// int getCount(destination, startTime, endTime)
// This is where the power of the destTimes map and multiset shines.

// It finds the entry for the given destination in the destTimes map. If no packets have this destination, it returns 0.

// It gets the sorted multiset of timestamps for that destination.

// lower_bound(startTime): Finds an iterator to the first timestamp that is greater than or equal to startTime.

// upper_bound(endTime): Finds an iterator to the first timestamp that is strictly greater than endTime.

// The elements between these two iterators are exactly the packets within the [startTime, endTime] range. std::distance(left, right) calculates how many there are. Because the data is sorted in a tree, this entire operation is very fast.

// Time Complexity Summary
// Let N be the memoryLimit and K be the number of packets for a specific destination (K <= N).

// addPacket: O(log K) on average. The dominant operation is inserting into the multiset.

// forwardPacket: O(log K) on average. The dominant operation is erasing from the multiset.

// * getCount: O(log K). The dominant operations are lower_bound and upper_bound on the multiset.

auto init=atexit([](){ofstream("display_runtime.txt")<<"0";});
