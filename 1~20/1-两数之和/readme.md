使用字典或者hashmap可以以O(n)的复杂度快速求得解

需要注意的是，在python3中，查询字典是否有某个键时，可以直接使用key in dict，如果键在字典dict里返回true，否则返回false
这种方法速度较 key in dict.key() 快不少
