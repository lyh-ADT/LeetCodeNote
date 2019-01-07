#include <iostream>
using namespace std;

// 链表实现
template <class T>
class BSTree_Linked {
   public:
    T val;
    BSTree_Linked* left;
    BSTree_Linked* right;
    BSTree_Linked(T v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
    T getMax(BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = right;
        }
        while (t) {
            if (t->right == nullptr) {
                return t->val;
            } else {
                t = t->right;
            }
        }
        return nullptr;
    }
    T getMin(BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = left;
        }
        while (t) {
            if (t->left == nullptr) {
                return t->val;
            } else {
                t = t->left;
            }
        }
        return nullptr;
    }
    void insert(T v) {
        BSTree_Linked* t = this;
        while (t) {
            if (t->val > v) {
                if (t->left) {
                    t = t->left;
                } else {
                    t->left = new BSTree_Linked(v);
                    return;
                }
            } else {
                if (t->right) {
                    t = t->right;
                } else {
                    t->right = new BSTree_Linked(v);
                    return;
                }
            }
        }
    }
    BSTree_Linked* find(T v, BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = this;
        }
        while (t) {
            if (t->val == v) {
                return t;
            }
            if (t->val > v) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return nullptr;
    }
    void del(T v, BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = this;
        }
        while (t) {
            if (t->val > v) {
                if (t->left) {
                    if (t->left->val == v) {
                        BSTree_Linked* tdel = t->left;
                        if (tdel->right) {
                            t->left = tdel->right;
                            t = tdel->right;
                            while (t->left) {
                                t = t->left;
                            }
                            t->left = tdel->left;
                        } else {
                            t->left = tdel->left;
                        }
                        delete[] tdel;
                        return;
                    } else {
                        t = t->left;
                    }
                } else {
                    return;
                }
            } else {
                if (t->right) {
                    if (t->right->val == v) {
                        BSTree_Linked* tdel = t->right;
                        if (tdel->right) {
                            t->right = tdel->right;
                            t = tdel->right;
                            while (t->left) {
                                t = t->left;
                            }
                            t->left = tdel->left;
                        } else {
                            t->right = tdel->left;
                        }
                        delete[] tdel;
                        return;
                    } else {
                        t = t->right;
                    }
                } else {
                    return;
                }
            }
        }
    }
    void printPreOrder(BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = this;
        }
        cout << t->val << endl;
        if (t->left) printPreOrder(t->left);
        if (t->right) printPreOrder(t->right);
    }
    void printMidOrder(BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = this;
        }
        if (t->left) printMidOrder(t->left);
        cout << t->val << endl;
        if (t->right) printMidOrder(t->right);
    }
    void printBackOrder(BSTree_Linked* t = nullptr) {
        if (t == nullptr) {
            t = this;
        }
        if (t->left) printBackOrder(t->left);
        if (t->right) printBackOrder(t->right);
        cout << t->val << endl;
    }
};

// 数组实现
template <class T>
class BSTree_Array {
   public:
    T** S;
    size_t maxLength;
    BSTree_Array(size_t maxLength) {
        this->maxLength = maxLength;
        if (maxLength <= 0) {
            return;
        }
        S = new T*[maxLength + 1];
        for (int i = 0; i <= maxLength; ++i) {
            S[i] = nullptr;
        }
    }
    void insert(T v) {
        int i = 1;
        while (i <= maxLength) {
            if (S[i] == nullptr) {
                S[i] = new T(v);
                return;
            }
            if (S[i][0] > v) {
                i = i << 1;
            } else {
                i = i << 1 + 1;
            }
        }
    }
    int find(T v) {
        int i = 0;
        while (i <= maxLength && S[i] != nullptr) {
            if (S[i][0] == v) {
                return i;
            }
            if (S[i] > v) {
                i = i << 1;
            } else {
                i = i << 1 + 1;
            }
        }
        return -1;
    }
};

int main() {
    BSTree_Array<int> h(10);
    h.insert(3);
    h.insert(1);
    h.insert(5);
    cout << h.S[2][0];
    return 0;
}