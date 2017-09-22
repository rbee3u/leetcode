class CombinationIterator {
private:
    string characters;
    int t;
    vector<int> combination;

public:
    CombinationIterator(const string &characters, int t) : characters(characters), t(t) {
        combination.resize(t + 1, characters.size());
        for (int i = 0; i < t; i++) combination[i] = i;
    }

    int add(int i) { return (i + 1) % (1 + t); }

    int sub(int i) { return (i + t) % (1 + t); }

    string next() {
        string result(t, 0);
        for (int i = 0; i < t; i++) {
            result[i] = characters[combination[i]];
        }
        int j = t, i = sub(j);
        while (combination[i] + 1 == combination[j]) {
            i = sub(j = i);
        }
        combination[i] = combination[i] + 1;
        while (j != t) {
            combination[j] = combination[i] + 1;
            j = add(i = j);
        }
        return result;
    }

    bool hasNext() {
        return combination[t] == characters.size();
    }
};
