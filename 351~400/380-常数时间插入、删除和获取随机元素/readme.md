# 380. 常数时间插入、删除和获取随机元素

```c++
设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。

insert(val)：当元素 val 不存在时，向集合中插入该项。
remove(val)：元素 val 存在时，从集合中移除该项。
getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
示例 :

// 初始化一个空的集合。
RandomizedSet randomSet = new RandomizedSet();

// 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomSet.insert(1);

// 返回 false ，表示集合中不存在 2 。
randomSet.remove(2);

// 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomSet.insert(2);

// getRandom 应随机返回 1 或 2 。
randomSet.getRandom();

// 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomSet.remove(1);

// 2 已在集合中，所以返回 false 。
randomSet.insert(2);

// 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
randomSet.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-delete-getrandom-o1
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
```

---

用`unordered_map`和`vector`配合实现。

`unordered_map<int,int>`存储的是数值和该数值在`vector`中的下标。

`vector`存储该下表对应的数值。

**插入**时直接新增`map`和`vector`节点

**删除**时将要删除的节点和`vector`中最后的一个节点换位置（`map`中的值也要更新），然后删除`vector`中最后一个节点和对应的`map`中的节点，。

删除的

```c++
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> dict;
    vector<int> nums;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(dict.count(val) > 0)
            return false;
        nums.push_back(val);
        dict[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(dict.count(val) == 0)
            return false;
        dict[nums.back()] = dict[val]; //将val的在nums中的位置送给原来是最后一个位置的数
        nums[dict[val]] = nums.back();
        nums.pop_back();
        dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(nums.empty())
            return 0;
        int pos = rand() % nums.size();
        return nums[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```

---



