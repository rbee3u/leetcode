struct LRUNode {
    int             key;
    int             value;
    LRUNode        *prev;
    LRUNode        *next;
};


class LRUList {
public:
    LRUList() : head(NULL) {
    }

    void remove(LRUNode *p) {
        if (head->next == head) {
            head = NULL; return;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;

        if (head == p) {
            head = p->next;
        }
    }

    void insert(LRUNode *p) {
        if (head == NULL) {
            p->prev = p->next = p;
            head = p; return;
        }

        p->prev = head->prev;
        p->prev->next = p;
        p->next = head;
        head->prev = p;

        head = p;
    }

    LRUNode *last() {
        if (head == NULL) {
            return NULL;
        }

        return head->prev;
    }

    int getKey(LRUNode *p) {
        return p->key;
    }

    int getValue(LRUNode *p) {
        return p->value;
    }

    void setKeyValue(LRUNode *p, int key, int value) {
        p->key = key; p->value = value;
    }

private:
    LRUNode        *head;
};


class LRUPool {
public:
    LRUPool(int capacity) {
        if (capacity <= 0) {
            head = pool = NULL; return;
        }

        head = pool = new LRUNode[capacity];
        for (int i=1; i < capacity; ++i) {
            pool[i-1].next = &pool[i];
        }
        pool[capacity-1].next = NULL;
    }

    ~LRUPool() {
        if (pool != NULL) {
            delete[] pool;
        }
    }

    LRUNode *malloc() {
        LRUNode *p = head;
        if (head != NULL) {
            head = head->next;
        }
        return p;
    }
    
    bool noCapacity() {
        return pool == NULL;
    }

private:
    LRUNode        *pool;
    LRUNode        *head;
};


class LRUCache {
public:
    LRUCache(int capacity)
        : pool(capacity) {
    }

    int get(int key) {
        LRUNode *p;
        auto it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        } else {
            p = it->second;
            list.remove(p);
            list.insert(p);
            return list.getValue(p);
        }
    }

    void set(int key, int value) {
        if (pool.noCapacity()) {
            return;
        }
        LRUNode *p;
        auto it = mp.find(key);
        if (it == mp.end()) {
            if (!(p=pool.malloc())) {
                p = list.last();
                mp.erase(list.getKey(p));
                list.remove(p);
            }
            mp[key] = p;
        } else {
            list.remove(p=it->second);
        }
        list.insert(p);
        list.setKeyValue(p, key, value);
    }

private:
    unordered_map<int, LRUNode*> mp;
    LRUList                    list;
    LRUPool                    pool;
};


