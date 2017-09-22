package main

type Trie struct {
	Exist    bool
	Children [26]*Trie
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	node := this
	for i := 0; i < len(word); i++ {
		c := word[i] - 'a'
		if node.Children[c] == nil {
			node.Children[c] = &Trie{}
		}
		node = node.Children[c]
	}
	node.Exist = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	node := this
	for i := 0; i < len(word); i++ {
		c := word[i] - 'a'
		if node.Children[c] == nil {
			return false
		}
		node = node.Children[c]
	}
	return node.Exist
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	node := this
	for i := 0; i < len(prefix); i++ {
		c := prefix[i] - 'a'
		if node.Children[c] == nil {
			return false
		}
		node = node.Children[c]
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
