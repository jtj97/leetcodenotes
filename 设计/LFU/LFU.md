# LFU

需求:  
3.1、首先，肯定是需要 `freq` 到 `key` 的映射，用来找到 `freq` 最小的 `key`。  
3.2、将 `freq` 最小的 `key` 删除，那你就得快速得到当前所有 `key` 最小的 `freq` 是多少。想要时间复杂度 `O(1)` 的话，肯定不能遍历一遍去找，那就用一个变量 `minFreq` 来记录当前最小的 `freq` 吧。  
3.3、可能有多个 `key` 拥有相同的 `freq`，所以 `freq` 对 `key` 是一对多的关系，即一个 `freq` 对应一个 `key` 的列表。  
3.4、希望 `freq` 对应的 `key` 的列表是存在时序的，便于快速查找并删除最旧的 `key`。  
3.5、希望能够快速删除 `key` 列表中的任何一个 `key`，因为如果频次为 `freq` 的某个 `key` 被访问，那么它的频次就会变成 `freq+1`，就应该从 `freq` 对应的 `key` 列表中删除，加到 `freq+1` 对应的 `key` 的列表中。  

```java
HashMap<Integer, LinkedHashSet<Integer>> freqToKeys;
```
`LinkedHashSet` 顾名思义，是链表和哈希集合的结合体。链表不能快速访问链表节点，但是插入元素具有时序；哈希集合中的元素无序，但是可以对元素进行快速的访问和删除。  

### 基本数据结构  
```java
class LFUCache {
    // key 到 val 的映射，我们后文称为 KV 表
    HashMap<Integer, Integer> keyToVal;
    // key 到 freq 的映射，我们后文称为 KF 表
    HashMap<Integer, Integer> keyToFreq;
    // freq 到 key 列表的映射，我们后文称为 FK 表
    HashMap<Integer, LinkedHashSet<Integer>> freqToKeys;
    // 记录最小的频次
    int minFreq;
    // 记录 LFU 缓存的最大容量
    int cap;

    public LFUCache(int capacity) {
        keyToVal = new HashMap<>();
        keyToFreq = new HashMap<>();
        freqToKeys = new HashMap<>();
        this.cap = capacity;
        this.minFreq = 0;
    }

    public int get(int key) {}

    public void put(int key, int val) {}

}
```