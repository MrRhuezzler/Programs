class DisjointSet {

    int *verties;
    int size;

public:

    DisjointSet(int n) {
        size = n;
        verties = new int[n];
        for(int i = 0; i < size; i++) {
            verties[i] = -1;
        }
    }

    int find(int x) {
        if(verties[x] != -1) {
            return find(verties[x]);
        } else {
            return x;
        }
    }

    void merge(int u, int v) {
        int uParent = find(u);
        int vParent = find(v);
        if(uParent == vParent) {
            return;
        }
        verties[uParent] = vParent;
    }

};