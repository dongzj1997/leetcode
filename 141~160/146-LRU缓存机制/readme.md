# 146-LRU缓存机制

```c++
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

```c++
class LRUCache {
public:
	int cap;

	list<pair<int, int>> cache;  // 双链表（与 向量(vectors)相比, 它允许快速的插入和删除，但是随机访问却比较慢.）：装着 (key, value) 元组 (就是实际的CACHE)
	
	//使用unordered_map存储cache中具体数的位置，克服随机访问比较慢的问题
	unordered_map<int, list<pair<int, int>>::iterator> mp;  // 哈希表：key 映射到 (key, value) 在 cache 中的位置  （::iterator 迭代器指向位置）

	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto it = mp.find(key);
		
		if (it == mp.end()) // 访问的 key 不存在
			return -1;
		
		pair<int, int> kv = *mp[key];  // key 存在，把 (k, v) 换到队头,然后返回pair的第二个元素（对于iterator，可以直接使用* 解引用）
		cache.erase(mp[key]);
		cache.push_front(kv);
		
		mp[key] = cache.begin();// 更新 (key, value) 在 cache 中的位置

		return kv.second; // 返回值
	}


	void put(int key, int value) {


		auto it = mp.find(key);

		if (it == mp.end()) {  // 访问的 key 不存在

			if (cache.size() == cap) {  // cache 已满
				
				auto lastPair = cache.back();
				int lastKey = lastPair.first;

				mp.erase(lastKey);  // 删除map 中的数据
				cache.pop_back();   // 删除尾部的键值对
			}

			// cache 没满，直接添加
			cache.push_front(make_pair(key, value));
			mp[key] = cache.begin();
		}
		else {  //key 存在，更改 value 并换到队头 */
			cache.erase(mp[key]);
			cache.push_front(make_pair(key, value));
			mp[key] = cache.begin();
		}
	}
};
```

---

## 解题：使用哈希链表

对于LRU这种特定的需求，要想在O(1)的时间内实现查找和添加，我们必须找一种特殊的数据结构，这种数据结构应该包含一下特点：

1. 随机查找快

2. 插入快

3. 删除快

对于2和3，使用双向链表（C++中的list）即可解决，对于1，可以使用哈希表查找（c++中的unordered_map），但是数据无固定顺序，如果将这两种数据结构结合起来，就达到了我们的目的。

![123](./1.jpg)

思想很简单，就是借助哈希表赋予了链表快速查找的特性嘛：可以快速查找某个 key 是否存在缓存（链表）中，同时可以快速删除、添加节点。

最后，注意理解几个关键的数据结构：

```C++
	list<pair<int, int>> cache;  // 双链表（与 向量(vectors)相比, 它允许快速的插入和删除，但是随机访问却比较慢.）：装着 (key, value) 元组 (就是实际的CACHE)
	
	//使用unordered_map存储cache中具体数的位置，克服随机访问比较慢的问题
	unordered_map<int, list<pair<int, int>>::iterator> mp;  // 哈希表：key 映射到 (key, value) 在 cache 中的位置  （::iterator 迭代器指向位置）

    pair<int, int> kv = *mp[key];  // key 存在，把 (k, v) 换到队头,然后返回pair的第二个元素（对于iterator，可以直接使用* 解引用）

```
