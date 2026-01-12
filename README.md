# 🚀 LRU Cache System (C++)

A high-performance **Least Recently Used (LRU) Cache System** implemented in **C++** using a **Doubly Linked List** and **Unordered Map** to achieve **O(1)** time complexity for cache access, insertion, and eviction.

This project demonstrates how caching mechanisms are designed and used in **real-world backend systems and operating systems** to reduce latency and optimize performance.

---

## ✨ Key Features

- ✅ O(1) time complexity for **Get** and **Put** operations  
- ✅ Efficient eviction using **Least Recently Used (LRU)** policy  
- ✅ Uses **Unordered Map** for constant-time key lookup  
- ✅ Uses **Doubly Linked List** to maintain usage order  
- ✅ Supports **string values** with integer keys  
- ✅ Clean, modular, and well-documented code  

---

## 🧠 Why LRU Cache?

In modern software systems, accessing data from disk or secondary memory is expensive.  
An **LRU Cache** stores frequently accessed data in faster memory and removes the least recently used items when capacity is exceeded.

This strategy is widely used in:
- Backend servers
- Databases
- Web browsers
- Operating Systems (page replacement)

---

## 🏗️ Design Overview

The cache system internally uses the following components:

### 🔹 Doubly Linked List
- Maintains the order of data usage  
- Most recently used item at the front  
- Least recently used item at the back  

### 🔹 Unordered Map
- Maps keys to list iterators  
- Enables constant-time access and updates  

This combination ensures **optimal performance and scalability**.

---

## ⚙️ System Workflow

1. **Cache Hit**
   - Data is returned in O(1)
   - Accessed item is moved to the front

2. **Cache Miss**
   - Returns default value
   - Cache remains unchanged

3. **Cache Full**
   - Least recently used item is evicted
   - New item is inserted at the front

---

## 🖥️ Real-World Use Cases

### 🔸 Backend Systems
LRU caching helps backend services:
- Reduce response latency  
- Avoid repeated database or disk access  
- Improve performance under high traffic  

Example use cases:
- API response caching  
- User session data  
- Configuration caching  

---

### 🔸 Operating Systems (Page Replacement)

LRU is widely used in **virtual memory management**:
- Pages are loaded into RAM on demand  
- Least recently used pages are replaced  
- Reduces page faults and system thrashing  

This project closely models how **LRU Page Replacement Algorithms** work internally.

---

## 📂 Project Structure

```text
LRU-Cache-System/
│
├── lru_cache.cpp        # LRU Cache System implementation
└── README.md            # Project documentation
-
```

## 🧪 Example Usage

```cpp
LRU_Cache cache(2);

cache.feedin(1, "alpha");
cache.feedin(2, "beta");
cache.feedin(3, "gamma"); // Evicts key 1

cout << cache.gettin(2);  // Cache hit
cout << cache.gettin(1);  // Cache miss
