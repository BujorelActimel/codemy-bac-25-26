#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("bifrunze.in");
ofstream fout("bifrunze.out");

struct Node {
    int value; // numarul din interiorul nodului
    int left; // indexul fiului din stanga
    int right; // indexul fiului din dreapta

    Node() {
        value = 0, left = 0, right = 0;
    }

    Node(int val, int l, int r) {
        value = val, left = l, right = r;
    }

    void print() {
        fout << value << ' ';
    }
};

struct Tree {
    vector<Node> nodes;

    int findRootIndex() {
        int numberOfNodes = nodes.size();
        int markedNodes[numberOfNodes];
        for (int i = 0; i < numberOfNodes; i++) {
            markedNodes[i] = 0;
        }
        
        for (Node node: nodes) {
            if (node.left) {
                markedNodes[node.left-1] = 1;
            }
            if (node.right) {
                markedNodes[node.right-1] = 1;
            }
        }

        for (int i = 0; i < numberOfNodes; i++) {
            if (!markedNodes[i]) {
                return i;
            }
        }

        return -1;
    }

    // radacina, subarbore stang, subarobore drept
    void print_PreOrder(Node r) {
        if (r.left == 0 && r.right == 0) {
            r.print();
            return;
        }

        // radacina
        r.print();

        // subarobre stang
        if (r.left) {
            print_PreOrder(nodes[r.left-1]);
        }

        // subarbore drept
        if (r.right) {
            print_PreOrder(nodes[r.right-1]);
        }
    }

    // subarbore stand, radacina, subarbore drept
    void print_InOrder(Node r) {
        if (r.left == 0 && r.right == 0) {
            r.print();
            return;
        }

        // subarobre stang
        if (r.left) {
            print_InOrder(nodes[r.left-1]);
        }

        // radacina
        r.print();

        // subarbore drept
        if (r.right) {
            print_InOrder(nodes[r.right-1]);
        }
    }

    void print_Leaves() {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i].left == 0 && nodes[i].right == 0) {
                fout << i+1 << ' ';
            }
        }
    }
};

int main() {
    int n;
    fin >> n;

    Tree tree;

    for (int i = 0; i < n; i++) {
        int val, st, dr;
        fin >> val >> st >> dr;
        Node node = Node(val, st, dr);
        tree.nodes.push_back(node);
    }
    
    tree.print_Leaves();

    return 0;
}
